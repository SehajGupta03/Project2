/**
 * @file MachineCFactory.h
 * @author sehaj
 *
 * Factory to create the first machine
 *
 */
 
#ifndef MACHINECFACTORY_H
#define MACHINECFACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Factory to create the first machine
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



#endif //MACHINECFACTORY_H
