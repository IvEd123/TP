#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>
#include "deque.h"
#include "Keeper.h"

void PrintMenu() {
	std::cout << "a) Generate Array" << std::endl;
	std::cout << "b) Print array" << std::endl;
	std::cout << "c) Calculate average" << std::endl;
	std::cout << "d) Print 1st deque" << std::endl;
	std::cout << "e) Print 2st deque" << std::endl;
	std::cout << "f) Remove element from 1st deque" << std::endl;
	std::cout << "g) Remove element from 2st deque" << std::endl;
	std::cout << "h) Compare deques" << std::endl;
	std::cout << "i) Add deques" << std::endl;
	std::cout << "m) Menu" << std::endl;
	std::cout << "q) Quit" << std::endl;
}

template <typename T>
void Menu() {
	std::vector<T> vec;
//	GenerateArray(vec);
	Deque<T> d1;
	Deque<T> d2;

	char command;
	PrintMenu();
	do
	{
		std::cout << "> ";
		std::cin >> command;
		switch (command)
		{
		case 'a': 
		//	GenerateArray(vec);
		case 'b': 
			for (auto elem : vec)
				std::cout << elem << " ";
			std::cout << std::endl;
			break;
		case 'c': 
			try
			{
		//		std::cout << average(vec) << std::endl; 
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case 'd': 
			d1.Print();
			break;
		case 'e': 
			d2.Print();
			break;
		case 'f': 
			try{
				T old_elem;
				d1 - &old_elem;
				std::cout << old_elem << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case 'g': 
			try{
				T old_elem;
				d2 - &old_elem;
				std::cout << old_elem << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case 'h':
			std::cout << "Deque 1 is" << (d1 < d2 ? " not " : " ") << "bigger than deque2" <<std::endl;
			break;
		case 'i':
		{
			Deque<T> d3 = d1 + d2;
			d3.Print();
		}
		break;
		case 'm': 
			PrintMenu();
			break;
		default:
			break;
		}
	} while (command != 'q');
}

template <>
void Menu<char*>() {
	std::vector<char*> vec;
	Deque<char*> d1;
	Deque<char*> d2;

	char command;
	PrintMenu();
	do
	{
		std::cout << ">";
		std::cin >> command;
		switch (command)
		{
		case 'a': 
			//GenerateArray(vec);
		case 'b': 
			for (auto elem : vec)
				std::cout << elem << " ";
			std::cout << std::endl;
			break;
		case 'c': 
			try
			{
				//std::cout << average(vec) << std::endl; 
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case 'd': 
			d1.Print();
			break;
		case 'e': 
			d2.Print();
			break;
		case 'f': 
			try{
				char old_elem[CHAR_P_LEN];
				d1 - old_elem;
				std::cout << old_elem << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case 'g': 
			try{
				char old_elem[CHAR_P_LEN];
				d2 - old_elem;
				std::cout << old_elem << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			break;
		case 'h':
			std::cout << "Deque 1 is" << (d1 < d2 ? " not " : " ") << "bigger than deque2" <<std::endl;
			break;
		case 'i':
		{
			Deque<char*> d3 = d1 + d2;
			d3.Print();
		}
		break;
		case 'm': 
			PrintMenu();
			break;
		default:
			break;
		}
	} while (command != 'q');
}

int main() {
	srand(time(NULL));
	char type;
	std::cout << "Choose type" << std::endl;
	std::cout << "i)int \nd)double \nc)char \nf)float \ns)char* \n";
	std::cin >> type;
	switch (type){
		case 'i':
			Menu<int>();	
			break;
		case 'd': 
			Menu<double>();	
			break;
		case 'c': 
			Menu<char>();	
			break;
		case 'f': 
			Menu<float>();	
			break;
		case 's': 
			Menu<char*>();	
			break;
		default:				
			break;
	}
}
