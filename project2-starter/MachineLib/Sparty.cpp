/**
 * @file Sparty.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Sparty.h"

/// The spring pen size to use in pixels
const double SpringWireSize = 2;

/// Minimum spacing between spring wire
const double SpringWireMinSpacing = 1;

/// Color to draw the spring
const wxColour SpringColor = wxColour(220, 220, 220);

/// Sparty popup time in seconds
const double SpartyPopupTime = 0.25;

// const double compressedLength = 30;

/**
 * Constructor
 * @param filename image file
 * @param size size of sparty
 * @param springLen len of the spring
 * @param springWidth width of the spring
 * @param numLinks number of links in sparty
 */
Sparty::Sparty(std::wstring filename, double size, double springLen, double springWidth, int numLinks)
{
 mSparty.Rectangle(-size/2, mCompressedLength / 2, size, size);
 mSparty.SetImage(filename);
 mSize = size;
 mNumLinks = numLinks;
 mSpringWidth = springWidth;
 mSpringLength = springLen;
}

/**
 * function to draw sparty on the given graphics context
 * @param graphics graphics context
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 graphics->PushState();
 graphics->SetPen(SpringColor);
 DrawSpring(graphics, GetX(), GetY(), mCompressedLength, mSpringWidth, mNumLinks );
 graphics->PopState();
 graphics->PushState();
 mSparty.DrawPolygon(graphics, GetX(), GetY() - mCompressedLength + 2);
 graphics->PopState();
}


/**
 * Draw a spring.
 * @param graphics Graphics context to render to
 * @param x X location of the bottom center of the spring in pixels
 * @param y Y location of the bottom center of the spring in pixels
 * @param length Length to draw the spring (bottom to top) in pixels
 * @param width Spring width in pixels
 * @param numLinks Number of links (loops) in the spring
 */
void Sparty::DrawSpring(std::shared_ptr<wxGraphicsContext> graphics,
                        int x, int y, double length, double width, int numLinks)
{
 graphics->PushState();
 auto path = graphics->CreatePath();

 // We keep track of three locations, the bottom of which
 // is y1. First half-loop will be y1 to y3, second half-loop
 // will be y3 to y2.
 double y1 = y;
 double linkLength = length / numLinks;

 // Left and right X values
 double xR = x + width / 2;
 double xL = x - width / 2;

 path.MoveToPoint(x, y1);

 for(int i=0; i<numLinks; i++)
 {
  auto y2 = y1 - linkLength;
  auto y3 = y2 - linkLength / 2;

  path.AddCurveToPoint(xR, y1, xR, y3, x, y3);
  path.AddCurveToPoint(xL, y3, xL, y2, x, y2);

  y1 = y2;
 }

 graphics->StrokePath(path);
 graphics->PopState();
}

/** Function to trigger sparty */
void Sparty::Trigger()
{
 mSpring = true;
 mCompressedLength = mSpringLength;
}