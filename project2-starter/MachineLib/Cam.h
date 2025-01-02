/**
 * @file Cam.h
 * @author sehaj
 *
 * Class that represents Cam
 */
 
#ifndef CAM_H
#define CAM_H
#include "RotationSink.h"

/**
 * Class that represents Cam
 */
class Cam : public RotationSink {
private:
 /// The Key object of type Polygon
 cse335::Polygon mKey;

 /// Location of the hole in the cam
 double mY = 8;

 /// Vector of objects that can be triggered by Cam
 std::vector<std::shared_ptr<ITrigger>> mObjects;

 /// the Y location of the Key
 int mKeyY;

public:
 Cam(std::wstring imagesDir);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 void Advance(double time) override;

 //void SetHoleAngle(double angle);

 void AddKeyDrop(std::shared_ptr<ITrigger> obj);

};



#endif //CAM_H
