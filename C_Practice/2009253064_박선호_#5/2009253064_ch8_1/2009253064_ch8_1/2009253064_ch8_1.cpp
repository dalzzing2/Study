#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//////////////////////////////////////
////��������� �ѱ۷� �ٲپ����ϴ�////
//////////////////////////////////////

class Money
{

public:

	Money();
	Money(double amount);
	Money(int theDollars, int theCents);
	Money(int theDollars);

	//�������� 8 ����, �����ε�
	friend bool operator<(const Money& amount1, const Money& amount2);
	friend bool operator<=(const Money& amount1, const Money& amount2);
	friend bool operator>(const Money& amount1, const Money& amount2);
	friend bool operator>=(const Money& amount1, const Money& amount2);
	friend bool operator!=(const Money& amount1, const Money& amount2);

	//ȣ�� ��ü : ���� �ݾ��� �ۼ�Ƽ���� ��ȯ
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
	//���� myAmount �� 10�޷� 9��Ʈ
	Money yourAmount, myAmount(10, 9);

	cout << "���� �� �׼��� �Է��ϼ���(�տ� $�� ����մϴ�): ";
	cin >> yourAmount;

	cout << "�ۼ��������� �Է��ϼ���: ";
	int percentAmount;
	cin >> percentAmount;
	
	cout << endl << "����� ���� " << yourAmount << " �Դϴ�." << endl;
	cout << "���� ���� " << myAmount << " �Դϴ�." << endl << endl;



	if (yourAmount == myAmount)
		cout << "���� �츮�� ���� �׼��� ������ �ֽ��ϴ�..\n";
	else
		cout << "�츮�� �Ѹ��� �� �����մϴ�.\n";

	cout << endl;

	cout << percentAmount << "%�� ����� ����� ���� "	<< yourAmount.percent(percentAmount) << "�Դϴ�." << endl;
	cout << percentAmount << "%�� ����� ���� ���� " << myAmount.percent(percentAmount) << "�Դϴ�." << endl;

	cout << endl;

	//ourAmount �� ��ŵ�+���ǵ�
	Money ourAmount = yourAmount + myAmount;
	cout << yourAmount << " + " << myAmount
		<< " = " << ourAmount << "." << endl;

	//diffAmount �� ��ŵ�-���ǵ�
	Money diffAmount = yourAmount - myAmount;
	cout << yourAmount << " - " << myAmount
		<< " = " << diffAmount << "." << endl << endl;

	system("pause");
	return 0;
}

//amount1 < amount2
bool operator<(const Money& amount1, const Money& amount2)
{
	//2�� �޷��� �� ũ�ų�, �޷��� ������� 2�� ��Ʈ�� �� ũ�ų�
	return (amount1.dollars < amount2.dollars) || 
		((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents));
}

//amount1 <= amount2
bool operator<=(const Money& amount1, const Money& amount2)
{
	//2�� �޷��� �� ũ�ų�, �޷��� ������� 2�� ��Ʈ�� �� ũ�ų�
	//���� �������
	return ((amount1.dollars < amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents))) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}

//amount1 > amount2
bool operator>(const Money& amount1, const Money& amount2)
{
	//1�� �޷��� �� ũ�ų�, �޷��� ������� 1�� ��Ʈ�� �� ũ�ų�
	return (amount1.dollars > amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents));

}

//amount1 >= amount2
bool operator>=(const Money& amount1, const Money& amount2)
{
	//1�� �޷��� �� ũ�ų�, �޷��� ������� 1�� ��Ʈ�� �� ũ�ų�
	//���� �������
	return ((amount1.dollars > amount2.dollars) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents))) ||
		((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}

//amount != amount2
bool operator!=(const Money& amount1, const Money& amount2)
{
	//1�� �޷��� 2�� �޷��� ���� �ʰų�, ������� ��Ʈ�� ���� �ʰų�
	return ((amount1.dollars != amount2.dollars) ||
		(amount1.dollars == amount2.dollars) && (amount1.cents != amount2.cents));
}

const Money Money::percent(int pcnt) const
{   
	//dollars�� cents �� ȣ���� ��ü�� dollar, cent

	int d = dollars * pcnt / 100;
	int c = dollars * pcnt % 100 + cents * pcnt / 100;

	//d : �޷��κ� ���� �޷� * �ۼ�Ʈ / 100
	//c : ��Ʈ�κ� ���� �޷� * �ۼ�Ʈ % 100    +    ��Ʈ * �ۼ�Ʈ / 100

	return Money(d, c);
}

// �� ���� ��
const Money operator +(const Money& amount1, const Money& amount2)
{
	//��Ʈ�� ��ȯ
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;

	int sumAllCents = allCents1 + allCents2;
	//���밪
	int absAllCents = abs(sumAllCents);
	
	//�ٽ� �޷��� ��Ʈ�� ��ȯ
	int finalDollars = absAllCents/100;
	int finalCents = absAllCents%100;

	//���� ������������, �ٽ� ������ �ٲ��ֱ� ���� if �� ����
	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

// �� ���� �� (�հ� ��������) �Ű������� �ΰ�
const Money operator -(const Money& amount1, const Money& amount2)
{
	int allCents1 = amount1.cents + amount1.dollars*100;
	int allCents2 = amount2.cents + amount2.dollars*100;

	//���ֱ�
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

//�� ���� ���� ���
bool operator ==(const Money& amount1, const Money& amount2)
{
	//������ 1, Ʋ���� 0 ��ȯ
	return
		((amount1.dollars == amount2.dollars)
		&& (amount1.cents == amount2.cents));
}

//�Ű������� �Ѱ�, (�տ� ���̳ʽ��� �ٿ��ֱ�)
const Money operator -(const Money& amount)
{
	return Money(-amount.dollars, -amount.cents);
}

//�� ��� ���� ������ �ʱ�ȭ �� ���� ������
//������ ����
Money::Money( ): dollars(0), cents(0)
{
}

//������ ����
Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount))
{
}

//������ ����
Money::Money(int theDollars) : dollars(theDollars), cents(0)
{
}

//Money ����Լ�
Money::Money(int theDollars, int theCents)
{
	dollars = theDollars;
	cents = theCents;
}

//double���� int������ �ٲ��� - ��Ʈ ����
int Money::dollarsPart(double amount) const
{
	return (int)amount;
}

//double���� �տ� �����κ��� ����
int Money::centsPart(double amount) const
{
	//��Ʈ�κ��� ���������� �ٲ���
	double doubleCents = amount*100;

	//�ε��Ҽ��� doubleCents�� ���밪�� ��, ������ ���� %100 ���
	int intCents = (round(fabs(doubleCents)))%100; 
	
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}

//����
int Money::round(double number) const
{
	return (int)(floor(number + 0.5));
}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
	//���밪
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	
	//�޷� Ȥ�� ��Ʈ�� �����̸�
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';

	outputStream << absDollars;

	//��Ʈ�� �ڸ���
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
		cout << "�Է��� ���� �ƴմϴ�.\n";
		exit(1);
	}

	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);
	return inputStream;
}


