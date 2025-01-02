/**
 * @file MachineDrawable.h
 * @author sehaj
 *
 * Adapter Class
 */
 
#ifndef MACHINEDRAWABLE_H
#define MACHINEDRAWABLE_H
#include "Drawable.h"
#include <../IMachineSystem.h>


class Picture;
class ViewEdit;

/**
 * Machine Drawable class - an adapter class to integrate machine
 * to canadian experience
 */
class MachineDrawable : public Drawable {
private:
 /// the frame where the machine should start
 int mStartFrame = -1;

 /// machine object
 std::shared_ptr<IMachineSystem> mSystem;

public:
 MachineDrawable(std::wstring name);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

 bool HitTest(wxPoint pos) override;

 void SetMachineNumber(int number);

 int GetMachineNumber();

 void SetMachineFrame(int frame);

 void SetFrameRate(int rate);

 double GetMachineTime();

 void Save(wxXmlNode* node);
 void Load(wxXmlNode* node);

 void OpenDialog(wxWindow* parent);

 /**
  * Function to set the frame where the machine should start
  * @param frame new frame
  */
 void SetStartFrame(int frame) { mStartFrame = frame; };

 /**
  * Function to get the frame where this machine will start
  * @return Frame at which this machine should start
  */
 int GetStartFrame() { return mStartFrame; };

};



#endif //MACHINEDRAWABLE_H
