#include <iostream>
#include <cmath>

using namespace std;

class MyInteger
{
public:
	int set();
	MyInteger();
	MyInteger(int a);
	int size(int a);
	int& operator [](int i);
private:
	int *out;
	int integer;
};

//������ ����
MyInteger::MyInteger(){}

//������ ����, �Ű����� �ʱ�ȭ�� �� ����
MyInteger::MyInteger(int len): integer(len)
{
	out = new int[len];
}

//�迭�� ũ�� ��ȯ
int MyInteger::size(int a)
{
	int size=0;
	while(a/10>0){
		size++;
		a=a/10;
	}
	return size;
}

//���� ����, �� ��ȯ
int MyInteger::set()
{
	cout << "������ �Է��Ͻÿ�. : ";
	cin >> integer;
	cout << "�Էµ� ������ " << integer << "�Դϴ�." << endl;

	return integer;
}

//[] �����ε� ������
int& MyInteger:: operator [](int i)
{
	return out[i];
}

int main()
{
	MyInteger Myint;

	int i,j;
	//set �Լ� ȣ�� , ���� ��ȯ a�� ����
	//size �Լ� ȣ��, ���� ��ȯ b�� ����
	int a = Myint.set();
	int b = Myint.size(a);

	//�迭�� ũ��� ������
	MyInteger out(b);

	j=pow(10,(double)(b-1));
	
	//�迭�� ���� �ڸ��� ��� ���
	for(i = b; i >= 0; i--){
		if(i == 0)
		{
			out[i] = a%10;
			cout << "[" << i << "]" << "��° �ڸ����� ���� " << out[i] << endl;
		}
		//�迭�� ���� NULL(���̻� ���� �������) return -1�� ��ȯ
		else if(out[i]==NULL){
			cout << "-1" << endl;
			return -1;
		}
		else
		{
			out[i] = a/j%10;
			j=j/10;
			cout << "[" << i << "]"  << "��° �ڸ����� ���� " << out[i] << endl;
		}
	}

	system("pause");
	return 0;
}