#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include "Keeper.h"
#include "Worker.h"

void task_2(std::string filename) {

}


int main() {
    int choice;
A:
    while (true) {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "1. task 1" << std::endl;
        std::cout << "2. task 2" << std::endl;
        std::cout << "0. quit" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
        system("clear");
        switch (choice) {
        case 1: {
            Worker buffer;
            Keeper keeper;
            std::string filename = "";
            while (true) {
                system("clear");
                std::cout << "Menu task 1:"  << std::endl;
                std::cout << "1. Add object" << std::endl;
                std::cout << "2. Load "    	 << std::endl;
                std::cout << "3. Save"       << std::endl;
                std::cout << "4. Print all"  << std::endl;
                std::cout << "5. Search"     << std::endl;
                std::cout << "6. Remove item"<< std::endl;
                std::cout << "0. Back"       << std::endl;
                std::cout << "> ";
                std::cin >> choice;
                system("clear");
                switch (choice) {
                case 1:
                    std::cin >> buffer;
                    keeper.Push(buffer);
                    break;

                case 2:
                    std::cout << "Enter load file: ";
                    std::cin >> filename;
                    keeper = keeper.Load(filename);
                    break;

                case 3:
                    std::cout << "Enter save file: ";
                    std::cin >> filename;
                    keeper.Save(filename);
                    break;
                    break;

                case 4:
                    keeper.Print();
                    system("pause");
                    break;

                case 5:
                    keeper.Search();
                    system("pause");
                    break;

                case 6:
                    keeper.Remove();
                    system("pause");
                    break;

                case 0:
                    goto A;

                default:
                    std::cout << "Choose correct option" << std::endl;
                    system("pause");

                    break;
                }
            }
        }
        case 2: {
            std::string filename = "";
            std::cout << "Enter file name: ";
            std::cin >> filename;
            task_2(filename);
            system("pause");
            break;
        }

        case 0: {
            return 0;
        }

        default: {
            std::cout << "Choose correct option" << std::endl;
            system("pause");
            break;
        }

        }

    }
}