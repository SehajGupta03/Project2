/**
 * @file Component.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Component.h"

#include "ITrigger.h"
#include "Machine.h"

void Component::Trigger(std::shared_ptr<ITrigger> obj)
{
 obj->Trigger();
}
