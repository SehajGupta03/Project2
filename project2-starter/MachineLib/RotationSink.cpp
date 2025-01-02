/**
 * @file RotationSink.cpp
 * @author sehaj
 */

#include "pch.h"
#include "RotationSink.h"
#include "RotationSource.h"

/** Constructor */
RotationSink::RotationSink() : Component()
{
 mSource = new RotationSource();
}

/**
 * function to set the source of rotation for this sink
 * @param source source of rotation of this sink
 */
void RotationSink::SetSource(RotationSource* source)
{
 delete mSource;
 mSource = source;
}
