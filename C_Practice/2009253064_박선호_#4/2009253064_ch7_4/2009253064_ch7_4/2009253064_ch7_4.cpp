#include <iostream>
#include <cstdlib>

using namespace std;

class HotDogStand{
public:
	HotDogStand(int id, int hds);	//������
	void justSold();				//�ֵ����� �� ����
	int getNumSold();				//�ȸ� ���� �޴� �Լ�
	int getID();					//���̵� �޴� �Լ�
	int getTotalSold();				//��ü �ȸ����� ��ȯ�ϴ� �Լ�
	void check(char c);				//�ʱ�ȭ �Լ�
private:
	int idNum;				//������
	int hotDogsSold;		//�ȸ�����
	static int totalSold;	//�Ϸ絿�� ��ü �ȸ� ��
};

//�ʱ� ��ü �ȸ� �� 0 ���� �ʱ�ȭ
int HotDogStand::totalSold=0;

//��������, ������ �Ű������� �Ҵ�
HotDogStand::HotDogStand(int id, int hds)
{
	idNum = id;
	hotDogsSold = hds;
	return;
}

//�� �������� �ȸ��ſ� ����, �ȸ� ����(�������� ���� �ٸ�)�� ��ü �ȸ� ��(�������� ���� static) ����
void HotDogStand::justSold()
{
	hotDogsSold++;
	totalSold++;
	return;
}

//�ȸ����� ��ȯ
int HotDogStand::getNumSold()
{
	return hotDogsSold;
}

//������ �̸� ��ȯ
int HotDogStand::getID()
{
	return idNum;
}

//��ü �ȸ��� ��ȯ
int HotDogStand::getTotalSold()
{
	return totalSold;
}
//�ʱ�ȭ �Լ�
void HotDogStand::check(char c)
{
	hotDogsSold=0;
	totalSold=0;
	return;
}
int main()
{
	//������ 3��
	HotDogStand s1(1, 0), s2(2, 0), s3(3, 0);
	char c='r';	//�ʱ� ���� r �� ����

	//r �Ǵ� R�� ����, a �Ǵ� A�� �߰�
	while(c=='r'||c=='R'||c=='a'||c=='A'){
		//r�̰ų� R�̸� check�Լ� ȣ��(�ʱ�ȭ)
		if(c=='r'||c=='R'){
			s1.check(c);
			s2.check(c);
			s3.check(c);
		}

		int i;
		cout << "ù��° �������� �Ǹ� ������ �Է��Ͻÿ�. : ";
		cin >> i;
		int j;
		cout << "�ι�° �������� �Ǹ� ������ �Է��Ͻÿ�. : ";
		cin >> j;
		int k;
		cout << "����° �������� �Ǹ� ������ �Է��Ͻÿ�. : ";
		cin >> k;

		//(�ǸŰ����� ���� �Լ� ȣ��)
		for(i; i>0; i--)
			s1.justSold();
		for(j; j>0; j--)
			s2.justSold();
		for(k; k>0; k--)
			s3.justSold();

		//(���)
		cout << "������ " << s1.getID() << " �ǸŰ��� " << s1.getNumSold() << "." << endl;
		cout << "������ " << s2.getID() << " �ǸŰ��� " << s2.getNumSold() << "." << endl;
		cout << "������ " << s3.getID() << " �ǸŰ��� " << s3.getNumSold() << "." << endl;
		cout << "��ü�Ǹŷ� = " << s1.getTotalSold() << endl;
		cout << endl;

		cout << "�ʱ�ȭ �Ͻ÷��� r ��ư�� �߰� �Ͻ÷��� a �� �����Ͻ÷��� n��ư�� �Է��Ͻÿ�. : ";
		cin >> c;
		if(c=='n'||c=='N')
			break;
	}
	system("pause");
	return 0;
}