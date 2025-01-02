/**
 * @file MachineDrawable.cpp
 * @author sehaj
 */

#include "pch.h"
#include "MachineDrawable.h"
#include <machine-api.h>

#include "Picture.h"


/**
 * Constructor
 * @param name name of the drawable
 */
MachineDrawable::MachineDrawable(std::wstring name) : Drawable(name)
{
 MachineSystemFactory factory(name);
 mSystem = factory.CreateMachineSystem();
}

/**
 * Function to draw the machine
 * @param graphics graphics context to draw the machine on
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
 graphics->PushState();
 graphics->Translate(GetPosition().x, GetPosition().y);
 mSystem->DrawMachine(graphics);
 graphics->PopState();
}


/**
 * Hit test
 * @param pos position of mouse
 * @return true or false
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
 return false;
}


/**
 * function to choose machine
 * @param number machine number
 */
void MachineDrawable::SetMachineNumber(int number)
{
 mSystem->ChooseMachine(number);
}


/**
 * Function to get the machine number
 * @return machine number
 */
int MachineDrawable::GetMachineNumber()
{
 return mSystem->GetMachineNumber();
}

/**
 * Function to update machine and its components as per its frame
 * @param frame new frame
 */
void MachineDrawable::SetMachineFrame(int frame)
{
 mSystem->SetMachineFrame(frame);
}

/**
 * Function to set the frame rate of the machine
 * @param rate new rate
 */
void MachineDrawable::SetFrameRate(int rate)
{
 mSystem->SetFrameRate(rate);
}


/**
 * Function to get the machine time
 * @return time of the machine
 */
double MachineDrawable::GetMachineTime()
{
 return mSystem->GetMachineTime();
}


/**
 * Function to save the details of this object
 * in the provided node
 * @param node XML node to save details in
 */
void MachineDrawable::Save(wxXmlNode* node)
{
 node->AddAttribute(L"X", wxString::Format(wxT("%i"), GetPosition().x));
 node->AddAttribute(L"Y", wxString::Format(wxT("%i"), GetPosition().y));

 node->AddAttribute(L"StartFrame", wxString::Format(wxT("%i"), mStartFrame));

 node->AddAttribute(L"Number", wxString::Format(wxT("%i"), GetMachineNumber()));

}

/**
 * Function to load the data of this object
 * from provided node
 * @param node XML node to load details of this object from
 */
void MachineDrawable::Load(wxXmlNode* node)
{
 mStartFrame = wxAtoi(node->GetAttribute(L"StartFrame", L"-1"));
 auto number = wxAtoi(node->GetAttribute(L"Number", L"1"));
 SetMachineNumber(number);
 auto x = wxAtoi(node->GetAttribute(L"X", L"0"));
 auto y = wxAtoi(node->GetAttribute(L"Y", L"0"));
 SetPosition(wxPoint(x, y));

}


/**
 * Function to open Machine Dialog
 * @param parent parent window
 */
void MachineDrawable::OpenDialog(wxWindow* parent)
{
 MachineDialog dialog(parent, mSystem);
 if(dialog.ShowModal() == wxID_CANCEL)
 {
   return;
 }
}
