/*
Если выписать все натуральные числа меньше 10, кратные 3 или 5, то получим 3, 5, 6 и 9. Сумма этих чисел равна 23.
Найдите сумму всех чисел меньше 1000, кратных 3 или 5.
.
*/

#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int res = 0;

	double time_spend = 0.0;					//для хранения времени кода
	clock_t begin = clock();					//старт таймера
	for (int i = 0; i < 1000; i++)
	{
		if (!(i % 3) || !(i % 5))				//инвертируем (9%3==0)==!(9%3) 1==1
		{
			res += i;
		}
	}
	clock_t end = clock();
	time_spend += (double)(end - begin) / CLOCKS_PER_SEC;// это константа, 1000
	cout << "Сумма:\t" << res << "\tВремя выполнения: " << time_spend<<endl;
	cout << begin << " : " << end<<endl;
	//cout << !(8 % 3) << endl;
	return 0;
}