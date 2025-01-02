/**
 * @file Crank.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Crank.h"
#include "RotationSource.h"


/// The width of the crank on the screen in pixels
const int CrankWidth = 10;

/// The depth of the crank away from the screen in pixels
const int CrankDepth = 20;

/// The length of the crank in pixels
const int CrankLength = 50;

/// The diameter to draw the crank handle
const int HandleDiameter = 7;

/// How long the handle is in pixels
const int HandleLength = 40;

/// How much to the left of the crank X the handle starts in pixels
const int HandleStartX = -10;

/// Crank color
const wxColour CrankColor = wxColour(220, 220, 220);

/// Line color for the rod
const wxColour CrankHandleLineColor = wxColour(100, 100, 100);


/**
 * Constructor
 * @param filename image
 */
Crank::Crank(std::wstring filename) : Component()
{
    mHandle.SetSize(HandleDiameter, HandleLength);
    mHandle.SetColour(CrankColor);
    mHandle.SetLines(CrankHandleLineColor, 1, 4);
    mSource = std::make_shared<RotationSource>();
}


/**
 * Function to draw the crank
 * @param graphics Graphics context to draw the crank on
 */
void Crank::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    double handleY = GetY() + cos(mAngle) * CrankLength;
    // drawing the handle
    graphics->PushState();
    mHandle.Draw(graphics, GetX() + HandleStartX, handleY, mAngle);
    graphics->PopState();

    // drawing rectangle
    graphics->PushState();

    // Create the path for the main vertical rectangle
    graphics->Translate(GetX(), GetY());

    // Set the color to light gray/white as shown in image
    graphics->SetBrush(wxBrush(CrankColor));
    graphics->SetPen(wxPen(*wxBLACK, 1));
    // Calculate the current length based on angle
    double currentLength = (CrankLength + HandleDiameter) * cos(mAngle);

    if (currentLength > 0 and currentLength < 15)
    {
        currentLength = 15;
    }
    if(currentLength < 0 and currentLength > -25)
    {
        currentLength = -25;
    }
    // Draw main vertical rectangle
    graphics->DrawRectangle(-CrankWidth/2, 0, CrankWidth, currentLength );

    graphics->PopState();

}

/**
 * Function to advance crank with time
 * @param time Time elapsed since last update
 */
void Crank::Advance(double time)
{
    Component::Advance(time);

    mAngle += time * mSpeed;

    if(mSource != nullptr)
    {
        mSource->NotifySinks(mAngle);
    }
}
