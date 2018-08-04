#include <iostream>
#include <cstdlib>

using namespace std;

//function Ŭ������ ����Լ� set(ù��ǥ) move(�̵���ǥ) rotate(90�� �ð������ǥ) ����
class function{
public:
	void set(double l, double c);
	void move(double l, double c);
	void rotate(double l, double c);
	void print();
private:
	double x, y;
};

int main()
{
	function xy;		//function ũ������ xy��ü �Ҵ�

	//ù ��ǥ
	double low, col;
	cout << "ó�� x, y��ǥ�� �Է��ϼ���. : " ;
	cin >> low >> col ;
	//�Ű��Լ� set
	xy.set(low, col);
	xy.print();

	//�̵� ��ǥ
	double plow, pcol;
	cout << "�̵��ϰ� ���� �Ÿ� x, y�� �Է��ϼ���. : " ;
	cin >> plow >> pcol ;
	//�Ű��Լ� move
	xy.move(low+plow, col+pcol);
	xy.print();

	//90�� ��ǥ
	//�Ű��Լ� rotate/
	xy.rotate(low+plow, col+pcol);
	xy.print();

	system("pause");
	return 0;
}

//�Ű��Լ� set�� ���� : x, y ���
void function::set(double l, double c)
{
	x = l;
	y = c;
}

//�Ű��Լ� move�� ���� : set x, y �� �̵��� x, y �� �ջ� ���
void function::move(double l, double c)
{
	cout << "�̵��� ��ǥ�Դϴ�. ";
	x = l;
	y = c;
}

//�Ű��Լ� rotate�� 90�� �̵��� ���� : move�� x, y ��ǥ�� y, -x �� �ٲ� ���
void function::rotate(double l, double c)
{
	cout << "90�� �̵��� ��ǥ�Դϴ�. " ;
	x = c;
	y = -l;
}
//x, y ��ǥ ���
void function::print()
{
	cout << "x : " << x << ", y : " << y << endl << endl;
}


/*
#include <iostream>
#include <cstdlib>

using namespace std;

//function Ŭ������ ����Լ� set(ù��ǥ) move(�̵���ǥ) rotate(90�� �ð������ǥ) ����
class function{
public:
	void set(double x, double y);
	void move(double x, double y);
	void rotate(double x, double y);
};

int main()
{
	function xy;		//function ũ������ xy��ü �Ҵ�

	//ù ��ǥ
	double low, col;
	cout << "ó�� x, y��ǥ�� �Է��ϼ���. : " ;
	cin >> low >> col ;
	//�Ű��Լ� set
	xy.set(low, col);

	//�̵� ��ǥ
	double plow, pcol;
	cout << "�̵��ϰ� ���� �Ÿ� x, y�� �Է��ϼ���. : " ;
	cin >> plow >> pcol ;
	//�Ű��Լ� move
	xy.move(low+plow, col+pcol);

	//90�� ��ǥ
	cout << "90���� �ð�������� �������� ��ǥ�Դϴ�." << endl;
	//�Ű��Լ� rotate/
	xy.rotate(low+plow, col+pcol);

	system("pause");
	return 0;
}

//�Ű��Լ� set�� ���� : x, y ���
void function::set(double x, double y)
{
	cout << "���� ��ǥ�Դϴ�. x : " << x << ", y : " << y << endl << endl;
}

//�Ű��Լ� move�� ���� : set x, y �� �̵��� x, y �� �ջ� ���
void function::move(double x, double y)
{
	cout << "�̵��� ��ǥ�Դϴ�. x : " << x << ", y : " << y << endl << endl;
}

//�Ű��Լ� rotate�� 90�� �̵��� ���� : move�� x, y ��ǥ�� y, -x �� �ٲ� ���
void function::rotate(double x, double y)
{
	cout << "90�� �̵��� ��ǥ�Դϴ�. x : " << y << ", y : " << -x << endl << endl;
}*/