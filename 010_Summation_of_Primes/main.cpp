#include<iostream>
#include<time.h>
#include<math.h>
#define LEN_ARR 2000000
using namespace std;
/*
	Сумма простых чисел меньше 10 равна 2 + 3 + 5 + 7 = 17.

	Найдите сумму всех простых чисел меньше двух миллионов
*/
//#define myTask1	//1.632
#define TaskOnline	//0.118
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
		if (!comp_arr[div] && !(num % div))	//пропускаем составные делители и срабатываем при num%i=0, пропускаем число 2
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

	for (int i = start; i < finish; i += step)
	{
		if (!comp_arr[i])										// если еще не отмечено
		{
			comp_arr[i] = 1;									//отмечаем составные числа
			cnt++;												// и счиатем их
		}
	}
	return cnt;
}
int main()
{
	double time_spend = 0.0;
	clock_t begin = clock();
#ifdef myTask1
	long long _numbers = 2;
	long long _numbers_temp = _numbers;
	unsigned long long Sum = 0;
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
			Sum += _numbers;
		}
		_numbers++;
	} while (_numbers_temp <2000000);



	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Answ:\t" << Sum << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	static char composite_arr[LEN_ARR] = { 0 };			// массив[составное число] = 1 static писать обязательно							
	long long answ=0;											
								
	for (int num = 2; num < LEN_ARR;num++)				//
	{
		//если число не отмечено состовным->проверяем число -> если число простое
		if (!composite_arr[num]&&!is_composite(composite_arr, num))
		{
			note_composite(composite_arr, num, num, LEN_ARR);		//отмечаем составные числа,кратные простому
			answ += num;											//скаладываем простое число с остальными
		}
	}

	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Answ:\t" << answ << "\truntime: " << time_spend << endl;
#endif // TaskOnline

	return 0;
}