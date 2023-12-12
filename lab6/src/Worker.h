#ifndef _WORKER_H_
#define _WORKER_H_

#include <string>

class Worker{
public:
    Worker();
    Worker(const Worker&);
    Worker(const std::string& sName);
    ~Worker();

    void        Print()                 const  override;
    void        Save(std::ostream&)     const  override;
    void        Load(std::istream&)            override;
    bool        Menu()                         override;
        
    void        SetJobTitle(    const std::string& sJobTitle);
    void        SetName(        const std::string& sName);
    void        SetEntryYear(   int   nEntryYear);

    std::string GetJobTitle()   const;
    std::string GetName()       const;
    int         GetEntryYear()  const;


private:
    std::string m_sName         = "Unknown";
    std::string m_sJobTitle     = "Unemployed";
    int         m_nEntryYear    = 0;
};

#endif