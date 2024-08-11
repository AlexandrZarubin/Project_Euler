#include<iostream>
#include<time.h>
using namespace std;
/*
		Простые делители числа 13195 - это 5, 7, 13 и 29.

		Каков самый большой делитель числа 600851475143, являющийся простым числом?
*/
//#define MyTask
#define TaskOnline
int main()
{
	setlocale(LC_ALL, "rus");
#ifdef MyTask
	long long _numbers = 600851475143;
	int _divider = 2;
	double time_spend = 0.0;
	clock_t begin = clock();
	do//запуск цикла на простые делители
	{
		while (!(_numbers % _divider))//запускаем пока равняюется 0
		{
			_numbers /= _divider;// делим на 2 пока равняется 0 иначе добавим 1
		}
		if (_divider == 2)_divider++;//если вышли из первого цикла добавлем 1
		else _divider += 2;//если делитель  уже не 2 добавляем +2
	} while (_numbers > 1);
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "divider:\t" << _divider - 2 << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	long long answer = 600851475143;
	double time_spend = 0.0;
	clock_t begin = clock();
	//дипазон в котором изменяется делитель числа
	int div = 2;								//начало диапазона
	int sq_answ = sqrt(answer) + 1;				//конец дипазона

	while (div < sq_answ)							//пока число делится
	{
		for (div = 2; div < sq_answ; div++)
		{
			if (!(answer % div))				//если число делится нацело(answer%div==0)
			{
				answer /= div;					//уменьшаем число
				sq_answ = sqrt(answer) + 1;		//обновляем диапазон
				break;
			}
		}
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "divider:\t" << answer << "\truntime: " << time_spend << endl;
#endif // TaskOnline
	
	return 0;
}