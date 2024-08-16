/*
	Выписав первые шесть простых чисел, получим 2, 3, 5, 7, 11 и 13. Очевидно, что 6-е простое число - 13.

	Какое число является 10001-м простым числом?
*/
#include<iostream>
#include<time.h>

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

using namespace std;

#define LEN_ARR 200000										// длина массива - зависит от размера искомого числа

bool is_prime(char prime_ar[], int num)
{
	/*
		функция принимает число и возращает true - если число простое
		параметры:	prime_ar[] - масив с ранее вычесленными простыми числами
					num		   - проверяемое число
		return		true	   - если число простое
	*/
	int div_max = sqrt(num) + 1;							// выносим вычисление квадратного корня из цикла for

	for (size_t div = 2; div < div_max; div++)				// чтоб он не вычисляллся каждую итерацию цикла
	{
		if (prime_ar[div] && !(num % div))					// пропускаем составные делители и срабатываем при num % i == 0
		{
			return false;
		}
	}
	return true;
}

//#define MyTask//0.026
#define TaskOnline//0.007
int main()
{

	setlocale(LC_ALL, "rus");
	double time_spend = 0.0;
	clock_t begin = clock();
#ifdef MyTask
	long long _numbers = 2;
	long long _numbers_temp = _numbers;
	int counter = 0;
	bool flag = true;
	do//запуск цикла на простые делители
	{
		_numbers_temp = _numbers;
		flag = true;
		for (int i = 2; i <= sqrt(_numbers_temp); i++)
		{
			if (_numbers_temp % i == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			counter++;
		}
		_numbers++;
	} while (counter != 10001);



	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << --_numbers << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	static char prime_arr[LEN_ARR] = {};					// массив[простое число] = 1 static писать обязательно
	prime_arr[2] = 1;
	int count = 1;											//	определили одно простое число в массиве -2
	int num = 2;

	while (count<10001)
	{
		num++;												// перебираем числа
		if (is_prime(prime_arr, num))
		{
			prime_arr[num] = 1;								// отмечаем число как простое в массиве
			count++;
		}
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << num << "\truntime: " << time_spend << endl;
#endif // TaskOnline



	return 0;
}