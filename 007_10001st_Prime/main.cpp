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

	for (int div = 2; div < div_max; div++)				// чтоб он не вычисляллся каждую итерацию цикла
	{
		if (prime_ar[div] && !(num % div))					// пропускаем составные делители и срабатываем при num % i == 0
		{
			return false;
		}
	}
	return true;
}

bool is_composite(char comp_arr[], int num)
{
	/*
		функция принимает число и возращает true - если число составное
		параметр:	com_arr[]					- массив с ранее вычисленными составными числами
					com_arr[num] = 0			- число простое
					com_arr[num] = 1			- число составное
					num							- проверяемое число
		return:		true						-если число составное
	*/
	int div_max = sqrt(num) + 1;							// выносим вычисление квадратного корня из цикла for

	for (int div = 2; div < div_max; div++)					// чтоб он не вычисляллся каждую итерацию цикла
	{
		if (!comp_arr[div] && !(num % div) && (num != 2))	//пропускаем составные делители и срабатываем при num%i=0, пропускаем число 2
		{
			return true;
		}
	}
	return false;
}
int note_composite(char comp_arr[], int step, int start, int finish)
{
	/*
		функция отмечает составные числа в массиве
		параметр:	com_arr[]					- массив с ранее вычисленными составными числами
					com_arr[num] = 0			- число простое
					com_arr[num] = 1			- число составное
					step						- простое число, служит шагом
					start						- начальный игдекс в массиве
					finish						- конечный индекс
		return:									-количество отмеченных составных чисел
	*/
	int cnt = 0;												//
	int shift = (start % step == 0) ? 0 : (step - (start % step));//смещение индекса start
	start += shift;

	for (int i = start; i < finish; i+=step)
	{
		if (!comp_arr[i])										// если еще не отмечено
		{
			comp_arr[i] = 1;									//отмечаем составные числа
			cnt++;												// и счиатем их
		}
	}
	return cnt;
}
int get_prime(char comp_arr[], int number, int start, int finish)
{
	/*
		функция считает кол-во простых чисел и возращает значение простого числа из отрезка массива по его номеру
		параметр:	com_arr[]					- массив с ранее вычисленными составными числами
					com_arr[num] = 0			- число простое
					com_arr[num] = 1			- число составное
					number						- порядковый номер простого числа
					start						- начальный место в массиве
					finish						- конечный место в массиве
		return:									-значение простого числа
	*/
	int answ = 0;
	int cnt = 0;

	for (int  i = start; i < finish; i++)		// перебор массива
	{
		if (!comp_arr[i]) 
		{										
			cnt++;								// считаем простые числа
		}
		if (cnt == number)						// когда дошли до искомого счета
		{
			answ = i;							// индекс в массиве является искомым числом
			break;
		}
	}

	return answ;
}
//#define MyTask//0.026
//#define TaskOnline//0.007
#define TaskOnline2//0.008 //решета Эратосфена
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

#ifdef TaskOnline2
	static char composite_arr[LEN_ARR] = { 0 };			// массив[составное число] = 1 static писать обязательно
	int cnt_prime = 0;									// счетчик кол-во простых чисел в массиве
	int past_cnt_prime;									// сохраняем значение счетчика предыдыщих итераций
	int cnt_comp = 0;									//счетчик кол-во составных чисел
	int answ;											//
	int start = 0;										//добавляем занчение в массиве по 1000
	int finish = 1000;									//
	int step_max;										//
	for (int num = 2; num < 1000; num++)				//определяем статус первых 1000 чисел
	{
		if (is_composite(composite_arr, num))
		{
			composite_arr[num] = 1;
			cnt_comp++;
		}
	}
	
	cnt_prime = 998 - cnt_comp;							//от 2 до 999-> xbctk

	while (cnt_prime<10001)
	{
		past_cnt_prime = cnt_prime;						//сохраняем значение счетчика предыщих итераций
		start += 1000;									//добавляем значение в массиве по 1000
		finish += 1000;
		cnt_comp = 0;
		step_max = finish / 2;							//максимальное значение шага

		for (int  step = 2; step < step_max; step++)
		{
			if (!composite_arr[step])					//числа, делимые на step? в массиве как составное
			{
				cnt_comp += note_composite(composite_arr, step, start, finish);
			}
		}
			cnt_prime += (1000 - cnt_comp);				//вычитаем составные числа, осталные - простые
	}
	//10001 - предыдщие значения счетчика = порядковый номер искомого числа в отрезке массива
	answ = get_prime(composite_arr, 10001 - past_cnt_prime, start, finish);

	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Answ:\t" << answ << "\truntime: " << time_spend << endl;
#endif // TaskOnline2


	return 0;
}