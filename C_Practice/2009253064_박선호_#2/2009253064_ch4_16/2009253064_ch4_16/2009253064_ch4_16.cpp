#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int getHighScore(string name, int value);

static int store_value=0;
string store_name;				//store_value ���� ������� ��������� �ϱ� ������ static ���� ����, string�� �Բ� ����� ���ڿ�

int main()
{
	int value;
	string name;

	ifstream stream;
	stream.open("Score.txt");		//Score ��� ������ �о�´�.

	while(stream>>name>>value){		//������ ����������
		cout << name << " " << value ;	//������ ���� ���
		getHighScore(name, value);		//getHighScore �Լ��� �̸��� ���� �Ű����� ����
		cout << endl;
	}

	cout << endl << endl << "Result : " << store_name << ", " << store_value << endl;		//���� ��� ���
	stream.close();		//Score ��� ������ �ݴ´�.
	system("pause");
	return 0;
}

int getHighScore(string name, int value)
{
	if(value > store_value){			//���޵Ǿ� �� ���� ����Ǿ� �ִ� ������ ũ�ٸ� (�ʱ� ���尪�� 0)
		store_value=value;				//���޵Ǿ� �� ���� ����Ǿ� �ִ� ������ ����
		store_name=name;				//���������� �̸��� �Բ� ����
		cout << "       Curret Best Score : " << store_name << " , " << store_value; //����Ǿ����� ����Ǿ����� �������
	}
	return 0;
}