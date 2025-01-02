/**
 * @file Box.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Box.h"

/// The background image to use
const std::wstring BoxBackgroundImage = L"/box-background.png";

/// The foreground image to use
const std::wstring BoxForegroundImage = L"/box-foreground.png";

/// The lid image to use
const std::wstring BoxLidImage = L"/box-lid.png";

/// The horizontal scale for the lid when the angle is zero
const double LidZeroAngleScale = 0.02;

/// How long it takes to up the lid in seconds
const double LidOpeningTime = 0.25;


/**
 * Constructor
 * @param imagesDir the directory containing the images
 * @param boxSize the size of the box
 * @param lidSize sie of the lid
 */
Box::Box(std::wstring imagesDir, int boxSize, int lidSize)
{
 mBox.Rectangle(-boxSize / 2, 0, boxSize, boxSize);
 mBox.SetImage(imagesDir + BoxBackgroundImage);

 mLid.Rectangle(-lidSize / 2, 0, lidSize, lidSize);
 mLid.SetImage(imagesDir + BoxLidImage);

 mForeground.Rectangle(-boxSize / 2, 0, boxSize, boxSize);
 mForeground.SetImage(imagesDir + BoxForegroundImage);
}


/**
 * Function to draw the box
 * @param graphics graphics context to draw the box on
 */
void Box::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 mBox.DrawPolygon(graphics, GetX(), GetY());

 double s = std::sin(mLidAngle);

 auto lidAngle = LidZeroAngleScale + s * (1.0 - LidZeroAngleScale);

 graphics->PushState();
 graphics->Translate(GetX(), GetY() - mLid.GetImageHeight()/2);
 graphics->Scale(1, lidAngle);

 mLid.DrawPolygon(graphics, 0, 0);

 graphics->PopState();
}

/**
 * Function to draw the foreground of the box
 * @param graphics graphics context to draw the foreground on
 */
void Box::DrawForeground(std::shared_ptr<wxGraphicsContext> graphics)
{
 graphics->PushState();
 mForeground.DrawPolygon(graphics, GetX(), GetY());
 graphics->PopState();
}


/**
 * Function to trigger the box to open by changing the lidangle
 */
void Box::Trigger()
{
 mLidAngle = M_PI / 2;
}
