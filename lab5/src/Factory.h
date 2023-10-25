#ifndef _FACTORY_H_
#define _FACTORY_H_
#include <iostream>

class Factory{
public:    

    Factory(){}
    virtual ~Factory() {};

    virtual void Print()              const = 0;
    virtual void Save(std::ostream&)  const = 0;
    virtual void Load(std::istream&)        = 0;
    virtual bool Menu()                     = 0;
protected:


};

#endif