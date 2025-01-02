/**
 * @file RotationSink.h
 * @author sehaj
 *
 * base class for all the rotational sinks
 *
 */
 
#ifndef ROTATIONSINK_H
#define ROTATIONSINK_H
#include "Component.h"
class RotationSource;

/**
 * base class for all the rotational sinks
 */
class RotationSink : public Component {
private:
 /// rotation of the sink
 double mRotation = 0;

 /// pointer to source of rotation
 RotationSource* mSource = nullptr;

public:
 RotationSink();

 /**
  * function to update the angle of the sink
  * @param angle new angle
  */
 virtual void UpdateRotation(double angle) {  mRotation = angle; };

 /**
  * function to advance the sinks with time
  * @param time time elapsed since last update
  */
 void Advance(double time) override {};

 /**
  * Function to draw rotation sinks
  * @param graphics grahpics context to draw the sink on
  */
 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {};

 /**
  * Function to get the rotation of this sink
  * @return rotation of this sink
  */
 double GetRotation() { return mRotation; };

 void SetSource(RotationSource* source);

 /**
  * function to get the source of rotation
  * @return source of rotation
  */
 RotationSource* GetSource() { return mSource; };

};



#endif //ROTATIONSINK_H
