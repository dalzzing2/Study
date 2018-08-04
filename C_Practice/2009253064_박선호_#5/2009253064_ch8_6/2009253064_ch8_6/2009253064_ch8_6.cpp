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

//생성자 생성
MyInteger::MyInteger(){}

//생성자 생성, 매개변수 초기화할 값 지정
MyInteger::MyInteger(int len): integer(len)
{
	out = new int[len];
}

//배열의 크기 반환
int MyInteger::size(int a)
{
	int size=0;
	while(a/10>0){
		size++;
		a=a/10;
	}
	return size;
}

//정수 저장, 값 반환
int MyInteger::set()
{
	cout << "정수를 입력하시오. : ";
	cin >> integer;
	cout << "입력된 정수는 " << integer << "입니다." << endl;

	return integer;
}

//[] 오버로딩 연산자
int& MyInteger:: operator [](int i)
{
	return out[i];
}

int main()
{
	MyInteger Myint;

	int i,j;
	//set 함수 호출 , 정수 반환 a에 저장
	//size 함수 호출, 정수 반환 b에 저장
	int a = Myint.set();
	int b = Myint.size(a);

	//배열의 크기로 저장함
	MyInteger out(b);

	j=pow(10,(double)(b-1));
	
	//배열에 따라 자릿수 출력 계산
	for(i = b; i >= 0; i--){
		if(i == 0)
		{
			out[i] = a%10;
			cout << "[" << i << "]" << "번째 자리수의 값은 " << out[i] << endl;
		}
		//배열의 값이 NULL(더이상 값이 없을경우) return -1을 반환
		else if(out[i]==NULL){
			cout << "-1" << endl;
			return -1;
		}
		else
		{
			out[i] = a/j%10;
			j=j/10;
			cout << "[" << i << "]"  << "번째 자리수의 값은 " << out[i] << endl;
		}
	}

	system("pause");
	return 0;
}