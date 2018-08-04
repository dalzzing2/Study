#include <iostream>
#include <cassert>

using namespace std;

//함수의 오버로딩 구현, 윗 함수는 정수형 2개를 매개변수로, 아랫 함수는 실수형 1개를 매개변수로 받는 함수로 선언
double ConvertToKPH(int min, int sec);
double ConvertToKPH(double kph);

int main()
{
	int sel=0;
	int min=0, sec=0;
	double kph=0;
	double Kph=0, Mph=0;
	char ans;

	do{
		cout << "정의 1번은 1번, 정의 2번은 2번을 눌러주세요. : " ;
		cin >> sel;		//매개변수를 입력받게 선택하는 공간
		if(sel==1){		//시간을 입력받는 if문 (정수형 분 초) - 윗함수로 들어가게 됨
			cout << "분과 초를 정수형으로 입력하여 주세요.(예) 3시 15분 -> 3 15, 5시 -> 5 00   " << endl;
			cout << ": " ;
			cin >> min >> sec;
		}
		else if(sel==2){	//kph를 입력받는 if문 (실수형 kph) - 아랫함수로 들어가게됨
			cout << "Kph를 더블형(실수)로 입력하여 주세요. : " ;
			cin >> kph;
		}
		else		//선택되지 않을경우 에러를 출력하고 프로그램을 종료하게 된다.
			assert(0);

		// 매개변수에 따라 들어가는 함수가 결정되는 부분, 각각 함수에 따라 반환되는 값이 다르기 때문에, kph(정의1번)과 mph(정의2번)으로 값을 저장
		Kph = ConvertToKPH(min, sec);
		Mph = ConvertToKPH(kph);

		//각각 선택된것에 따라 출력)
		if(sel==1)
			cout << "1번을 선택하였습니다. Kph 는 " << Kph << " 입니다. " << endl;
		else if(sel==2)
			cout << "2번을 선택하였습니다. Mph 는 " << Mph << " 입니다. " << endl;

		//드라이브 검사
		cout << "계속하시겠습니까.(Y,y)" << endl;
		cin >> ans;
	}while(ans=='y'||ans=='Y');

	return 0;
}

double ConvertToKPH(int min, int sec)
{
	double kph;
	// 1kph는 1시간에 1km 를 간다는 의미, 즉 60분에 1km. 3600초에 1km
	double pmin, psec;

	pmin = (double)min/60;
	psec = (double)sec/3600;

	kph = pmin+psec;

	return kph;
}

double ConvertToKPH(double kph)
{
	// 1.61kph 는 1mph
	kph = (double)kph/1.61;
	return kph;
}