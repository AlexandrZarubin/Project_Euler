#include<iostream>
#include<time.h>
using namespace std;
/*
		Каждый следующий элемент ряда Фибоначчи получается при сложении двух предыдущих. Начиная с 1 и 2, первые 10 элементов будут:

		1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

		Найдите сумму всех четных элементов ряда Фибоначчи, которые не превышают четыре миллиона.
*/
#define MyTask
//#define TaskOnline
int main()
{
	setlocale(LC_ALL, "rus");
#ifdef MyTask
	int _NumberA = 0;
	int _NumberB = 1;
	int _next = 0;
	long long _summ = 0;
	double time_spend = 0.0;
	clock_t begin = clock();
	for (int i = 0; _next < 4000000; i++)
	{
		if (!(_next % 2))
		{
			_summ += _next;
		}
		//cout << _next << " ";
		_NumberA = _NumberB;
		_NumberB = _next;
		_next = _NumberA + _NumberB;
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Result:\t" << _summ << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	int fib1 = 1;
	int fib2 = 2;
	int fib_next = 0;
	int evens_summ = 0;
	double time_spend = 0.0;
	clock_t begin = clock();
	while (fib_next < 4000000)
	{
		fib_next = fib1 + fib2;
		fib1 = fib2;
		if (!(fib2 % 2))evens_summ += fib2;
		fib2 = fib_next;
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Result:\t" << evens_summ << "\truntime: " << time_spend << endl;
#endif // TaskOnline

	return 0;
}