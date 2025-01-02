/**
 * @file Shaft.h
 * @author sehaj
 *
 * Shaft
 *
 */
 
#ifndef SHAFT_H
#define SHAFT_H
#include "RotationSink.h"


class RotationSource;

/**
 * Shaft
 */
class Shaft : public RotationSink {
private:
 /// body of shaft
 cse335::Cylinder mCylinder;

public:
 Shaft();
 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 void SetSize(double diameter, double length);

 void SetOffset(double x);

};



#endif //SHAFT_H
