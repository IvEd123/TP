#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Keeper.h"
#include "Worker.h"

void PrintMenu() {
	std::cout << "1) Add item" << std::endl;
	std::cout << "2) Print all" << std::endl;
	std::cout << "3) Select" << std::endl;
	std::cout << "4) Save" << std::endl;
	std::cout << "5) Load" << std::endl;
	std::cout << "m) Menu" << std::endl;
	std::cout << "q) Quit" << std::endl;
}


int main() {
	Keeper keeper(10);
	keeper.AddSaveFile("./save.txt");
	char input;
	PrintMenu();
	while (1)
	{
		std::cout << "> ";
		std::cin >> input;


		switch (input)
		{
		case '1':
		{
			std::cout << "Choose item:\n1)Furniture\n2)Worker\n3)Car\n";
			std::cin >> input;
			Factory* pNewItem;
			switch (input)
			{
			case '1':
				pNewItem = new Furniture();
				break;
			case '2':
				pNewItem = new Worker();
				break;
			case '3':
				pNewItem = new Car();
			break;
			default:
				std::cout << "error: unknown type\n";
				break;
			}
			if(pNewItem){
				keeper += pNewItem;
				pNewItem->Menu();
			}
		}
			break;
		case '2':
			keeper.Print();
			break;
		case '3':
		{
			int ind;
			std::cout << keeper.GetSize() << " elements available\n";
			if(keeper.GetSize() == 0)
				continue;
			std::cin >> ind;
			try
			{
				keeper[ind-1].Menu();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				continue;
			}
			
		}
		break;
		case '4':
			keeper.Save();
			break;
		case '5':
			keeper.Load();
			break;
		case 'm':
			PrintMenu();
			break;
		case 'q':
		default:
			return 0;
		}
	}
	
}
