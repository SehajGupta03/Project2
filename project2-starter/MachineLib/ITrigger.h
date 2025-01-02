/**
 * @file ITrigger.h
 * @author sehaj
 *
 * Interface for triggerable objects
 */
 
#ifndef ITRIGGER_H
#define ITRIGGER_H
#include "Component.h"

/**
 * Interface for triggerable objects
 */
class ITrigger : public Component
{
 private:

public:
 /** Destructor */
 virtual ~ITrigger() = default;

 /** trigger function */
 virtual void Trigger() = 0;

 /**
  * advance function
  * @param time time elapsed since last update
  */
 void Advance(double time) override {};

};

#endif //ITRIGGER_H
