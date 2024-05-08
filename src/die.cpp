//
#include "die.h"


int Die::roll()
{
    
    int randomvalue = rand() % sides + 1;

    return randomvalue;
}
