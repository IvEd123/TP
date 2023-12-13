#ifndef _WORKER_H_
#define _WORKER_H_

#include <string>

class Worker{
public:
    Worker();
    Worker(const Worker&);
    Worker(const std::string& sName);
    ~Worker();

    void        Print()             const;
    void        Save(std::ostream&) const;
    bool        Load(std::istream&);
    bool        Menu();
        
    void        SetJobTitle(    const std::string& sJobTitle);
    void        SetName(        const std::string& sName);
    void        SetEntryYear(   int   nEntryYear);

    std::string GetJobTitle()   const;
    std::string GetName()       const;
    int         GetEntryYear()  const;

	friend std::ostream& operator << (std::ostream& os, const Worker&);

	friend std::istream& operator >> (std::istream& in, Worker&);

    bool operator<(Worker&) const;
    bool operator>(Worker&) const;


private:
    std::string m_sName         = "Unknown";
    std::string m_sJobTitle     = "Unemployed";
    int         m_nEntryYear    = 0;
};

#endif