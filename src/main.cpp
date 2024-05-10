#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>
#include <time.h>


using std::cout;


int main() 
{
	srand(time(0));

	Die die1, die2;
    Shooter shooter;
	Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

	ComeOutPhase come_out_phase;

	while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) 
	{
        cout << "Rolled: " << rolled_value << " roll again" << "\n";
        roll = shooter.throw_dice(die1, die2);
    }

    cout << rolled_value<<"  Start of point phase" << "\n";
    cout << "Roll until "<< rolled_value<< "or 7 is rolled" << "\n";

    int point = rolled_value;
	roll = shooter.throw_dice(die1, die2);

    PointPhase point_phase(point);

	while (point_phase.get_outcome(roll) != RollOutcome::seven_out && point_phase.get_outcome(roll) != RollOutcome::nopoint) 
	{
        cout << "Rolled: " << rolled_value << " roll again" << "\n";
        roll = shooter.throw_dice(die1, die2);
    }

    cout << "Rolled " <<rolled_value<<"  end of point phase."<<"\n";
	shooter.display_rolled_values();

	shooter.~Shooter();


	return 0;
}