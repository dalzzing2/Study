#include <iostream>
using namespace std;

int main()
{
	int n;
	double guess;
	double r;			//n은 int 설정, guess와 r의 값은 double 로 설정

	cout << "Press one n : ";	// 임의의 정수 n 의 값 입력	
	cin >> n;

	guess = (double)n/2;		// n/2 는 정수형 으로 나오기 때문에 형 변환을 위해 double로 바꿔줌

	for(int i=1; i<=5; i++){
		r = n / guess;			
		guess = (guess+r)/2;		//문제의 계산 식 요구 조건

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);			//소수점 2번째 자리까지 나오게 하기 위한 포맷 지정
		cout << "*i 번째*" << endl;
		cout << "guess : " << guess << " , r : " << r << endl; //포문 돌때마다 guess 와 r 의 값 설정
	}
	return 0;
}