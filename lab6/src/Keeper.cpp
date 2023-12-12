#include "Keeper.h"

#include <iostream>
#include <fstream>

#include "Furniture.h"
#include "Worker.h"
#include "Car.h"

Keeper::Keeper(){
}

Keeper::Keeper(int nCopacity){
    ReallocBuff(nCopacity);
}

Keeper::Keeper(const Keeper &){

}

Keeper::~Keeper(){
    for(int i = 0; i < m_nSize; i++){
        if(m_pObjectBuff[i]== nullptr)
            continue;
        delete m_pObjectBuff[i];
    }
    delete m_pObjectBuff;
}

bool Keeper::Save(){
    std::ofstream os;
    os.open(m_sSaveFilePath);
    if(!os){
        std::cout << "Couldn't open file\n";
        return false;
    }
    for(int i = 0; i < m_nSize; i++)
        if(m_pObjectBuff[i])
            m_pObjectBuff[i]->Save(os);
    os << "end\n";
    os.close();
    return false;
}

void Keeper::Load(){
    std::ifstream is(m_sSaveFilePath);
    if(!is){
        std::cout << "Couldn't open file\n";
        return;
    }
    std::string sBuff;
    Factory* pNewItem;
    while (!is.eof()) {
        is >> sBuff;
        if(sBuff == "end")
            return;
        if(sBuff.empty()){
            std::cout << "File is empty :(\n";
            return;
        }
        if(sBuff == "Worker:") {
            pNewItem = new Worker();
        }
        else if(sBuff == "Furniture:") {
            pNewItem = new Furniture();
        }
        else if(sBuff == "Car:"){
            pNewItem = new Car();
        }
        if(!pNewItem)
            continue;
        pNewItem->Load(is);
        PushBack(pNewItem);
    }
    is.close();
}

bool Keeper::AddSaveFile(const std::string &sPath){
    m_sSaveFilePath = sPath;
    return false;
}

void Keeper::Print() const{
    for(int i = 0; i < m_nSize; i++)
        if(m_pObjectBuff[i] != nullptr)
            m_pObjectBuff[i]->Print();

}

void Keeper::PushBack(Factory *pObj){
    if(pObj == nullptr)
        throw "Tried to push null pointer\n";

    if(m_nSize + 1 >= m_nCopacity) //alloc more memory if buffer is full
        ReallocBuff(m_nCopacity * 1.5);
    
    m_pObjectBuff[m_nSize++] = pObj;
}

void Keeper::operator+=(Factory*pObj){
    PushBack(pObj);
}

Factory& Keeper::operator[](int nIndex){
    if(nIndex >= m_nSize || nIndex < 0)
        throw "Invalid index\n";
    
    if(m_pObjectBuff[nIndex] == nullptr)
        throw "Array error\n";

    return *m_pObjectBuff[nIndex];
}

int Keeper::GetSize() const
{
    return m_nSize;
}

void Keeper::ReallocBuff(int nNewCopacity){
    Factory** pNewBuff = new Factory*[nNewCopacity];

    if(m_nSize <= 0){
        m_pObjectBuff = pNewBuff;
        m_nCopacity = nNewCopacity;
        return;
    }

    std::copy(&m_pObjectBuff[0], &m_pObjectBuff[m_nSize-1], pNewBuff);
    delete m_pObjectBuff;
    m_pObjectBuff = pNewBuff;
    m_nCopacity = nNewCopacity;
}