/**
 * @file Cam.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Cam.h"

#include "RotationSource.h"

/// Width of the cam on the screen in pixels
const double CamWidth = 17;

/// Cam diameter
const double CamDiameter = 60;

/// How big is the hole in the cam?
const double HoleSize = 8;

/// The key image
const std::wstring KeyImage = L"/key.png";

/// The key image size
const int KeyImageSize = 20;

/// The amount the key drops into the hole
const int KeyDrop = 10;


/**
 * Constructor
 * @param imagesDir images directory containing all the required images
 */
Cam::Cam(std::wstring imagesDir) : RotationSink()
{
 mKey.SetImage(imagesDir + KeyImage);
 mKey.Rectangle(-KeyImageSize/2, 0, KeyImageSize, KeyImageSize);
 mKeyY = 0;
}


/**
 * Function to draw the Cam
 * @param graphics graphics context to draw the Cam on
 */
void Cam::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 // drawing rectangle and hole
 graphics->PushState();
 graphics->SetBrush(*wxWHITE_BRUSH);
 graphics->SetPen(*wxBLACK_PEN);
 graphics->DrawRectangle(GetX(), GetY(), CamWidth, CamDiameter);
 double ellipseHeight = HoleSize * std::abs(std::sin(GetRotation() * 2 * M_PI));
 double ellipseWidth = HoleSize;

 // Position the ellipse within the rectangle
 // mHoleDistance determines how far from the left edge the hole is
 double ellipseX = GetX() + HoleSize/2;
 double ellipseY = GetY() + CamDiameter - mY;
 // Draw the ellipse
 graphics->SetBrush(wxBrush(wxColour(0, 0, 0)));  // Black fill for the hole
 if(ellipseY >= GetY()- HoleSize/2)
 {
  graphics->DrawEllipse(ellipseX, ellipseY, ellipseWidth, ellipseHeight);
 }

 graphics->PopState();

 // Draw the Key
 graphics->PushState();
 mKey.DrawPolygon(graphics, GetX() + CamWidth/2, GetY() + mKeyY, 0);
 graphics->PopState();
}


/**
 * Function to update the location of the key and speed
 * of hole with time
 * @param time time elapsed since last update
 */
void Cam::Advance(double time)
{
 RotationSink::Advance(time);
 auto rotation = GetRotation();
 rotation += GetRotation() * time;
 auto source = GetSource();
 if(source != nullptr)
 {
  source->NotifySinks(rotation);
  mY += rotation + rotation * time;

  if(GetY() + (CamDiameter) - mY <= GetY() - HoleSize/2)
  {
    mKeyY = KeyDrop;
    for(auto obj : mObjects)
    {
     Trigger(obj);
    }
  }
 }
}


/**
 * Function to add the object to the collection of triggerable objects
 * @param obj triggerable object
 */
void Cam::AddKeyDrop(std::shared_ptr<ITrigger> obj)
{
 mObjects.push_back(obj);
}
