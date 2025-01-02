/**
 * @file Pulley.h
 * @author sehaj
 *
 * Pulley class
 *
 */
 
#ifndef PULLEY_H
#define PULLEY_H
#include "RotationSink.h"


class RotationSource;

/**
 * Pulley class
 */
class Pulley : public RotationSink {
private:
 /// radius of the Pulley
 double mRadius = 0;

 /// left hub of the pulley
 cse335::Cylinder mLeftHub;

 /// right hub of the pulley
 cse335::Cylinder mRightHub;

 /// width of the pulley
 double mWidth = 0;

 /// another pulley this pulley is connected to
 std::shared_ptr<Pulley> mBeltConnectedPulley = nullptr;

public:
 Pulley(double diameter, double width);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 void BeltTo(const std::shared_ptr<Pulley>& pulley);

 //void SetBelConnection(const std::shared_ptr<Pulley>& pulley) {mBeltConnectedPulley = pulley;};

 /**
  * function to get the radius of this pulley
  * @return radius of this pulley
  */
 double GetRadius() {return mRadius;};

 void UpdateRotation(double angle) override;

 void Advance(double time) override;

};



#endif //PULLEY_H
