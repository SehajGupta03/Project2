/**
 * @file Component.h
 * @author sehaj
 *
 * Base component class
 */
 
#ifndef COMPONENT_H
#define COMPONENT_H

class ITrigger;
class Machine;
#include "Cylinder.h"
#include "Polygon.h"


/**
* Base Component Class
*/
class Component {
private:

 /// pointer to the machine this is part of
 Machine *mMachine = nullptr;

 /// position of the component
 wxPoint mPosition = wxPoint(0, 0);

 /// current time of the component
 double mTime = 0;

public:
 /** Destructor */
 virtual ~Component() = default;

 /**
  * function to draw components
  * @param graphics graphics context to draw component on
  */
 virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

 /**
  * function to get x coord of this component
  * @return x coord of this component
  */
 int GetX() const {return mPosition.x;};

 /**
  * function to get Y coord of this component
  * @return y coord of this component
  */
 int GetY() const {return mPosition.y;};

 /**
  * Set the time of the component to the provided time
  * @param time new time
  */
 void SetTime(double time) {mTime = time;};

 /**
  * Function to advance the components with time
  * @param time time since last update
  */
 virtual void Advance(double time) {};

 /**
  * Function to draw the foreground
  * @param graphics graphics context to draw on
  */
 virtual void DrawForeground(std::shared_ptr<wxGraphicsContext> graphics) {};

 /**
  * Function to set the position to the given x, y values
  * @param x x coord
  * @param y y coord
  */
 void SetPosition(int x, int y) {mPosition.x = x;mPosition.y = y;};

 /**
  * Function to set the machine that this component belongs to
  * @param machine machine object this is part of
  */
 void SetMachine(Machine* machine) { mMachine = machine;}

 /**
  * Function to trigger object
  * @param obj triggerable object
  */
 void Trigger(std::shared_ptr<ITrigger> obj);


};



#endif //COMPONENT_H
