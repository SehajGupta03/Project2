/**
 * @file TimeDlg.h
 * @author sehaj
 *
 * Dialog class to set the start time of the machines
 */
 
#ifndef TIMEDLG_H
#define TIMEDLG_H
#include "MachineDrawable.h"

class MachineDrawable;

/**
 * Dialog class to set the start time of
 * the machines
 */
class TimeDlg final : public wxDialog {
private:
 void OnOK(wxCommandEvent& event);

 /// pointer to the machine drawable object
 std::shared_ptr<MachineDrawable> mDrawable;

 /// Frame of the machine
 int mFrame;

public:
 TimeDlg(wxWindow* parent, std::shared_ptr<MachineDrawable> machine);

};



#endif //TIMEDLG_H
