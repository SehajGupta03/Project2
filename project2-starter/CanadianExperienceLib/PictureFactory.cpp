/**
 * @file PictureFactory.cpp
 *
 * @author Charles Owen
 * @author Anik Momtaz
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    auto machine = std::make_shared<MachineDrawable>(resourcesDir);
    machine->SetPosition(wxPoint(990, 600));
    picture->SetMachineOne(machine);

    auto machine2 = std::make_shared<MachineDrawable>(resourcesDir);
    machine2->SetPosition(wxPoint(670, 600));
    machine2->SetMachineNumber(2);
    picture->SetMachineTwo(machine2);

    // create 1 actor for machines


    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background2.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);

    background->AddDrawable(machine);
    background->AddDrawable(machine2);

    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(150, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(370, 460));
    picture->AddActor(sparty);

    machine->SetFrameRate(picture->GetTimeline()->GetFrameRate());
    machine->SetStartFrame(0);
    machine2->SetFrameRate(picture->GetTimeline()->GetFrameRate());

    return picture;
}

