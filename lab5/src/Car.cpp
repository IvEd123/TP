#include "Car.h"

Car::Car(){

}

Car::Car(const Car & car){
    m_sModel        = car.m_sModel;
    m_sNumberPlate  = car.m_sNumberPlate;
}

Car::Car(const std::string &sModel){
    m_sModel = sModel;
}

Car::~Car(){

}

void Car::Print() const {
    std::cout << "Car: \n" << m_sModel << " " << m_sNumberPlate << std::endl;
}

std::string Car::GetModel() const {
    return m_sModel;
}

std::string Car::GetNumberPlate() const {
    return m_sNumberPlate;
}

void Car::SetNumberPlate(const std::string &sNumberPlate) {
    m_sNumberPlate = sNumberPlate;
}

void Car::SetModel(const std::string &sModel){
    m_sModel = sModel;
}   

void Car::Save(std::ostream& os) const {
    os << "Car:\n";
    os << "model:" << m_sModel << "\n";
    os << "number_plate:" << m_sNumberPlate << "\n";
    std::cout << "Car saved successfully.\n";
}

void Car::Load(std::istream& is) {
    std::string line;
    while (std::getline(is, line)) {
        size_t pos = line.find(':');
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        if (key == "model") {
            m_sModel = value;
        }
        else if (key == "number_plate") {
            m_sNumberPlate = value;
        }
    }
    std::cout << "Car loaded successfully.\n";
}


bool Car::Menu() {
    int choice;
    while (1) {
        std::cout << "Menu:\n";
        std::cout << "1. Print car information\n";
        std::cout << "2. Set car model\n";
        std::cout << "3. Set car number plate\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: 
                this->Print();
                break;
            case 2: 
                {
                    std::string model;
                    std::cout << "Enter car model: ";
                    std::cin >> model;
                    this->SetModel(model);
                }
                break;
            case 3: 
                {
                    std::string number_plate;
                    std::cout << "Enter car number plate: ";
                    std::cin >> number_plate;
                    this->SetNumberPlate(number_plate);
                }
                break;
            case 4: 
                return true;
                break;
            default: 
                std::cerr << "Invalid choice.\n";
                return true;
                break;
        }
    }
}
