#include <iostream>
#include <fstream>
#include <string>
#include "MergeSort.h"

void main()
{
	setlocale(LC_ALL, "Rus");

	std::ifstream input;
	std::string path;
	int c = 0;
	int  n;
	int *A;


	std::cout << "Выберите считываение:\n\t 1)из консоли\n\t 2)из файла\n";
	while (!c) {
		std::cout << ">>>";
		std::cin >> c;
		switch (c)
		{
		case 1:
			std::cout << "Размер массива > ";
			std::cin >> n;
			A = new int[n];
			for (int i = 0; i < n; i++)
			{
				std::cout << i << " элемент > ";
				std::cin >> A[i];
			}
			MergeSort(A, 0, n - 1);
			std::cout << "Упорядоченный массив: "; 
			for (int i = 0; i < n; i++)
				std::cout << A[i] << " ";
			std::cout << "\n";
			delete[]A;
			break;

		case 2:
			std::cout << "Введите путь до файла: ";
			std::cin >> path;
			input.open(path);
			if (input.is_open()) {
				input >> n;
				A = new int[n];
				for (int i = 0; i < n; i++)
				{
					input >> A[i];
				}
				MergeSort(A, 0, n - 1);
				std::cout << "Упорядоченный массив: ";
				for (int i = 0; i < n; i++)
					std::cout << A[i] << " ";
				std::cout << "\n";
				delete[]A;
			}
			else {
				std::cout << "Файл не открыт!\n";
			}
			input.close();
			break;
		default:
			c = 0;
			break;
		}
	}
	system("pause");
}