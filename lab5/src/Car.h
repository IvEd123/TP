#ifndef _CAR_H_
#define _CAR_H_

#include <string>
#include "Factory.h"

class Car : public Factory{
public:
    Car();
    Car(const Car&);
    Car(const std::string& sModel);
    ~Car();

    void        Print()             const   override;
    void        Save(std::ostream&) const   override;
    void        Load(std::istream&)         override;
    bool        Menu()                      override;
    std::string GetModel()          const;
    std::string GetNumberPlate()    const;
    void        SetNumberPlate(const std::string& sNumberPlate);
    void        SetModel(const std::string& sModel);

private:
    std::string m_sModel        = "unknown";
    std::string m_sNumberPlate  = "x___xx";
};

#endif