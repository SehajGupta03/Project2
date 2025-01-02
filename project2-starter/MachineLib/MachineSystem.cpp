/**
 * @file MachineSystem.cpp
 * @author sehaj
 */

#include "pch.h"
#include "MachineSystem.h"

#include "MachineCFactory.h"
#include "MachineSFactory.h"

/**
 * Constructor
 * @param resourcesDir resources directory
 */
MachineSystem::MachineSystem(std::wstring resourcesDir)
{
 mResourcesDir = resourcesDir;
 this->ChooseMachine(1);
}

/**
 * function to set the location of the machine
 * @param location new location
 */
void MachineSystem::SetLocation(wxPoint location)
{
 mLocation = location;
}

/**
 * function to get the location of the system
 * @return location of the system
 */
wxPoint MachineSystem::GetLocation()
{
 return mLocation;
}

/**
 * function to draw the machine
 * @param graphics graphics context to draw the machine on
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
 // This will put the machine where it is supposed to be drawn
 graphics->PushState();
 graphics->Translate(mLocation.x, mLocation.y);

 mMachine->Draw(graphics);

 graphics->PopState();
}

/**
 * Function to set machine frame and the time
 * @param frame new frame
 */
void MachineSystem::SetMachineFrame(int frame)
{
 while (frame < mFrame) {
  mFrame--;
  mTime = mFrame / mFrameRate;
  mMachine->Advance(-1.0 / mFrameRate);
  mMachine->SetTime(mTime);
 }

 if (frame < mFrame)
 {
  mFrame = 0;
  Reset();
 }

 while (mFrame < frame) {
  mFrame++;
  mTime = mFrame / mFrameRate;
  mMachine->Advance(1.0 / mFrameRate);
  mMachine->SetTime(mTime);
 }

}

/**
 * function to choose machine
 * @param machine chosen machine number
 */
void MachineSystem::ChooseMachine(int machine)
{
 if(machine == 1)
 {
  auto machineFactory = std::make_shared<MachineCFactory>(mResourcesDir);
  mMachine = machineFactory->Create();
 }
 else
 {
  auto machineFactory = std::make_shared<MachineSFactory>(mResourcesDir);
  mMachine = machineFactory->Create();
 }
 mNumber = machine;
 Reset();
 mTime = 0;
}

/**
 * Function to get the time
 * @return time of the machine
 */
double MachineSystem::GetMachineTime()
{
 return mTime;
}

/**
 * function to get the machine number
 * @return machine number
 */
int MachineSystem::GetMachineNumber()
{
 return mNumber;
}

/**
 * function to set the frame rate
 * @param rate new frame rate
 */
void MachineSystem::SetFrameRate(double rate)
{
 mFrameRate = rate;
}

/**
 * function to set the flag
 * @param flag new flag
 */
void MachineSystem::SetFlag(int flag)
{
 mFlag = flag;
}

/**
 * function to reset the time of the machine to 0
 */
void MachineSystem::Reset()
{
 mMachine->SetTime(0);
}