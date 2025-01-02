/**
 * @file RotationSource.cpp
 * @author sehaj
 */

#include "pch.h"
#include "RotationSource.h"

/**
 * function to tell all the sinks that angle has been changed
 * @param angle updated angle
 */
void RotationSource::NotifySinks(double angle)
{
 for(auto sink : mSinks)
 {
  sink->UpdateRotation(angle);
 }
}

/**
 * function to add sink to this source
 * @param sink sink to add to this source
 */
void RotationSource::AddSink(std::shared_ptr<RotationSink> sink)
{
 mSinks.push_back(sink);
 sink->SetSource(this);
}
