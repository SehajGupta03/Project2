/**
 * @file RotationSource.h
 * @author sehaj
 *
 * base class for rotational sources
 *
 */
 
#ifndef ROTATIONSOURCE_H
#define ROTATIONSOURCE_H
#include "RotationSink.h"

/**
 * base class for rotational sources
 */
class RotationSource {
private:
 /// collection of all the connected sinks
 std::vector<std::shared_ptr<RotationSink>> mSinks;


public:
 void NotifySinks(double angle);

 void AddSink(std::shared_ptr<RotationSink> sink);

 RotationSource() = default;

 /// Copy constructor (disabled)
 RotationSource(const RotationSource &) = delete;

 /// Assignment operator (disabled)
 void operator=(const RotationSource &) = delete;

};



#endif //ROTATIONSOURCE_H
