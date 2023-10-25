#include "Worker.h"

Worker::Worker() {
}

Worker::Worker(const Worker & worker) {
    m_sName         = worker.m_sName;
    m_sJobTitle     = worker.m_sJobTitle;
    m_sAdress       = worker.m_sAdress;
    m_sPhoneNumber  = worker.m_sPhoneNumber;
    m_fSalary       = worker.m_fSalary;
}

Worker::Worker(const std::string &sName) {
    m_sName = sName;
}

Worker::~Worker() {
}

void Worker::Print() const { 
    std::cout << "Worker:\n";
    std::cout << m_sName << ", ";
    std::cout << m_sJobTitle << ", " << std::endl;
    std::cout << m_sAdress << ", "  << std::endl;
    std::cout << m_sPhoneNumber << ", " << std::endl;
    std::cout << m_fSalary << "" << std::endl;
}

void Worker::SetPhoneNumber(const std::string &sPhoneNumber) {
    m_sPhoneNumber  = sPhoneNumber;
}

void Worker::SetJobTitle(const std::string &sJobTitle) {
    m_sJobTitle = sJobTitle;
}

void Worker::SetAdress(const std::string &sAdress) {
    m_sAdress = sAdress;
}

void Worker::SetName(const std::string &sName) {
    m_sName = sName;
}

void Worker::SetSalary(float fSalary) {
    m_fSalary = fSalary;
}

std::string Worker::GetPhoneNumber() const {
    return m_sPhoneNumber;
}

std::string Worker::GetJobTitle() const {
    return m_sJobTitle;
}

std::string Worker::GetAdress() const {
    return m_sAdress;
}

std::string Worker::GetName() const {
    return m_sName;
}

float Worker::GetSalary() const {
    return m_fSalary;
}

void Worker::Save(std::ostream& os) const {
    os << "Worker:\n";
    os << "name: " << m_sName << "\n";
    os << "job_title: " << m_sJobTitle << "\n";
    os << "address: " << m_sAdress << "\n";
    os << "phone_number: " << m_sPhoneNumber << "\n";
    os << "salary: " << m_fSalary << "\n";
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
        else if (key == "address:") {
            m_sAdress = value;
        }
        else if (key == "phone_number:") {
            m_sPhoneNumber = value;
        }
        else if (key == "salary:") {
            m_fSalary = std::stof(value);
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
        std::cout << "4. Set worker address\n";
        std::cout << "5. Set worker phone number\n";
        std::cout << "6. Set worker salary\n";
        std::cout << "7. Exit\n";
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
                    std::string address;
                    std::cout << "Enter worker address: ";
                    std::cin >> address;
                    this->SetAdress(address);
                }
                break;
            case 5: 
                {
                    std::string phone_number;
                    std::cout << "Enter worker phone number: ";
                    std::cin >> phone_number;
                    this->SetPhoneNumber(phone_number);
                }
                break;
            case 6: 
                {
                    float salary;
                    std::cout << "Enter worker salary: ";
                    std::cin >> salary;
                    this->SetSalary(salary);
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
