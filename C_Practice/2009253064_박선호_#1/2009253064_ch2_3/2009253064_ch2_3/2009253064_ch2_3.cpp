#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	int chocolate, chocolate1=0;		//�߰��� ���� �� �ִ� ���ݸ�(���� �ٲ�) , �߰��� ���� �� �ִ� ���ݸ�(����)
	int coupon, coupon1;				//ó�� ������ �ִ� ���� ����, ������ ����ϰ� ���� ������ ����

	cout << "Current coupon is : " ;
	cin >> coupon;					//���� ������ �ִ� ���� ����
	coupon1=coupon;

	while(1){
		chocolate = coupon1/7;		//�߰��� ���� �� �ִ� ���ݸ� ����
		chocolate1 = chocolate1+chocolate;		//���ݸ� ����
		coupon1 = coupon1%7+chocolate;	//���� ���� ����

		if(coupon1>=7)			//������ 7�� �̻��̸� while�� �ݺ����� 7�� ������ ��� ���
			continue;
		else
			break;
	}
	cout << "�� ���� ���ݸ� ���� : " << coupon+chocolate1 << "\n�����ִ� ���� ���� : " << coupon1 << endl ;		//ó�� ����(���ݸ� ����)+�������ݸ�, ���� ����
	
	system("pause");
	return 0;
}