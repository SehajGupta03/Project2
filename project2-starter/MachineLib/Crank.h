/**
 * @file Crank.h
 * @author sehaj
 *
 * Class that represents Crank
 */
 
#ifndef CRANK_H
#define CRANK_H
#include "Component.h"


class RotationSource;

/**
 * Class that represents Crank, a component
 */
class Crank : public Component {
private:
 /// Handle of the Crank
 cse335::Cylinder mHandle;

 /// Angle of the Crank
 double mAngle = 0;

 /// Speed of the Crank
 double mSpeed = 0;

 /// Pointer to rotation source
 std::shared_ptr<RotationSource> mSource;

public:
 Crank(std::wstring filename);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 /**
  * Function to update speed to new value
  * @param speed new speed
  */
 void SetSpeed(double speed) { mSpeed = speed; };

 void Advance(double time) override;

 /**
  * Function to get the rotational source
  * @return associated rotation source
  */
 std::shared_ptr<RotationSource> GetSource() { return mSource; };


};



#endif //CRANK_H
