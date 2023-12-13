#ifndef _KEEPER_H_
#define _KEEPER_H_

#include <string>
#include <exception>
#include "Worker.h"

class Keeper {
private:
    struct container {
        Worker     obj;
        container* next;
    };
    int        m_nCounter;
    container* m_pFirst;
    container* m_pLast;
public:
    Keeper();
    ~Keeper();

    void    Push(const Worker& obj); 
    void    Save(const std::string& sFilename); 
    Keeper  Load(const std::string& sFilename); 

    bool    IsEmpty() const;
    void    Print()   const; 
    void    Search()  const;
    void    Redact() ;
    void    Remove();
};



#endif