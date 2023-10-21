#ifndef _FACTORY_H_
#define _FACTORY_H_

class Factory{
public:    
    Factory();
    Factory(const Factory&);
    virtual ~Factory() = 0;

    virtual void Print() const;
    virtual void Save()  const;
    virtual void Load();
protected:


};

#endif