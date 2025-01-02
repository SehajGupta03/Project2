/**
 * @file Machine.h
 * @author sehaj
 *
 * Class representing the actual machine
 *
 */
 
#ifndef MACHINE_H
#define MACHINE_H
#include <vector>
#include <memory>

#include "Component.h"

/**
 * Class representing the actual machine
 */
class Machine {
private:
 /// Collection of all the components of this machine
 std::vector<std::shared_ptr<Component>> mComponents;

 /// Time of this Machine
 double mTime = 0;

public:
 Machine();

 void AddComponent(std::shared_ptr<Component> component);

 void Draw(std::shared_ptr<wxGraphicsContext> graphics);

 void SetTime(double time);

 void Advance(double time);

};



#endif //MACHINE_H
