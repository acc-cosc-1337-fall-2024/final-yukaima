//
#include "phase.h"

#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H


class Roll; 

class ComeOutPhase : public Phase 
{
public:
    RollOutcome get_outcome(Roll* roll) ;
};

#endif 