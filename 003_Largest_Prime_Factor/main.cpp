#include<iostream>
#include<time.h>
using namespace std;
/*
		������� �������� ����� 13195 - ��� 5, 7, 13 � 29.

		����� ����� ������� �������� ����� 600851475143, ���������� ������� ������?
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
	do//������ ����� �� ������� ��������
	{
		while (!(_numbers % _divider))//��������� ���� ���������� 0
		{
			_numbers /= _divider;// ����� �� 2 ���� ��������� 0 ����� ������� 1
		}
		if (_divider == 2)_divider++;//���� ����� �� ������� ����� �������� 1
		else _divider += 2;//���� ��������  ��� �� 2 ��������� +2
	} while (_numbers > 1);
	clock_t end = clock();
	time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "divider:\t" << _divider - 2 << "\truntime: " << time_spend << endl;
#endif // MyTask

#ifdef TaskOnline
	long long answer = 600851475143;
	double time_spend = 0.0;
	clock_t begin = clock();
	//������� � ������� ���������� �������� �����
	int div = 2;								//������ ���������
	int sq_answ = sqrt(answer) + 1;				//����� ��������

	while (div < sq_answ)							//���� ����� �������
	{
		for (div = 2; div < sq_answ; div++)
		{
			if (!(answer % div))				//���� ����� ������� ������(answer%div==0)
			{
				answer /= div;					//��������� �����
				sq_answ = sqrt(answer) + 1;		//��������� ��������
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