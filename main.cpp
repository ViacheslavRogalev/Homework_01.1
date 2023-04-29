#include <iostream>
#include <fstream>
#include <Windows.h>

int* create_arr(const int size_row)
{
	int* arr = new int[size_row];
	return arr;
}

void print_arr(int* arr, const int arr_size_row)
{
	std::ofstream fout("out.txt", std::ios::app);
	fout << arr_size_row << std::endl;
	
	for (int i = 0; i < arr_size_row - 1; i++)
	{
		fout << arr[i] << "  ";
	}

	fout << arr[arr_size_row - 1] << std::endl;
	fout.close();
}

void shiftLeft_arr(int* arr, const int arr_size_row)
{
	int tmp = arr[0];
	for (int i = 0; i < arr_size_row - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[arr_size_row - 1] = tmp;
}

void shiftRight_arr(int* arr, const int arr_size_row)
{
	int tmp = arr[arr_size_row - 1];
	for (int i = arr_size_row - 1; i >= 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::ifstream fin("in.txt");

	int arr1_size_row = 0;
	fin >> arr1_size_row;

	int* arr1 = create_arr(arr1_size_row);

	for (int i = 0; i < arr1_size_row; i++)
	{
		fin >> arr1[i];
	}

	int arr2_size_row = 0;
	fin >> arr2_size_row;

	int* arr2 = create_arr(arr2_size_row);

	for (int i = 0; i < arr2_size_row; i++)
	{
		fin >> arr2[i];
	}

	fin.close();

	shiftLeft_arr(arr1, arr1_size_row);
	shiftRight_arr(arr2, arr2_size_row);

	std::ofstream fout("out.txt");
	fout.close();

	print_arr(arr2, arr2_size_row);
	print_arr(arr1, arr1_size_row);

	delete[] arr1;
	delete[] arr2;
	return 0;
}