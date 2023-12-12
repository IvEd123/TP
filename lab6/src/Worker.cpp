#include "Worker.h"

Worker::Worker() {
}

Worker::Worker(const Worker & worker) {
    m_sName         = worker.m_sName;
    m_sJobTitle     = worker.m_sJobTitle;
    m_nEntryYear    = worker.m_nEntryYear;
}

Worker::Worker(const std::string &sName) {
    m_sName = sName;
}

Worker::~Worker() {
}

void Worker::Print() const { 
    std::cout << "Worker:"              << std::endl;
    std::cout << m_sName << ", ";
    std::cout << m_sJobTitle << ", "    << std::endl;
    std::cout << m_nEntryYear           << std::endl;
}

void Worker::SetJobTitle(const std::string &sJobTitle) {
    m_sJobTitle = sJobTitle;
}

void Worker::SetName(const std::string &sName) {
    m_sName = sName;
}

void Worker::SetEntryYear(int nEntryYear) {
    m_nEntryYear = nEntryYear;
}

std::string Worker::GetJobTitle() const {
    return m_sJobTitle;
}

std::string Worker::GetName() const {
    return m_sName;
}

void Worker::GetEntryYear() const {
    return m_nEntryYear;
}

void Worker::Save(std::ostream& os) const {
    os << "Worker:\n";
    os << "name: " << m_sName << "\n";
    os << "job_title: " << m_sJobTitle << "\n";
    os << "ey: " << m_nEntryYear << "\n";
    os << "end\n\n";
    std::cout << "Worker saved successfully.\n";
}

void Worker::Load(std::istream& is) {
    while (!is.eof()) {
        std::string key, value;
        is >> key;
        if(key == "end")
            break;
        is >> value;
        if (key == "name:") {
            m_sName = value;
        }
        else if (key == "job_title:") {
            m_sJobTitle = value;
        }
        else if (key == "ye:") {
            m_nEntryYear = std::stoi(value);
        }
    }
    std::cout << "Worker loaded successfully.\n";
}

bool Worker::Menu() {
    int choice;
    while (1) {
        std::cout << "1. Print worker information\n";
        std::cout << "2. Set worker name\n";
        std::cout << "3. Set worker job title\n";
        std::cout << "4. Set worker's entry year\n";
        std::cout << "5. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: 
                this->Print();
                break;
            case 2:
                {
                    std::string name;
                    std::cout << "Enter worker name: ";
                    std::cin >> name;
                    this->SetName(name);
                }
                break;
            case 3: 
                {
                    std::string job_title;
                    std::cout << "Enter worker job title: ";
                    std::cin >> job_title;
                    this->SetJobTitle(job_title);
                }
                break;
            case 4: 
                {
                    int nEntryYear;
                    std::cout << "Enter worker entry year: ";
                    std::cin >> address;
                    this->seten(address);
                }
                break;
            case 7: 
                return true;
                break;
            default: 
                std::cout << "Invalid choice.\n";
                return true;
                break;
        }
    }
}
