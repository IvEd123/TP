#ifndef _WORKER_H_
#define _WORKER_H_

#include <string>
#include "Factory.h"

class Worker : public Factory{
public:
    Worker();
    Worker(const Worker&);
    Worker(const std::string& sName);
    ~Worker();

    void        Print()                 const  override;
    void        Save(std::ostream&)     const  override;
    void        Load(std::istream&)            override;
    bool        Menu()                         override;
        
    void        SetPhoneNumber( const std::string& sPhoneNumber);
    void        SetJobTitle(    const std::string& sJobTitle);
    void        SetAdress(      const std::string& sAdress);
    void        SetName(        const std::string& sName);
    void        SetSalary(      float fSalary);

    std::string GetPhoneNumber()    const;
    std::string GetJobTitle()       const;
    std::string GetAdress()         const;
    std::string GetName()           const;
    float       GetSalary()         const;


private:
    std::string m_sName         = "Unknown";
    std::string m_sJobTitle     = "Unemployed";
    std::string m_sAdress       = "Homeless";
    std::string m_sPhoneNumber  = "0";
    float       m_fSalary       = 0;
};

#endif