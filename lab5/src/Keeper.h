#ifndef _KEEPER_H_
#define _KEEPER_H_

#include <string>
#include <exception>
#include "Factory.h"

class Keeper{
public:
    Keeper();
    Keeper(int nCopacity);
    Keeper(const Keeper&);
    ~Keeper();

    bool        Save();
    void        Load();
    bool        AddSaveFile(const std::string& sPath);
    void        Print() const;
    void        PushBack(Factory* pObj);
    void        operator+=(Factory* pObj);
    Factory&    operator[](int nIndex);
    int         GetSize() const;

private:
    std::string m_sSaveFilePath;
    Factory**   m_pObjectBuff;
    int         m_nSize         = 0;
    int         m_nCopacity     = 0;

    void        ReallocBuff(int nNewCopacity);
};



#endif