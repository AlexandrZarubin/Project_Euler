#include<iostream>
#include<time.h>
using namespace std;
/*
	Сумма квадратов первых десяти натуральных чисел равна

				1^2 + 2^2 + ... + 10^2 = 385
	Квадрат суммы первых десяти натуральных чисел равен

				(1 + 2 + ... + 10)^2 = 55^2 = 3025
	Следовательно, разность между суммой квадратов и квадратом суммы первых десяти натуральных чисел составляет 3025 − 385 = 2640.

	Найдите разность между суммой квадратов и квадратом суммы первых ста натуральных чисел.
*/
//#define MyTask
#define TaskOnline
int main()
{
	
	setlocale(LC_ALL, "rus");
	double time_spend = 0.0;
	clock_t begin = clock();
#ifdef MyTask
	int Sum_Square = 0;
	int Square_Sum = 0;
	for (size_t i = 0; i <= 100; i++)
	{
		Sum_Square += i;
		Square_Sum += i * i;
	}
	Sum_Square *= Sum_Square;
	int answ = Sum_Square - Square_Sum;
#endif // MyTask

#ifdef TaskOnline
	int answ;										//
	int num = 100;									//
	int sum_sq;										//
	int sum_num;									//
	sum_num = (num * num + num) / 2;
	sum_sq = (num * (num + 1) * (2 * num + 1)) / 6;
	answ = sum_num * sum_num - sum_sq;
#endif // TaskOnline



	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << answ << "\truntime: " << time_spend << endl;
	return 0;
}