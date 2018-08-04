#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//////////////////////////////////////
////영문출력을 한글로 바꾸었습니다////
//////////////////////////////////////

class Money
{

public:

	Money();
	Money(double amount);
	Money(int theDollars, int theCents);
	Money(int theDollars);

	//연습문제 8 참조, 오버로딩
	friend bool operator<(const Money& amount1, const Money& amount2);
	friend bool operator<=(const Money& amount1, const Money& amount2);
	friend bool operator>(const Money& amount1, const Money& amount2);
	friend bool operator>=(const Money& amount1, const Money& amount2);
	friend bool operator!=(const Money& amount1, const Money& amount2);

	//호출 객체 : 돈의 금액을 퍼센티지로 반환
	const Money percent(int percentFigure) const;

	friend const Money operator +(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount1, const Money& amount2);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount);
	friend ostream& operator <<(ostream& outputStream, const Money& amount);
	friend istream& operator >>(istream& inputStream, Money& amount);

private:
	int dollars;
	int cents;
	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double number) const;
};

int main( )
{
	//현재 myAmount 는 10달러 9센트
	Money yourAmount, myAmount(10, 9);

	cout << "돈의 총 액수를 입력하세요(앞에 $를 써야합니다): ";
	cin >> yourAmount;

	cout << "퍼센테이지를 입력하세요: ";
	int percentAmount;
	cin >> percentAmount;
	
	cout << endl << "당신의 돈은 " << yourAmount << " 입니다." << endl;
	cout << "나의 돈은 " << myAmount << " 입니다." << endl << endl;



	if (yourAmount == myAmount)
		cout << "현재 우리는 같은 액수를 가지고 있습니다..\n";
	else
		cout << "우리중 한명이 더 부유합니다.\n";

	cout << endl;

	cout << percentAmount << "%가 적용된 당신의 돈은 "	<< yourAmount.percent(percentAmount) << "입니다." << endl;
	cout << percentAmount << "%가 적용된 나의 돈은 " << myAmount.percent(percentAmount) << "입니다." << endl;

	cout << endl;

	//ourAmount 는 당신돈+나의돈
	Money ourAmount = yourAmount + myAmount;
	cout << yourAmount << " + " << myAmount
		<< " = " << ourAmount << "." << endl;

	//diffAmount 는 당신돈-나의돈
	Money diffAmount = yourAmount - myAmount;
	cout << yourAmount << " - " << myAmount
		<< " = " << diffAmount << "." << endl << endl;

	system("pause");
	return 0;
}

//amount1 < amount2
bool operator<(const Money& amount1, const Money& amount2)
{
	//2의 달러가 더 크거나, 달러가 같을경우 2의 센트가 더 크거나
	return (amount1.dollars < amount2.dollars) || 
		((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents));
}

//amount1 <= amount2
bool operator<=(const Money& amount1, const Money& amount2)
{
	//2의 달러가 더 크거나, 달러가 같을경우 2의 센트가 더 크거나
	//둘이 같을경우
	return ((amount1.dollars < amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents))) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}

//amount1 > amount2
bool operator>(const Money& amount1, const Money& amount2)
{
	//1의 달러가 더 크거나, 달러가 같을경우 1의 센트가 더 크거나
	return (amount1.dollars > amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents));

}

//amount1 >= amount2
bool operator>=(const Money& amount1, const Money& amount2)
{
	//1의 달러가 더 크거나, 달러가 같을경우 1의 센트가 더 크거나
	//둘이 같을경우
	return ((amount1.dollars > amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents))) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}

//amount != amount2
bool operator!=(const Money& amount1, const Money& amount2)
{
	//1의 달러와 2의 달러가 같지 않거나, 같을경우 센트가 같지 않거나
	return ((amount1.dollars != amount2.dollars) ||
		(amount1.dollars == amount2.dollars) && (amount1.cents != amount2.cents));
}

const Money Money::percent(int pcnt) const
{   
	//dollars와 cents 는 호출한 객체의 dollar, cent

	int d = dollars * pcnt / 100;
	int c = dollars * pcnt % 100 + cents * pcnt / 100;

	//d : 달러부분 계산법 달러 * 퍼센트 / 100
	//c : 센트부분 계산법 달러 * 퍼센트 % 100    +    센트 * 퍼센트 / 100

	return Money(d, c);
}

// 두 돈의 합
const Money operator +(const Money& amount1, const Money& amount2)
{
	//센트로 변환
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;

	int sumAllCents = allCents1 + allCents2;
	//절대값
	int absAllCents = abs(sumAllCents);
	
	//다시 달러와 센트로 변환
	int finalDollars = absAllCents/100;
	int finalCents = absAllCents%100;

	//합이 음수였었으면, 다시 음수로 바꿔주기 위해 if 문 수행
	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

// 두 돈의 차 (합과 마찬가지) 매개변수가 두개
const Money operator -(const Money& amount1, const Money& amount2)
{
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;

	//빼주기
	int diffAllCents = allCents1 - allCents2;

	int absAllCents = abs(diffAllCents); 

	int finalDollars = absAllCents/100;
	int finalCents = absAllCents%100;

	if (diffAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

//두 돈이 같을 경우
bool operator ==(const Money& amount1, const Money& amount2)
{
	//맞으면 1, 틀리면 0 반환
	return
		((amount1.dollars == amount2.dollars)
		&& (amount1.cents == amount2.cents));
}

//매개변수가 한개, (앞에 마이너스를 붙여주기)
const Money operator -(const Money& amount)
{
	return Money(-amount.dollars, -amount.cents);
}

//각 멤버 변수 다음에 초기화 할 값을 지정함
//생성자 구현
Money::Money( ): dollars(0), cents(0)
{
}

//생성자 구현
Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount))
{
}

//생성자 구현
Money::Money(int theDollars) : dollars(theDollars), cents(0)
{
}

//Money 멤버함수
Money::Money(int theDollars, int theCents)
{
	dollars = theDollars;
	cents = theCents;
}

//double형을 int형으로 바꿔줌 - 센트 버림
int Money::dollarsPart(double amount) const
{
	return (int)amount;
}

//double형을 앞에 정수부분을 버림
int Money::centsPart(double amount) const
{
	//센트부분을 정수형으로 바꿔줌
	double doubleCents = amount*100;

	//부동소숫점 doubleCents의 절대값한 후, 버리고 나서 %100 계산
	int intCents = (round(fabs(doubleCents)))%100; 
	
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}

//버림
int Money::round(double number) const
{
	return (int)(floor(number + 0.5));
}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
	//절대값
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	
	//달러 혹은 센트가 음수이면
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';

	outputStream << absDollars;

	//센트의 자릿수
	if (absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;

	return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount)
{
	char dollarSign;
	inputStream >> dollarSign;
	if (dollarSign != '$')
	{
		cout << "입력이 돈이 아닙니다.\n";
		exit(1);
	}

	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);
	return inputStream;
}


