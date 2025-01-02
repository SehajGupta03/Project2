/**
 * @file Sparty.h
 * @author sehaj
 *
 * Sparty
 *
 */
 
#ifndef SPARTY_H
#define SPARTY_H
#include "ITrigger.h"

/**
 * Sparty
 */
class Sparty : public ITrigger {
private:
 /// sparty's body
 cse335::Polygon mSparty;

 /// size of sparty
 int mSize;

 /// number of links in the spring
 int mNumLinks;

 /// width of the spring
 double mSpringWidth;

 /// length of the spring
 double mSpringLength;

 /// length of the compressed spring
 double mCompressedLength = 30;

 /// sparty out or not
 bool mSpring;

public:
 Sparty(std::wstring filename, double size, double springLen, double springWidth, int numLinks);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
 void DrawSpring(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, double length, double width, int numLinks);

 void Trigger() override;
};



#endif //SPARTY_H
