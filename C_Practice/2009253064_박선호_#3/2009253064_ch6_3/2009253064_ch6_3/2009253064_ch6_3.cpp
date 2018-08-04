#include <iostream>
#include <cstdlib>

using namespace std;

//function 클래스에 멤버함수 set(첫좌표) move(이동좌표) rotate(90도 시계방향좌표) 선언
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
	function xy;		//function 크래스의 xy객체 할당

	//첫 좌표
	double low, col;
	cout << "처음 x, y좌표를 입력하세요. : " ;
	cin >> low >> col ;
	//매개함수 set
	xy.set(low, col);
	xy.print();

	//이동 좌표
	double plow, pcol;
	cout << "이동하고 싶은 거리 x, y를 입력하세요. : " ;
	cin >> plow >> pcol ;
	//매개함수 move
	xy.move(low+plow, col+pcol);
	xy.print();

	//90도 좌표
	//매개함수 rotate/
	xy.rotate(low+plow, col+pcol);
	xy.print();

	system("pause");
	return 0;
}

//매개함수 set의 역할 : x, y 출력
void function::set(double l, double c)
{
	x = l;
	y = c;
}

//매개함수 move의 역할 : set x, y 와 이동한 x, y 의 합산 출력
void function::move(double l, double c)
{
	cout << "이동된 좌표입니다. ";
	x = l;
	y = c;
}

//매개함수 rotate의 90도 이동한 역할 : move된 x, y 좌표를 y, -x 로 바꿔 출력
void function::rotate(double l, double c)
{
	cout << "90도 이동한 좌표입니다. " ;
	x = c;
	y = -l;
}
//x, y 좌표 출력
void function::print()
{
	cout << "x : " << x << ", y : " << y << endl << endl;
}


/*
#include <iostream>
#include <cstdlib>

using namespace std;

//function 클래스에 멤버함수 set(첫좌표) move(이동좌표) rotate(90도 시계방향좌표) 선언
class function{
public:
	void set(double x, double y);
	void move(double x, double y);
	void rotate(double x, double y);
};

int main()
{
	function xy;		//function 크래스의 xy객체 할당

	//첫 좌표
	double low, col;
	cout << "처음 x, y좌표를 입력하세요. : " ;
	cin >> low >> col ;
	//매개함수 set
	xy.set(low, col);

	//이동 좌표
	double plow, pcol;
	cout << "이동하고 싶은 거리 x, y를 입력하세요. : " ;
	cin >> plow >> pcol ;
	//매개함수 move
	xy.move(low+plow, col+pcol);

	//90도 좌표
	cout << "90도를 시계방향으로 돌렸을때 좌표입니다." << endl;
	//매개함수 rotate/
	xy.rotate(low+plow, col+pcol);

	system("pause");
	return 0;
}

//매개함수 set의 역할 : x, y 출력
void function::set(double x, double y)
{
	cout << "현재 좌표입니다. x : " << x << ", y : " << y << endl << endl;
}

//매개함수 move의 역할 : set x, y 와 이동한 x, y 의 합산 출력
void function::move(double x, double y)
{
	cout << "이동된 좌표입니다. x : " << x << ", y : " << y << endl << endl;
}

//매개함수 rotate의 90도 이동한 역할 : move된 x, y 좌표를 y, -x 로 바꿔 출력
void function::rotate(double x, double y)
{
	cout << "90도 이동한 좌표입니다. x : " << y << ", y : " << -x << endl << endl;
}*/