#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	int chocolate, chocolate1=0;		//추가로 받을 수 있는 초콜릿(새로 바뀜) , 추가로 받을 수 있는 초콜릿(누적)
	int coupon, coupon1;				//처음 가지고 있는 쿠폰 개수, 쿠폰을 사용하고 남는 쿠폰의 개수

	cout << "Current coupon is : " ;
	cin >> coupon;					//현재 가지고 있는 쿠폰 개수
	coupon1=coupon;

	while(1){
		chocolate = coupon1/7;		//추가로 받을 수 있는 초콜릿 개수
		chocolate1 = chocolate1+chocolate;		//초콜릿 누적
		coupon1 = coupon1%7+chocolate;	//남은 쿠폰 개수

		if(coupon1>=7)			//쿠폰이 7개 이상이면 while문 반복수행 7개 이하일 경우 출력
			continue;
		else
			break;
	}
	cout << "총 먹은 초콜릿 개수 : " << coupon+chocolate1 << "\n남아있는 쿠폰 개수 : " << coupon1 << endl ;		//처음 쿠폰(초콜릿 개수)+누적초콜릿, 남은 쿠폰
	
	system("pause");
	return 0;
}