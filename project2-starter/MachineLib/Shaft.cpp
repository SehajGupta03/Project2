/**
 * @file Shaft.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Shaft.h"
#include "RotationSource.h"

/// The color to draw the shaft
const wxColour ShaftColor = wxColour(220, 220, 220);

/// The color to draw the lines on the shaft
/// First parameter to Cylinder::SetLines
const wxColour ShaftLineColor = wxColour(100, 100, 100);

/// The width to draw the lines on the shaft
/// Second parameter to Cylinder::SetLines
const int ShaftLinesWidth = 1;

/// The number of lines to draw on the shaft
/// Third parameter to Cylinder::SetLines
const int ShaftNumLines = 4;

/**
 * Constructor
 */
Shaft::Shaft() : RotationSink()
{
 mCylinder.SetColour(ShaftColor);
 mCylinder.SetLines(ShaftLineColor, ShaftLinesWidth, ShaftNumLines);
}

/**
 * Function to draw this shaft
 * @param graphics graphics context to draw this shaft on
 */
void Shaft::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 RotationSink::Draw(graphics);
 graphics->PushState();
 mCylinder.Draw(graphics, GetX(), GetY(), GetRotation());
 graphics->PopState();
}

/**
 * function to set the size of the shaft
 * @param diameter new diameter
 * @param length new length
 */
void Shaft::SetSize(double diameter, double length)
{
 mCylinder.SetSize(diameter, length);
}


/**
 * function to set the offset
 * @param x new offset
 */
void Shaft::SetOffset(double x)
{
 mCylinder.SetOffset(x);
}