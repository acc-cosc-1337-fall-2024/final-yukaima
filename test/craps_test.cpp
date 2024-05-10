#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "die.h"
#include <time.h>
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"



TEST_CASE("Test  die return a random number from 1 to 6")
{
	
	Die die;
    
	for (int i = 0; i < 10; i++)
	{
		int rollresult = die.roll();
		bool result = rollresult >= 1 && rollresult <= 6;
		REQUIRE(result == true) ;
	}
	
}

TEST_CASE("Test roll return a random number from 2 to 12")
{
	Die die1,die2;
	Roll roll(die1,die2);
    
	for (int i = 0; i < 10; i++)
	{
		roll.roll_dice();
		int rollvalue = roll.roll_value();
		bool result = rollvalue >= 2 && rollvalue <= 12;
		REQUIRE(result == true) ;
	}
	
}

TEST_CASE("Test shooter return a Roll and it's from 2 to 12")
{
	Die die1, die2;
    Shooter shooter;
    
	for (int i = 0; i < 10; ++i)
    {
        Roll* roll = shooter.throw_dice(die1,die2);
        int value = roll->roll_value();
		bool result = value >=2 && value <=12;
        REQUIRE(result == true);
    }
	
}

TEST_CASE("Test ComeOutPhase returns values RollOutcome::natural") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    ComeOutPhase comeoutphase;
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() != 7 && roll.roll_value() != 11);

	REQUIRE(comeoutphase.get_outcome(&roll) == RollOutcome::natural);	
}


TEST_CASE("Test ComeOutPhase return RollOutcome::craps") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    ComeOutPhase comeoutphase;
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() != 2 && roll.roll_value() != 3 && roll.roll_value() != 12);

	REQUIRE(comeoutphase.get_outcome(&roll) == RollOutcome::craps);	
}

TEST_CASE("Test ComeOutPhase return RollOutcome::point ") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    ComeOutPhase comeoutphase;
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() == 2 || roll.roll_value() == 3 || roll.roll_value() == 12 ||  roll.roll_value() == 7 || roll.roll_value() == 11);

	REQUIRE(comeoutphase.get_outcome(&roll) == RollOutcome::point);	
}

TEST_CASE("Test PointPhase return RollOutcome::point") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    PointPhase pointphase(6);
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() != 6);

	REQUIRE(pointphase.get_outcome(&roll) == RollOutcome::point);	
}

TEST_CASE("Test PointPhase return RollOutcome::seven_out") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    PointPhase pointphase(6);
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() != 7);

	REQUIRE(pointphase.get_outcome(&roll) == RollOutcome::seven_out);	
}

TEST_CASE("Test PointPhase return RollOutcome::nopoint") 
{
    Die die1, die2;
    Roll roll(die1, die2);
    PointPhase pointphase(6);
	do
	{
		roll.roll_dice();
		roll.roll_value();
	} while (roll.roll_value() == 7 || roll.roll_value() == 6);

	REQUIRE(pointphase.get_outcome(&roll) == RollOutcome::nopoint);	
}