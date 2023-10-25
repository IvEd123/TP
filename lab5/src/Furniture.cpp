#include "Furniture.h"

#include <sstream>

std::string aFurnitureTypes[Furniture::FURTYPE_COUNT];


void Furniture::DefineTypes() {
    aFurnitureTypes[Furniture::FURTYPE_UNKNOWN]   = "unknown";
    aFurnitureTypes[Furniture::FURTYPE_TABLE]     = "table";
    aFurnitureTypes[Furniture::FURTYPE_CHAIR]     = "chair";
    aFurnitureTypes[Furniture::FURTYPE_CLOSET]    = "closet";
    aFurnitureTypes[Furniture::FURTYPE_BED]       = "bed";
}

Furniture::Furniture() {
    DefineTypes();
}

Furniture::Furniture(const Furniture & fur) {
    DefineTypes();
    m_Type      = fur.m_Type;
    m_nSize[3]  = fur.m_nSize[3];
    m_sColor    = fur.m_sColor;
    m_sMaterial = fur.m_sMaterial;
    m_fPrice    = fur.m_fPrice;
}

Furniture::Furniture(TYPE type) {
    m_Type = type;
}

Furniture::~Furniture() {

}

void Furniture::Print() const {
    std::cout << "Furniture:\n";
    std::cout << m_sColor << " " << m_sMaterial << " " << aFurnitureTypes[m_Type] << ":\n";
    std::cout << GetSize() << ";\n";
    std::cout << "price: " << m_fPrice << std::endl;
}

std::string Furniture::GetType() const {
    return aFurnitureTypes[m_Type];
}

std::string Furniture::GetColor() const {
    return m_sColor;
}

std::string Furniture::GetMaterial() const {
    return m_sMaterial;
}

std::string Furniture::GetSize() const {
    return std::to_string(m_nSize[0]) + " " +  std::to_string(m_nSize[1]) + " "+ std::to_string(m_nSize[2]);
}

float Furniture::GetPrice() const {
    
    return m_fPrice;
}

void Furniture::SetType(TYPE type) {
    m_Type = type;
}

void Furniture::SetColor(const std::string &sColor) {
    m_sColor = sColor;
}

void Furniture::SetSize(float x, float y, float z) {
    m_nSize[0] = x;
    m_nSize[1] = y;
    m_nSize[2] = z;
}

void Furniture::SetMaterial(const std::string &sMaterial) {
    m_sMaterial = sMaterial;
}

void Furniture::Save(std::ostream& os) const {
    os << "Furniture:\n";
    os << "type:" << m_Type << "\n";
    os << "size:" << m_nSize[0] << " " << m_nSize[1] << " " << m_nSize[2] << "\n";
    os << "color:" << m_sColor << "\n";
    os << "material:" << m_sMaterial << "\n";
    os << "price:" << m_fPrice << "\n";
    std::cout << "Furniture saved successfully.\n";
}

void Furniture::Load(std::istream& is) {
    std::string line;
    while (std::getline(is, line)) {
        size_t pos = line.find(':');
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        if (key == "type") {
            m_Type = (TYPE)std::stoi(value);
        }
        else if (key == "size") {
            std::stringstream ss(value);
            ss >> m_nSize[0] >> m_nSize[1] >> m_nSize[2];
        }
        else if (key == "color") {
            m_sColor = value;
        }
        else if (key == "material") {
            m_sMaterial = value;
        }
        else if (key == "price") {
            m_fPrice = std::stof(value);
        }
    }
    std::cout << "Furniture loaded successfully.\n";
}

bool Furniture::Menu() {
    int choice;
    while (1) {
        std::cout << "Menu:\n";
        std::cout << "1. Print furniture information\n";
        std::cout << "2. Set furniture type\n";
        std::cout << "3. Set furniture color\n";
        std::cout << "4. Set furniture size\n";
        std::cout << "5. Set furniture material\n";
        std::cout << "6. Set furniture price\n";
        std::cout << "7. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: 
                this->Print();
                break;
            case 2: 
                {
                    int type;
                    std::cout << "Enter furniture type (1 - table, 2 - chair, 3 - closet, 4 - bed): ";
                    std::cin >> type;
                    this->SetType((TYPE)type);
                }
                break;
            case 3: 
                {
                    std::string color;
                    std::cout << "Enter furniture color: ";
                    std::cin >> color;
                    this->SetColor(color);
                }
                break;
            case 4: 
                {
                    float x, y, z;
                    std::cout << "Enter furniture size (length, width, height): ";
                    std::cin >> x >> y >> z;
                    this->SetSize(x, y, z);
                }
                break;
            case 5: 
                {
                    std::string material;
                    std::cout << "Enter furniture material: ";
                    std::cin >> material;
                    this->SetMaterial(material);
                }
                break;
            case 6: 
                {
                    float price;
                    std::cout << "Enter price: ";
                    std::cin >> price;
                    m_fPrice = price;
                }
                break;
            case 7: 
                return true;
            default: 
                std::cerr << "Invalid choice.\n";
                return false;
        }
    }
}
