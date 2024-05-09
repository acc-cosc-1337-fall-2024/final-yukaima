#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "die.h"
#include <time.h>
#include "roll.h"



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