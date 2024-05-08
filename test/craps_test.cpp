#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "die.h"
#include <time.h>



TEST_CASE("Test roll() function return a random number from 1 to 6")
{
	
	Die die;
    
	for (int i = 0; i < 10; i++)
	{
		int rollresult = die.roll();
		bool result = rollresult >= 1 && rollresult <= 6;
		REQUIRE(result == true) ;
	}
	
}