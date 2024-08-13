#include<iostream>
#include<time.h>
using namespace std;
/*
		2520 - самое маленькое число, которое делится без остатка на все числа от 1 до 10.

		Какое самое маленькое число делится нацело на все числа от 1 до 20?
*/
int is_Number(int range)//MyTask/
{
	int number = 0;
	for (size_t i = 100;; i++)
	{
		for (size_t j = 1; j <= range; j++)
		{
			if (i % j)break;
			if (!(i % j) && j == range)
			{
				return i;
			}
		}
		
	}
}

long long get_NOD(long long num1, long long num2)
/*	функция определяет найбольший общий делитель двух чисел			nod 645 and 681
	параметры num1		- число 1									645/381=1(294)
			  num2		- число 2									381/294=1(87)
	return:	  найбольший общий делитель двух чисел					294/87=3(33)
																	33/33=11(0)nod(3)*/
{
	while (num1 && num2)					//пока ни одно из чисел не равно нулю
	{
		if (num1 >= num2)
		{
			num1 %= num2;
		}
		else num2 %= num1;
	}
	return (num1 > num2) ? num1 : num2;		//возвращает максимальное
}
long long get_NOK(long long num1, long long num2)
/*	функция оперделяющая найибольшее общее кратное двух чисел
	параметры num1		- число 1									
			  num2		- число 2							
	return:	  найбольшее общее кратное двух чисел*/
{
	return num1 * num2 / get_NOD(num1, num2);
}
//#define MyTask//2.48
#define TaskOnline//0
int main()
{
	setlocale(LC_ALL, "rus");
	
#ifdef MyTask
	double time_spend = 0.0;
	clock_t begin = clock();

	int number = is_Number(20);

	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << number << "\truntime: " << time_spend << endl;
#endif // MyTask
#ifdef TaskOnline
	long long answ = 1;

	double time_spend = 0.0;
	clock_t begin = clock();

	for (size_t i = 2; i <=20; i++)				//(1,2)=2
	{											//(2,3)=6
		answ = get_NOK(answ, i);				//(6,4)=12
	}											//(12,5)=
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << answ << "\truntime: " << time_spend << endl;
#endif // TaskOnline

	return 0;
}