/**
 * @file Pulley.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Pulley.h"
#include "RotationSource.h"


/// How wide the hub is on each side of the pulley
const double PulleyHubWidth = 3;

/// How deep the belt is into the pulley
const double PulleyBeltDepth = 3;

/// The color to use for pulleys
const wxColour PulleyColor = wxColour(205, 250, 5);

/// The line color to use for the hub
/// First parameter to Cylinder::SetLines
const wxColour PulleyHubLineColor = wxColour(139, 168, 7);

/// The width to draw the lines on the hub
/// Second parameter to Cylinder::SetLines
const int PulleyHubLineWidth = 4;

/// The number of lines to draw on a pulley is the int(diameter / 6.0)
/// Third parameter to Cylinder::SetLines
const double PulleyHubLineCountDiviser = 6.0;

/**
 * Constructor
 * @param diameter diameter of this pulley
 * @param width width of this pulley
 */
Pulley::Pulley(double diameter, double width) : RotationSink()
{
 mRadius = diameter / 2;
 mWidth = width;
 mLeftHub.SetColour(PulleyColor);
 mRightHub.SetColour(PulleyColor);
 mLeftHub.SetSize(diameter, 2);
 mRightHub.SetSize(diameter, 2);
 int lines = int(diameter / PulleyHubLineCountDiviser);
 mLeftHub.SetLines(PulleyHubLineColor, PulleyHubLineWidth, lines);
 mRightHub.SetLines(PulleyHubLineColor, PulleyHubLineWidth, lines);
}


/**
 * Function to draw this pulley
 * @param graphics graphics context to draw pulley on
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 RotationSink::Draw(graphics);
 graphics->PushState();

 // Draw the hubs
 mLeftHub.Draw(graphics, GetX(), GetY(), GetRotation());
 mRightHub.Draw(graphics, GetX() + mWidth - PulleyHubWidth, GetY(), GetRotation());

 if(mBeltConnectedPulley)
 {
  // Create path for the belt
  wxGraphicsPath path = graphics->CreatePath();

  // Calculate belt dimensions
  double startX = GetX() + 3;
  double startY = GetY() - PulleyBeltDepth - mRadius + 2.3;
  double endY = mBeltConnectedPulley->GetY() + PulleyBeltDepth + mBeltConnectedPulley->GetRadius() - 2.3;
  if(GetY() > mBeltConnectedPulley->GetY())
  {
    startY = GetY() + PulleyBeltDepth + mRadius - 2.3;
    endY = mBeltConnectedPulley->GetY() - PulleyBeltDepth - mBeltConnectedPulley->GetRadius() + 2.3;
  }

  double beltWidth = mWidth - 2*PulleyHubWidth;

  // Draw the vertical belt connecting the pulleys
  path.AddRectangle(startX, std::min(startY, endY),
                   beltWidth, std::abs(endY - startY));

  // Set the belt appearance
  graphics->SetPen(*wxBLACK_PEN);
  graphics->SetBrush(*wxBLACK_BRUSH); // Grey color for the belt

  // Draw the belt
  graphics->DrawPath(path);
 }

 graphics->PopState();
}

/**
 * function to set another pulley this pulley is connected to
 * @param pulley another pulley this pulley is connected to
 */
void Pulley::BeltTo(const std::shared_ptr<Pulley>& pulley)
{
 mBeltConnectedPulley = pulley;
}

/**
 * function to update the angle of the connected pulley
 * @param angle new angle
 */
void Pulley::UpdateRotation(double angle)
{
 RotationSink::UpdateRotation(angle);

 if(mBeltConnectedPulley != nullptr)
 {
  double rotation = (mRadius/mBeltConnectedPulley->GetRadius()) * angle;
  if(mRadius > mBeltConnectedPulley->GetRadius())
  {
   rotation = (mBeltConnectedPulley->GetRadius()/mRadius) * angle;
  }
  mBeltConnectedPulley->UpdateRotation(rotation);
 }
}

/**
 * function to advance connected sinks with time
 * @param time time elapsed since last update
 */
void Pulley::Advance(double time)
{
 RotationSink::Advance(time);
 auto source = GetSource();
 auto angle = GetRotation();
 angle += time * angle;
 if(source != nullptr)
 {
  source->NotifySinks(angle);
 }
}
