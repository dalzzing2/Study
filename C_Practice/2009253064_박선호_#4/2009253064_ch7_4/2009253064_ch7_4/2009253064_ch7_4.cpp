#include <iostream>
#include <cstdlib>

using namespace std;

class HotDogStand{
public:
	HotDogStand(int id, int hds);	//생성자
	void justSold();				//핫도그의 수 증가
	int getNumSold();				//팔린 양을 받는 함수
	int getID();					//아이디를 받는 함수
	int getTotalSold();				//전체 팔린양을 반환하는 함수
	void check(char c);				//초기화 함수
private:
	int idNum;				//영업점
	int hotDogsSold;		//팔린개수
	static int totalSold;	//하루동안 전체 팔린 양
};

//초기 전체 팔린 양 0 으로 초기화
int HotDogStand::totalSold=0;

//영업점과, 개수를 매개변수로 할당
HotDogStand::HotDogStand(int id, int hds)
{
	idNum = id;
	hotDogsSold = hds;
	return;
}

//각 영업점에 팔린거에 따라, 팔린 개수(영업점에 따라 다름)와 전체 팔린 양(영업점과 무관 static) 증가
void HotDogStand::justSold()
{
	hotDogsSold++;
	totalSold++;
	return;
}

//팔린양을 반환
int HotDogStand::getNumSold()
{
	return hotDogsSold;
}

//영업점 이름 반환
int HotDogStand::getID()
{
	return idNum;
}

//전체 팔린양 반환
int HotDogStand::getTotalSold()
{
	return totalSold;
}
//초기화 함수
void HotDogStand::check(char c)
{
	hotDogsSold=0;
	totalSold=0;
	return;
}
int main()
{
	//영업점 3개
	HotDogStand s1(1, 0), s2(2, 0), s3(3, 0);
	char c='r';	//초기 문자 r 로 지정

	//r 또는 R은 리셋, a 또는 A는 추가
	while(c=='r'||c=='R'||c=='a'||c=='A'){
		//r이거나 R이면 check함수 호출(초기화)
		if(c=='r'||c=='R'){
			s1.check(c);
			s2.check(c);
			s3.check(c);
		}

		int i;
		cout << "첫번째 영업점의 판매 개수를 입력하시오. : ";
		cin >> i;
		int j;
		cout << "두번째 영업점의 판매 개수를 입력하시오. : ";
		cin >> j;
		int k;
		cout << "세번째 영업점의 판매 개수를 입력하시오. : ";
		cin >> k;

		//(판매개수에 맞춰 함수 호출)
		for(i; i>0; i--)
			s1.justSold();
		for(j; j>0; j--)
			s2.justSold();
		for(k; k>0; k--)
			s3.justSold();

		//(출력)
		cout << "영업점 " << s1.getID() << " 판매개수 " << s1.getNumSold() << "." << endl;
		cout << "영업점 " << s2.getID() << " 판매개수 " << s2.getNumSold() << "." << endl;
		cout << "영업점 " << s3.getID() << " 판매개수 " << s3.getNumSold() << "." << endl;
		cout << "전체판매량 = " << s1.getTotalSold() << endl;
		cout << endl;

		cout << "초기화 하시려면 r 버튼을 추가 하시려면 a 를 종료하시려면 n버튼을 입력하시오. : ";
		cin >> c;
		if(c=='n'||c=='N')
			break;
	}
	system("pause");
	return 0;
}