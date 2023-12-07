/*
2. Дан массив размера N.
Возвести в квадрат все его локальные минимумы
(то есть числа, меньшие своих соседей).
*/

#include <iostream>

void ar_in(size_t , int*);
int* new_array(size_t, int*);
void ar_sqrt1(int*);
void ar_sqrt2(size_t, int*);
void ar_out(size_t, int*, int*);

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	size_t n;
	cout << "Введите число элементов массива:";
	cin >> n;

	if (n == 0)
	{
		cerr << "Ошибка: размер массива не может быть равен 0";
		return 1;
	}

	int* array;
	array = new int[n];
	ar_in(n, array);

	switch (n)
	{
	case 1: ar_sqrt1(array); break;
	default: ar_sqrt2(n,array); break;
	}
}

void ar_in(size_t n, int* array)
{
	cout << "Введите элементы массива:" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

int* new_ar(size_t n, int* array)
{
	int* new_array = new int [n];
	for (size_t i = 0; i < n; i++)
	{
		new_array[i] = array[i];
	}
	return new_array;
}

void ar_sqrt1(int* array)
{
	int* new_array = new_ar(1, array);
	new_array[0] *= array[0];
	ar_out(1, new_array, array);
}

void ar_sqrt2(size_t n, int* array)
{
	int* new_array = new_ar(n, array);
	if (array[0] < array[1])
	{
		new_array[0] *= new_array[0];
	}

	for (size_t i = 1; i < (n - 1); i++)
	{
		int a0 = array[i - 1], a1 = array[i], a2 = array[i + 1];
		if ((a1 < a0) && (a1 < a2))
		{
			new_array[i] *= new_array[i];
		}
	}

	if (array[n - 1] < array[n - 2])
	{
		new_array[n - 1] *= new_array[n - 1];
	}
	ar_out(n, new_array, array);
}

void ar_out(size_t n, int* new_array, int* array)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << new_array[i] << " ";
	}

	delete[] array;
	delete[] new_array;
}