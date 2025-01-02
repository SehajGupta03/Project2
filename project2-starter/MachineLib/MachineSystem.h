/**
 * @file MachineSystem.h
 * @author sehaj
 *
 * System to have factories create machines
 *
 */
 
#ifndef MACHINESYSTEM_H
#define MACHINESYSTEM_H
#include "IMachineSystem.h"
#include "Machine.h"

/**
 * System to have factories create machines
 */
class MachineSystem : public IMachineSystem {
private:
 /// Location of the machine
 wxPoint mLocation = wxPoint(0, 0);

 /// number of machine
 int mNumber;

 /// frame rate of the system
 double mFrameRate = 0;

 /// flags of the machine
 int mFlag;

 /// frame of the system
 int mFrame = 0;

 /// machine contained in the system
 std::shared_ptr<Machine> mMachine = nullptr;

 /// Path to the resources directory
 std::wstring mResourcesDir;

 /// time of the system
 double mTime = 0;

public:

 MachineSystem(std::wstring resourcesDir);

 void SetLocation(wxPoint location) override;

 wxPoint GetLocation() override;

 void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

 void SetMachineFrame(int frame) override;

 void ChooseMachine(int machine) override;

 double GetMachineTime() override;

 int GetMachineNumber() override;

 void SetFrameRate(double rate) override;

 void SetFlag(int flag) override;
 void Reset();
};



#endif //MACHINESYSTEM_H
