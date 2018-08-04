#include <iostream>
#include <cassert>

using namespace std;

//�Լ��� �����ε� ����, �� �Լ��� ������ 2���� �Ű�������, �Ʒ� �Լ��� �Ǽ��� 1���� �Ű������� �޴� �Լ��� ����
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
		cout << "���� 1���� 1��, ���� 2���� 2���� �����ּ���. : " ;
		cin >> sel;		//�Ű������� �Է¹ް� �����ϴ� ����
		if(sel==1){		//�ð��� �Է¹޴� if�� (������ �� ��) - ���Լ��� ���� ��
			cout << "�а� �ʸ� ���������� �Է��Ͽ� �ּ���.(��) 3�� 15�� -> 3 15, 5�� -> 5 00   " << endl;
			cout << ": " ;
			cin >> min >> sec;
		}
		else if(sel==2){	//kph�� �Է¹޴� if�� (�Ǽ��� kph) - �Ʒ��Լ��� ���Ե�
			cout << "Kph�� ������(�Ǽ�)�� �Է��Ͽ� �ּ���. : " ;
			cin >> kph;
		}
		else		//���õ��� ������� ������ ����ϰ� ���α׷��� �����ϰ� �ȴ�.
			assert(0);

		// �Ű������� ���� ���� �Լ��� �����Ǵ� �κ�, ���� �Լ��� ���� ��ȯ�Ǵ� ���� �ٸ��� ������, kph(����1��)�� mph(����2��)���� ���� ����
		Kph = ConvertToKPH(min, sec);
		Mph = ConvertToKPH(kph);

		//���� ���õȰͿ� ���� ���)
		if(sel==1)
			cout << "1���� �����Ͽ����ϴ�. Kph �� " << Kph << " �Դϴ�. " << endl;
		else if(sel==2)
			cout << "2���� �����Ͽ����ϴ�. Mph �� " << Mph << " �Դϴ�. " << endl;

		//����̺� �˻�
		cout << "����Ͻðڽ��ϱ�.(Y,y)" << endl;
		cin >> ans;
	}while(ans=='y'||ans=='Y');

	return 0;
}

double ConvertToKPH(int min, int sec)
{
	double kph;
	// 1kph�� 1�ð��� 1km �� ���ٴ� �ǹ�, �� 60�п� 1km. 3600�ʿ� 1km
	double pmin, psec;

	pmin = (double)min/60;
	psec = (double)sec/3600;

	kph = pmin+psec;

	return kph;
}

double ConvertToKPH(double kph)
{
	// 1.61kph �� 1mph
	kph = (double)kph/1.61;
	return kph;
}