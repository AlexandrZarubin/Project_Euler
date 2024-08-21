#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<vector>
#include"Timer.h"
using namespace std;

/*
	Наибольшее произведение четырех последовательных цифр в нижеприведенном 1000-значном числе равно 9 × 9 × 8 × 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

	Найдите наибольшее произведение тринадцати последовательных цифр в данном числе.
*/
int Sum(const vector<int>& vec, const int Size, int start, int end)
{
	int Sum = 1;
	if (
		(end - start) % Size != 0 
		|| start > end 
		|| end >= vec.size())
	{
		std::cout << "Invalid range!" << endl;
		return 0;
	}
	else {
		for (int i = start; i <start+Size; i++)
		{
			Sum *= vec[i];
		}
		return Sum;
	}
}
#define LEN_ARR 1000
#define LEN_SERIES 13
//#define myTask		//0.006055	/0.005
//#define TaskOnline1	//0.0008565
//#define TaskOnline2		//0.0010097
struct TIP						//Создаем структуру для хранения "оконечностей змей"
{
	int value;					//текущее значение
	int index;					//текущий индекс положения в массиве
};							
struct SNAKE					//создаем структуру для хранения "змеи" - серий чисел
{
	long long product;			//текущее значение произведения серий чисел - "тело змеи"
	TIP head;					//значение и индекс "головы змеи"
	TIP tail;					//значение и индекс "хвост змеи"
	int len_snake;				//длина змеи
};

bool snale_growth(SNAKE* snake, char num_arr[])
{
	/*
		"змея" растет - увеличивает длину, пока не достигнет длины 13 чисел или не встретит ноль
		параметры:	*snake		- указатель структуры - "змея"
					num_arr[]	- указатель на масси с числами
		return:		true		- змея успешно выросла до длины 13 чисел
					false		- змея встретила ноль
	*/
	while (snake->len_snake < LEN_SERIES)
	{
		snake->head.index++;								// перемещаем голову на шаг вперед
		snake->head.value = num_arr[snake->head.index];
		if (!snake->head.value)								//	ытфлуюруфвюмфдгу == 0
			return false;									// стретила ноль - "змея" не выросла
		snake->product *= snake->head.value;				// изменяем "тело змеи" - произведение серий чисел
		snake->len_snake++;									// увеличиваем длину змеи
	}
	return true;											// "змея" - успешно выросла до 13 чисел

}
bool snale_crawl(SNAKE* snake, char num_arr[])
{
	/*
		"змея" ползет на один шаг, если не встретит ноль
		параметры:	*snake		- указатель структуры - "змея"
					num_arr[]	- указатель на масси с числами
		return:		true		- змея успешно проползла один шаг
					false		- змея встретила ноль
	*/
		snake->head.index++;								// перемещаем голову на шаг вперед
		snake->head.value = num_arr[snake->head.index];
	
		if (!snake->head.value)								//	ытфлуюруфвюмфдгу == 0
			return false;									// стретила ноль - "змея" не выросла
		snake->product /= snake->tail.value;				// обрезаем хвост
		snake->tail.index++;								// перемещаем хвост на шаг вперед
		snake->tail.value = num_arr[snake->tail.index];
		snake->product *= snake->head.value;				// изменяем "тело змеи" - произведение серий чисел
		
	
	return true;											// "змея" - успешно выросла до 13 чисел

}
void snake_jump(SNAKE* snake, char num_arr[])
{
	/*
		"змея" перепрыгивает через ноль
		параметры:	*snake		- указатель структуру - "змея"
					num_arr[]	- указатель на массив с числами
	*/

	int jump = snake->len_snake;						//длина прыжка
	while (!num_arr[snake->tail.index + jump])			//num_arr[snake->tail.index+jump]==0
		jump++;											//изменяем длину прыжка, чтобы не попадать на голь

	snake->tail.index += jump;							//перемещаем "хвост" вперед
	snake->tail.value = num_arr[snake->tail.index];

	snake->head.index = snake->tail.index;				//перемещаем "голову" вперед
	snake->head.value = num_arr[snake->head.index];

	snake->product = snake->tail.value;					//обновляем значение "тела" змеи
	snake->len_snake = 1;								//"змея" занимает только одно число

}
int main()
{
	Timer timer;
#ifdef myTask
	double time_spend = 0.0;
	clock_t begin = clock();

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string patch = "numbers.txt";
	ifstream fin;
	fin.open(patch);
	string str;
	vector<int>vec;
	if (!fin.is_open())cout << "Ошибка открытия фаила!" << endl;
	else
	{
		cout << "Фаил открыт!" << endl;
		while (!fin.eof())
		{
			getline(fin, str);
			cout << str << endl;
			for (int i = 0; i < str.length(); i++)
			{
				string temp = str.substr(i, 1);
				int num = stoi(temp);
				vec.push_back(num);
			}

		}
	}
	//cout << str << endl;
	fin.close();
	int sum = 0, result = 0;;
	for (int i = 0; i < vec.size(); i++)
	{

		sum = Sum(vec, 13, i, i + 13);
		if (result < sum)result = sum;
	}
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Answ:\t" << result << "\truntime: " << time_spend << endl;
	//cout <<"Сумма\t" << result << endl;  
#endif // myTask
#ifdef TaskOnline1
	/*char num_str[] =
		"73167176531330624919225119674426574742355349194934"
		"96983520312774506326239578318016984801869478851843"
		"85861560789112949495459501737958331952853208805511"
		"12540698747158523863050715693290963295227443043557"
		"66896648950445244523161731856403098711121722383113"
		"62229893423380308135336276614282806444486645238749"
		"30358907296290491560440772390713810515859307960866"
		"70172427121883998797908792274921901699720888093776"
		"65727333001053367881220235421809751254540594752243"
		"52584907711670556013604839586446706324415722155397"
		"53697817977846174064955149290862569321978468622482"
		"83972241375657056057490261407972968652414535100474"
		"82166370484403199890008895243450658541227588666881"
		"16427171479924442928230863465674813919123162824586"
		"17866458359124566529476545682848912883142607690042"
		"24219022671055626321111109370544217506941658960408"
		"07198403850962455444362981230987879927244284909188"
		"84580156166097919133875499200524063689912560717606"
		"05886116467109405077541002256983155200055935729725"
		"71636269561882670428252483600823257530420752963450";
		*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string patch = "numbers.txt";
	ifstream file(patch);
	if (!file)std::cout << "Ошибка открытия фаила!" << endl;
	string num_str;
	string line;
	while (getline(file, line))
	{
		num_str += line;
	}
	file.close();

	long long answ = 0;
	long long prod = 1;
	char num_array[1000];
	//разбираем строку на массив
	for (int i = 0; i < 1000; i++)
	{
		char symb[] = { num_str[i],'\0' };
		num_array[i] = atoi(symb);
	}
	//перемножаем последовательность 13 цифр
	for (int i = 0; i < 987; i++)
	{
		prod = 1;
		for (int j = 0; j < 13; j++)
		{
			prod *= num_array[i + j];
			if (prod > answ)answ = prod;
		}
	}
	std::cout << answ << endl;
#endif // TaskOnline1
	
#ifdef TaskOnline2	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string patch = "numbers.txt";
	ifstream file(patch);
	if (!file)std::cout << "Ошибка открытия фаила!" << endl;
	string num_str;
	string line;
	while (getline(file, line))
	{
		num_str += line;
	}
	file.close();
	char num_arr[LEN_ARR];
	long long answ = 0;
	bool is_answ = false;										// флаг наличие ответа(отсутвия нуля в серий чисел)

	for (int i = 0; i < LEN_ARR; i++)							// преобразуем строку в массив цифр
	{
		num_arr[i] = num_str[i] - 48;							// символ '0' имеет код 48, '1'-49 и т.д
	}
	SNAKE snake;												// создаем структуру "змея" - массив чисел из одного числа
	snake.product = num_arr[0];									//произведение равно первому числу массива
	snake.len_snake = 1;										//"длина змеи" - одно число
	snake.head.index = 0;										//голова
	snake.head.value = num_arr[0];								//
	snake.tail.index = 0;										// и "хвост" тоже находятся в первом числе массива
	snake.tail.value = num_arr[0];								//

	while (snake.head.index < LEN_ARR)							// пока не дойдем до конца массива
	{
		if (snake.len_snake < LEN_SERIES)						//"змея" растет
			is_answ = snale_growth(&snake, num_arr);
		else													//или ползет
			is_answ = snale_crawl(&snake, num_arr);

		if (is_answ)											//если есть ответ - обновляем максимум
			answ = (answ > snake.product) ? answ : snake.product;
		else													//если встретился ноль - змея перепрыгивает через него
			snake_jump(&snake, num_arr);
	}
	std::cout << answ << endl;
#endif // TaskOnline2	

	return 0;
}