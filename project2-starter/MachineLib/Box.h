/**
 * @file Box.h
 * @author sehaj
 *
 * Class that represents the box which contains all the other components
 */
 
#ifndef BOX_H
#define BOX_H
#include <string>
#include "ITrigger.h"

/**
 * class that represents the box which contains all the other components
 */
class Box : public ITrigger {
private:
 /// Box of type Polygon
 cse335::Polygon mBox;

 /// Lid of the Box
 cse335::Polygon mLid;

 /// Front of the Box
 cse335::Polygon mForeground;

 /// Lid angle
 double mLidAngle = 0;

public:
 Box(std::wstring imagesDir, int boxSize, int lidSize);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 void DrawForeground(std::shared_ptr<wxGraphicsContext> graphics) override;

 /**
  * function to update the angle of the lid
  * @param angle new angle
  */
 void SetLidAngle(double angle) { mLidAngle = angle; };

 void Trigger() override;

};



#endif //BOX_H
