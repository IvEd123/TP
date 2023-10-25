#ifndef _FURNITURE_H_
#define _FURNITURE_H_

#include <string>
#include "Factory.h"

class Furniture : public Factory{
public:
    enum TYPE {
        FURTYPE_UNKNOWN = 0,
        FURTYPE_TABLE,
        FURTYPE_CHAIR,
        FURTYPE_CLOSET,
        FURTYPE_BED,

        FURTYPE_COUNT
    };

    Furniture();
    Furniture(const Furniture&);
    Furniture(TYPE type);
    ~Furniture();

    void        Print()              const   override;
    void        Save(std::ostream&)  const   override;
    void        Load(std::istream&)          override;
    bool        Menu()                       override;
   

    std::string GetType()       const;
    std::string GetColor()      const;
    std::string GetMaterial()   const;
    std::string GetSize()       const;
    float       GetPrice()      const;

    void        SetType(TYPE type);
    void        SetColor(const std::string& sColor);
    void        SetSize(float x, float y, float z);
    void        SetMaterial(const std::string& sMaterial);

private:
    void        DefineTypes();


    TYPE        m_Type      = FURTYPE_UNKNOWN;
    float       m_nSize[3]  = {1, 1, 1};
    std::string m_sColor    = "invisible";
    std::string m_sMaterial = "vacuum";
    float       m_fPrice    = 0;
};

#endif