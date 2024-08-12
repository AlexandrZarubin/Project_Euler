#include<iostream>
#include<time.h>
using namespace std;
/*
	Число-палиндром с обеих сторон (справа налево и слева направо) читается одинаково. 
	
	Самое большое число-палиндром, полученное умножением двух двузначных чисел – 9009 = 91 × 99.

	Найдите самый большой палиндром, полученный умножением двух трехзначных чисел.
*/
//#define MyTask
#define TaskOnline

bool is_palindrom(int num)//Ункция определяет,является ли число палиндром	//TaskOnline
{
	int check_num = num;
	int revers_num = 0;					//check_num=123->321=revers_num
	
	while (check_num)					//пока число не уменьшится до нуля
	{
		revers_num *= 10;				//увеличиваем регистр цифр обратного числа
		revers_num += check_num % 10;	//прибавляем к обратному числу младший регистр проверяемого числа
		check_num /= 10;				//обрезаем младший регистр
	}
	return revers_num == num;
}
int main()
{
	setlocale(LC_ALL, "rus");
#ifdef MyTask
	double time_spend = 0.0;
	clock_t begin = clock();
	int Palindrom = 0;
	int PalindromCopy = 0;
	int Temp = 0;
	int BigPalindrom = 0;
	for (size_t i = 11; i < 999; i++)
	{
		for (size_t j = 1; j < 999; j++)
		{
			Palindrom = i * j;
			int PalindromCopy = Palindrom;
			Temp = 0;
			while (Palindrom)//смысл цикла надо разобрать число начиная с последней цифпы и заного собрать
			{
				int Buffer = Palindrom % 10;//получаем послденее число
				Temp = Temp * 10 + Buffer;// берем число умнажаем на 10 и прибовляем последнее число- первое число 0
				Palindrom = Palindrom / 10;// убераем последниее число из основной
			}
			if (PalindromCopy == Temp)
			{
				if (BigPalindrom < Temp)
				{
					BigPalindrom = Temp;
				}
			};

		}
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Palindrom:\t" << BigPalindrom << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	int answ = 0;
	int num;

	double time_spend = 0.0;
	clock_t begin = clock();
	for (size_t i = 999; i > 99; i--)			//перебираем множитель от большого к меньшему
	{
		// 990(Делится на 11)
		for (size_t j = 990; j > 99; j-=11)		//все палиндромы с четным кол-во цифр делятся на 11!
		{
			num = i * j;						//
			if (answ > num)break;				//если произведение чисел меньше уже полученного ответа - то и дальше будет меньше

			if (is_palindrom(num))				//находим палиндром
			{
				answ = num;						//сохраняем если он максимален
				break;							//Пропускаем цикл е.к последующее число заведомо меньше
			}
		}
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Palindrom:\t" << answ << "\truntime: " << time_spend << endl;
#endif // TaskOnline

	return 0;
}