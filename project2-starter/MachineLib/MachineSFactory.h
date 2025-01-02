/**
 * @file MachineSFactory.h
 * @author sehaj
 *
 * Factory to create the second machine
 *
 */
 
#ifndef MACHINESFACTORY_H
#define MACHINESFACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Factory to create the second machine
 */
class MachineSFactory {
private:
 /// Path to the resources directory
 std::wstring mResourcesDir;

 /// Path to the images directory
 std::wstring mImagesDir;

public:
 MachineSFactory(std::wstring resourcesDir);

 std::shared_ptr<Machine> Create();
};



#endif //MACHINESFACTORY_H
