/*
���� �������� ��� ����������� ����� ������ 10, ������� 3 ��� 5, �� ������� 3, 5, 6 � 9. ����� ���� ����� ����� 23.
������� ����� ���� ����� ������ 1000, ������� 3 ��� 5.
.
*/

#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int res = 0;

	double time_spend = 0.0;					//��� �������� ������� ����
	clock_t begin = clock();					//����� �������
	for (int i = 0; i < 1000; i++)
	{
		if (!(i % 3) || !(i % 5))				//����������� (9%3==0)==!(9%3) 1==1
		{
			res += i;
		}
	}
	clock_t end = clock();
	time_spend += (double)(end - begin) / CLOCKS_PER_SEC;// ��� ���������, 1000
	cout << "�����:\t" << res << "\t����� ����������: " << time_spend<<endl;
	cout << begin << " : " << end<<endl;
	//cout << !(8 % 3) << endl;
	return 0;
}