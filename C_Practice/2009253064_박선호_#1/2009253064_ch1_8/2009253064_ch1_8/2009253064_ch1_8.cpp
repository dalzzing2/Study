#include <iostream>
using namespace std;

int main()
{
	int n;
	double guess;
	double r;			//n�� int ����, guess�� r�� ���� double �� ����

	cout << "Press one n : ";	// ������ ���� n �� �� �Է�	
	cin >> n;

	guess = (double)n/2;		// n/2 �� ������ ���� ������ ������ �� ��ȯ�� ���� double�� �ٲ���

	for(int i=1; i<=5; i++){
		r = n / guess;			
		guess = (guess+r)/2;		//������ ��� �� �䱸 ����

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);			//�Ҽ��� 2��° �ڸ����� ������ �ϱ� ���� ���� ����
		cout << "*i ��°*" << endl;
		cout << "guess : " << guess << " , r : " << r << endl; //���� �������� guess �� r �� �� ����
	}
	return 0;
}