#include<iostream>
#include<time.h>

using namespace std;

/*
	Тройка Пифагора - три натуральных числа a < b < c, для которых выполняется равенство

	a^2 + b^2 = c^2
	Например, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	Существует только одна тройка Пифагора, для которой a + b + c = 1000.
	Найдите произведение abc.
*/
int my_pow(int a,int b)
{

	return a*a+b*b;
}
bool is_bool(int a, int b, int c)
{
	return (a + b + c) == 1000;
}
bool is_triple(int sq[], int a, int b, int c)
{
	//функция проверяет, является ли число тройкой пифагора
	// sq[] - указатель на массив с уже вычисленными квадратами чисел
	// a,b,c - проверяем натуральные числа
	return sq[a] + sq[b] == sq[c];
}
bool is_correct(int a, int b, int c)
{
	//функция проверяет, является ли число особой тройкой
	return a + b + c == 1000;
}
//#define myTask //0.233
#define TaskOnline//0.008
int main()
{
	double time_spend = 0.0;
	clock_t begin = clock();
	setlocale(LC_ALL, "rus");
#ifdef myTask
	int a, b, c;
	bool flag = false;
	for (int i = 1; i < 999 && !flag; i++)
	{
		for (int j = i + 1; j < 999 && !flag; j++)
		{
			for (int k = j + 1; k < 999 && !flag; k++)
			{
				if (my_pow(i, j) == k * k && is_bool(i, j, k))
				{
					cout << "a: " << i << " b: " << j << " c: " << k << endl;
					c = i * j * k;
					flag = true;
					break;
				}
			}
		}
	}
#endif // myTask
#ifdef TaskOnline
	int arr_sq[1000] = { 0 };				// чтоб не вычислять многократно одно и тоже
	for (int i = 0; i < 1000; i++)			//вычисляем квадраты натуральных чисел до 1000
	{
		arr_sq[i] = i * i;					//и сохраняем их в массив
	}
	int a, b, c, a_and_b,result;					// стороны треугольника и a+b

	for ( c = 500; c > 0; c--)				//сторона не может быть больше a+b т.е 1000/2
	{
		a_and_b = 1000 - c;					// сумма сторон ф+и+с=1000
		for (b=a_and_b-1;  b>0; b--)		//перебираем цмкл, чтобы не повторятся
		{
			a = a_and_b - b;				//а-квеличивается
			if (a > b)break;				//прерываем цикл, чтобы не повторятся

			if (is_triple(arr_sq, a, b, c) && is_correct(a, b, c))
			{
				result = a * b * c;

			}
		}
	}
#endif // TaskOnline		


	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << result << "\truntime: " << time_spend << endl;
	return 0;
}