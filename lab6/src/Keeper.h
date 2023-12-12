#ifndef _KEEPER_H_
#define _KEEPER_H_

#include <string>
#include <exception>
#include "Worker.h"

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
    struct container{
        Worker*    p_obj;
        container* p_next;
        container* p_prev;
    }

    std::string m_sSaveFilePath;
    container   m_first;

    int         m_nSize         = 0;
    int         m_nCopacity     = 0;

    void        ReallocBuff(int nNewCopacity);
};



#endif