/**
 * @file MachineCFactory.cpp
 *
 * @author Charles Owen
 */

#include "pch.h"
#include "MachineCFactory.h"
#include "Machine.h"
#include "Box.h"
#include "Sparty.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
MachineCFactory::MachineCFactory(std::wstring resourcesDir) :
        mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}



/**
 * Factory method to create machine #1
 * @return
 */
std::shared_ptr<Machine> MachineCFactory::Create()
{
    // The machine itself
    auto machine = std::make_shared<Machine>();

    /*
     * The Box class constructor parameters are:
     * @param imagesDir Directory containing the images
     * @param boxSize Size of the box in pixels (just the box, not the lid)
     * @param lidSize Size of the lid in pixels
     */
    auto box = std::make_shared<Box>(mImagesDir, 250, 240);

    // This simulates the cam key drop so the box will immediately open
    box->KeyDrop();
    machine->AddComponent(box);

    /*
     * The Sparty class constructor parameters are:
     * @param image Image file to load
     * @param size Size to draw Sparty (width and height)
     * @param springLength How long the spring is when fully extended in pixels
     * @param springWidth How wide the spring is in pixels
     * @param numLinks How many links (loops) there are in the spring
     */
    auto sparty =
        std::make_shared<Sparty>(mImagesDir + L"/sparty.png", 212, 260, 80, 15);

    // This simulates the cam key drop so Sparty will immediately pop up
    sparty->KeyDrop();
    machine->AddComponent(sparty);


    return machine;
}

