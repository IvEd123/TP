#ifndef _KEEPER_H_
#define _KEEPER_H_

#include <string>
#include <exception>

template <typename T>
class Keeper{
public:
    Keeper();
    Keeper(int nCopacity);
    Keeper(const Keeper&);
    ~Keeper();

    bool        Save();
    T&          Load();
    bool        AddSaveFile(const std::string& sPath);
    void        Print() const;
    void        PushBack(const T& rObj);
    void        operator+=(const T& rObj);
    T&          operator[](int nIndex);

private:
    std::string m_sSaveFilePath;
    T*          m_pObjectBuff;
    int         m_nSize;
    int         m_nCopacity;

    void        ReallocBuff(int nNewCopacity);
};

template <typename T>
inline Keeper<T>::Keeper(){
    m_nSize     = 0;
    m_nCopacity = 0;
}

template <typename T>
inline Keeper<T>::Keeper(int nCopacity){
    ReallocBuff(nCopacity);
}

template <typename T>
inline Keeper<T>::Keeper(const Keeper &){

}

template <typename T>
inline Keeper<T>::~Keeper(){

}

template <typename T>
inline bool Keeper<T>::Save(){

    return false;
}

template <typename T>
inline T &Keeper<T>::Load(){

    // TODO: insert return statement here
}

template <typename T>
inline bool Keeper<T>::AddSaveFile(const std::string &sPath){
    m_sSaveFilePath = sPath;
    return false;
}

template <typename T>
inline void Keeper<T>::Print() const{
    for(int i = 0; i < m_nSize; i++)
        if(m_pObjectBuff[i] != nullptr)
            m_pObjectBuff[i].Print();

}

template <typename T>
inline void Keeper<T>::PushBack(const T &rObj){
    if(m_nSize + 1 >= m_nCopacity) //alloc more memory if buffer is full
        ReallocBuff(m_nCopacity * 1.5);
    
    
}

template <typename T>
inline void Keeper<T>::operator+=(const T &rObj){
    PushBack(rObj);
}

template <typename T>
inline T &Keeper<T>::operator[](int nIndex){
    if(nIndex >= m_nSize || nIndex < 0)
        throw "Invalid index\n";
    
    if(m_pObjectBuff[nIndex] == nullptr)
        throw "Array error\n";

    return m_pObjectBuff[nIndex];
}

template <typename T>
inline void Keeper<T>::ReallocBuff(int nNewCopacity){
    T* pNewBuff = new T[nNewCopacity];

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

#endif