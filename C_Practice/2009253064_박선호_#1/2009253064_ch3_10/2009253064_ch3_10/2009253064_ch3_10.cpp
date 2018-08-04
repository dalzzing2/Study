#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
	int motherh, fatherh, childh;				//엄마키 아빠키 아이키 선언
	string sex;									//성별 문자형 선언

	cout << "*정수형으로 하라고 하여서(정수형 선언), 1inch = 2.54*" << endl << endl;
	cout << "엄마키 : " ; cin >> motherh;
	cout << "아빠키 : " ; cin >> fatherh;

	cout << "아이의 성별 남성(m), 여성(f) : ";
	cin >> sex;

	cout << endl;

	//엄마 키와 아빠 키를 입력받아서 인치로 계산한 후 인치값을 미리 보여줌
	cout << "엄마인치 : " << motherh/2.54 << "아빠인치 : " << fatherh/2.54 << endl << endl;
	
	//아이의 성별이 남성일 경우m , 여성일 경우 f 로 들어가 키 값을 계산
	//아이의 키가 인치형으로 계산되었기 때문에,
	//'1피트'는 '12인치' 이므로 피트를 /12 그리고 나머지 인치를 출력하기 위해 %12 사용

	if(sex=="m"){
		childh = ((motherh/2.54*(13.0/12.0))+fatherh/2.54)/2.0;
		cout << "아이의 키는 " << childh/12 << "피트(pete), " << childh%12 << "인치(inch) 입니다." << endl;
	}
	else if(sex=="f"){
		childh = ((fatherh/2.54*(12.0/13.0))+motherh/2.54)/2.0;
		cout << "아이의 키는 " << childh/12 << "피트(pete), " << childh%12 << "인치(inch) 입니다." << endl;	
	}
	
	system("pause");

	return 0;
}