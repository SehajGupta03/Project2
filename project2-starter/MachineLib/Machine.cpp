/**
 * @file Machine.cpp
 * @author sehaj
 */

#include "pch.h"
#include "Machine.h"

/** Constructor */
Machine::Machine()
{
}

/**
 * Function to add a component t0 the machine
 * @param component Component to add to the collection
 */
void Machine::AddComponent(std::shared_ptr<Component> component)
{
 mComponents.push_back(component);
 component->SetMachine(this);
}


/**
 * Function to draw all the components of the machine
 * @param graphics graphics context to draw the machine on
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 for(auto component : mComponents)
 {
  component->Draw(graphics);
 }
 for(auto component : mComponents)
 {
  component->DrawForeground(graphics);
 }
}

/**
 * Function to set the time of machine and all associated components
 * @param time New time
 */
void Machine::SetTime(double time)
{
 mTime = time;
 for(auto component : mComponents)
 {
  component->SetTime(time);
 }
}

/**
 * Function to advance all the components of the machine
 * @param time time elapsed since last update
 */
void Machine::Advance(double time)
{
 for(auto component : mComponents)
 {
  component->Advance(time);
 }
}
