/**
 * @file TimeDlg.cpp
 * @author sehaj
 */

#include "pch.h"
#include <wx/valnum.h>
#include <wx/xrc/xmlres.h>
#include "TimeDlg.h"

/**
 * Constructor
 * @param parent parent window
 * @param machine machine drawable object
 */
TimeDlg::TimeDlg(wxWindow* parent, std::shared_ptr<MachineDrawable> machine) : mDrawable(machine)
{
 wxXmlResource::Get()->LoadDialog(this, parent, L"TimeDlg");

 mFrame = machine->GetStartFrame();

 Bind(wxEVT_BUTTON, &TimeDlg::OnOK, this, wxID_OK);

 auto numFramesCtrl = XRCCTRL(*this, "StartFrame", wxTextCtrl);
 wxIntegerValidator<int> numFramesValidator(&mFrame);
 numFramesValidator.SetRange(0, 10000);
 numFramesCtrl->SetValidator(numFramesValidator);
}

/**
 * Function to change the data of the machine after its been
 * validated
 *
 * @param event command event
 */
void TimeDlg::OnOK(wxCommandEvent& event)
{
 if ( Validate() && TransferDataFromWindow() )
 {
  // Success! Set values in the class
  mDrawable->SetStartFrame(mFrame);

  EndModal(wxID_OK);
 }
}