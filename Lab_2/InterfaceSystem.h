#ifndef INTERFACESYSTEM_H
#define INTERFACESYSTEM_H

#include <string>
#include <iostream>

using namespace std;

class InterfaceSystem {
public:

    virtual bool canAccess(string zone) const = 0;

    virtual void showType() const = 0;

    virtual string getIdentifier() const = 0;

    virtual ~InterfaceSystem() {}
};

#endif