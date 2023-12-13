#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include "Keeper.h"
#include "Worker.h"

void task_2(const std::string& filename) {
    std::vector<std::string> sentences;
    std::ifstream file(filename);
    if (!file.is_open())
        return;
    
    std::string sentence;
    while (getline(file, sentence, '.'))
    {
        sentence += '.';
        if( sentence.find(",") == std::string::npos)
            break;
        sentences.push_back(sentence);
    }
    file.close();


    for (int i = 0; i  <= sentences.size() - 1; i++)
        std::cout << sentences[i] << std::endl; 
}


int main() {
    int choice;
A:
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. task 1" << std::endl;
        std::cout << "2. task 2" << std::endl;
        std::cout << "0. quit" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            Worker buffer;
            Keeper keeper;
            std::string filename = "";
            while (true) {
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
                    break;

                case 5:
                    keeper.Search();
                    break;

                case 6:
                    keeper.Remove();
                    break;

                case 0:
                    goto A;

                default:
                    std::cout << "Choose correct option" << std::endl;

                    break;
                }
            }
        }
        case 2: {
            std::string filename = "";
            std::cout << "Enter file name: ";
            std::cin >> filename;
            task_2(filename);
            break;
        }

        case 0: {
            return 0;
        }

        default: {
            std::cout << "Choose correct option" << std::endl;
            break;
        }

        }

    }
}