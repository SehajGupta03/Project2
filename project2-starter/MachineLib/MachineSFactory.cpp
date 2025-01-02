/**
 * @file MachineSFactory.cpp
 * @author sehaj
 */

#include "pch.h"
#include "MachineSFactory.h"
#include "Box.h"
#include "Cam.h"
#include "Crank.h"
#include "Machine.h"
#include "Pulley.h"
#include "RotationSource.h"
#include "Shaft.h"
#include "Sparty.h"


/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir resources directory
 */
MachineSFactory::MachineSFactory(std::wstring resourcesDir) :
        mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}


/**
 * Function to create machine
 * @return pointer to created machine
 */
std::shared_ptr<Machine> MachineSFactory::Create()
{
    // The machine itself
 auto machine = std::make_shared<Machine>();

 // Locations of some things in the machine
 const int Shaft1Y = -180;
 const int Shaft2Y = -70;
 const int Shaft3Y = -180;


 /*
  * The Box class constructor parameters are:
  * @param imagesDir Directory containing the images
  * @param boxSize Size of the box in pixels (just the box, not the lid)
  * @param lidSize Size of the lid in pixels
  */
 auto box = std::make_shared<Box>(mImagesDir, 250, 240);
 //
 // // This simulates the cam key drop so the box will immediately open
 // box->KeyDrop();
 machine->AddComponent(box);
 //
 /*
  * The Sparty class constructor parameters are:
  * @param image Image file to load
  * @param size Size to draw Sparty (width and height)
  * @param springLength How long the spring is when fully extended in pixels
  * @param springWidth How wide the spring is in pixels
  * @param numLinks How many links (loops) there are in the spring
  */
 auto sparty =
     std::make_shared<Sparty>(mImagesDir + L"/sparty2.png", 212, 260, 80, 15);
 //
 // // This simulates the cam key drop so Sparty will immediately pop up
 // sparty->KeyDrop();
 machine->AddComponent(sparty);

 auto crank = std::make_shared<Crank>(mImagesDir + L"/crank.png");
 crank->SetPosition(150, Shaft1Y);
 crank->SetSpeed(0.5);


 auto shaft1 = std::make_shared<Shaft>();
 shaft1->SetPosition(90, Shaft1Y);       // Left-center end of the shaft
 shaft1->SetSize(10, 70);                // Diameter, length
 shaft1->SetOffset(0.3);                  // Rotation offset so the
                                           // lines don't all line up
 machine->AddComponent(shaft1);
 //
 crank->GetSource()->AddSink(shaft1);


 machine->AddComponent(crank);

 auto pulley1 = std::make_shared<Pulley>(30, 15);
 pulley1->SetPosition(95, Shaft1Y);

 shaft1->GetSource()->AddSink(pulley1);

 // The second pulley
 auto pulley2 = std::make_shared<Pulley>(80, 15);
 pulley2->SetPosition(pulley1->GetX(), Shaft2Y);
 pulley1->BeltTo(pulley2);

 auto shaft2 = std::make_shared<Shaft>();
 shaft2->SetPosition(-115, Shaft2Y);       // Left end of the shaft
 shaft2->SetSize(10, 230);                // Diameter and length
 shaft2->SetOffset(0.1);
 machine->AddComponent(shaft2);

 pulley2->GetSource()->AddSink(shaft2);

 machine->AddComponent(pulley2);
 machine->AddComponent(pulley1);

 auto pulley3 = std::make_shared<Pulley>(15, 15);
 pulley3->SetPosition(-103, Shaft2Y);
 shaft2->GetSource()->AddSink(pulley3);

 auto pulley4 = std::make_shared<Pulley>(90, 15);
 pulley4->SetPosition(pulley3->GetX(), Shaft3Y);
 pulley3->BeltTo(pulley4);

 auto shaft3 = std::make_shared<Shaft>();
 shaft3->SetPosition(-115, Shaft3Y);       // Left end of the shaft
 shaft3->SetSize(10, 50);                // Diameter and length
 shaft3->SetOffset(0.1);
 machine->AddComponent(shaft3);

 pulley4->GetSource()->AddSink(shaft3);

 machine->AddComponent(pulley4);
 machine->AddComponent(pulley3);

 auto cam = std::make_shared<Cam>(mImagesDir);
 cam->SetPosition(-80, -200);

 machine->AddComponent(cam);
 cam->AddKeyDrop(box);
 cam->AddKeyDrop(sparty);
 shaft3->GetSource()->AddSink(cam);


 return machine;
}
