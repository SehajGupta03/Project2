/**
 * @file MachineCFactory.h
 *
 * @author Anik Momtaz
 *
 * Factory for creating Machine #1
 */

#ifndef CANADIANEXPERIENCE_MACHINECFACTORY_H
#define CANADIANEXPERIENCE_MACHINECFACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Factory for creating Machine #1
 */
class MachineCFactory {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

public:
    MachineCFactory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINECFACTORY_H
