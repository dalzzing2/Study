#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
	int motherh, fatherh, childh;				//����Ű �ƺ�Ű ����Ű ����
	string sex;									//���� ������ ����

	cout << "*���������� �϶�� �Ͽ���(������ ����), 1inch = 2.54*" << endl << endl;
	cout << "����Ű : " ; cin >> motherh;
	cout << "�ƺ�Ű : " ; cin >> fatherh;

	cout << "������ ���� ����(m), ����(f) : ";
	cin >> sex;

	cout << endl;

	//���� Ű�� �ƺ� Ű�� �Է¹޾Ƽ� ��ġ�� ����� �� ��ġ���� �̸� ������
	cout << "������ġ : " << motherh/2.54 << "�ƺ���ġ : " << fatherh/2.54 << endl << endl;
	
	//������ ������ ������ ���m , ������ ��� f �� �� Ű ���� ���
	//������ Ű�� ��ġ������ ���Ǿ��� ������,
	//'1��Ʈ'�� '12��ġ' �̹Ƿ� ��Ʈ�� /12 �׸��� ������ ��ġ�� ����ϱ� ���� %12 ���

	if(sex=="m"){
		childh = ((motherh/2.54*(13.0/12.0))+fatherh/2.54)/2.0;
		cout << "������ Ű�� " << childh/12 << "��Ʈ(pete), " << childh%12 << "��ġ(inch) �Դϴ�." << endl;
	}
	else if(sex=="f"){
		childh = ((fatherh/2.54*(12.0/13.0))+motherh/2.54)/2.0;
		cout << "������ Ű�� " << childh/12 << "��Ʈ(pete), " << childh%12 << "��ġ(inch) �Դϴ�." << endl;	
	}
	
	system("pause");

	return 0;
}