// jdhgag1202@naver.com

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "2009253064_ch15_4.h"

using namespace std;
void battleArena(Creature &creature1, Creature &creature2);

int main()
{
	srand(time(NULL));
	int type1, type2;
	cout << "0 : Human, 1 : CyberDemon, 2 : Balrog, 3 : Elf " << endl << "������ �Է��ϼ��� " << endl << "ù ��° ���� : ";
	cin >> type1;
	cout << "�� ��° ���� : ";
	cin >> type2;

	//������ ���ݷ� HP�� �����ڰ� �����ϴ� ����/
	//����, �ִ���ݷ�, HP 
	Human Human(0, 13, 150);
	CyberDemon CyberDemon(1, 30, 40);
	Balrog Balrog(2, 20, 70);
	Elf Elf(3, 15,100);
	//battleArena �Լ� ȣ��
	if(type1==0 && type2==0)
		battleArena(Human, Human);
	if(type1==0 && type2==1)
		battleArena(Human, CyberDemon);
	if(type1==0 && type2==2)
		battleArena(Human, Balrog);
	if(type1==0 && type2==3)
		battleArena(Human, Elf);
	if(type1==1 && type2==0)
		battleArena(CyberDemon, Human);
	if(type1==1 && type2==1)
		battleArena(CyberDemon, CyberDemon);
	if(type1==1 && type2==2)
		battleArena(CyberDemon, Balrog);
	if(type1==1 && type2==3)
		battleArena(CyberDemon, Elf);
	if(type1==2 && type2==0)
		battleArena(Balrog, Human);
	if(type1==2 && type2==1)
		battleArena(Balrog, CyberDemon);
	if(type1==2 && type2==2)
		battleArena(Balrog, Balrog);
	if(type1==2 && type2==3)
		battleArena(Balrog, Elf);
	if(type1==3 && type2==0)
		battleArena(Elf, Human);
	if(type1==3 && type2==1)
		battleArena(Elf, CyberDemon);
	if(type1==3 && type2==2)
		battleArena(Elf, Balrog);
	if(type1==3 && type2==3)
		battleArena(Elf, Elf);
	system ("pause");
	return 0;
}


//battleArena �Լ� -> �Ű������� �ΰ��� ���̹�����c
void battleArena(Creature &creature1, Creature &creature2)
{
	cout << "�÷��̾��� �� hp�� " << endl << creature1.getSpecies() << " : " << creature1.gethitpoints() << "   " << creature2.getSpecies() << " : " << creature2.gethitpoints() << " �Դϴ� " << endl;
	int hit1 = creature1.gethitpoints();
	int hit2 = creature2.gethitpoints();

	

	//���� ĳ������ ������ ����
	Creature *Die;
	Die = new Creature;

	//while���� 1�� �ٲٰ� try/catch�� ���
	while (1)
	{
		int damage1 = creature1.getDamage();
		int damage2 = creature2.getDamage();
		hit1 = hit1 - damage2;

		cout << "�÷��̾� 1 (" << creature1.getSpecies() << ")�� ������ " << damage2 << "�� ���Խ��ϴ�. ���� ���� �Ǵ� " << hit1 << "�Դϴ�." << endl;

		//sethitpoints�� Ŭ�����Լ� ��� - Ŭ���� �Լ� ���ο��� ����ó�� ����
		try{
			creature1.sethitpoints(hit1);
		}catch(int e){
			//���� Ŭ������ ����
			Die = creature1.Die;
			//Die->getSpecies() = creature1.getSpecies();
			cout << Die->getSpecies() << "�� �����ϴ�." << endl;
			return ;
		}
		
		hit2 = hit2 - damage1;
		cout << "�÷��̾� 2 (" << creature2.getSpecies() << ")�� ������ " << damage1 << "�� ���Խ��ϴ�. ���� ���� �Ǵ� " << hit2 << "�Դϴ�." << endl;
		cout << endl;

		//�� try���� ����
		try{
			creature2.sethitpoints(hit2);
		}catch(int e){
			Die = creature2.Die;
			//Die->getSpecies() = creature2.getSpecies();
			cout << Die->getSpecies() << "�� �����ϴ�." << endl;
			return ;
		}
	}
}

//����ó�� ���Ѻκ�
/*
void battleArena(Creature &creature1, Creature &creature2)
{
   int hit1 = creature1.getHitpoints();
   int hit2 = creature2.getHitpoints();

   while ((hit1 > 0) && (hit2 > 0))
   {
		int damage1 = creature1.getDamage();
		int damage2 = creature2.getDamage();
		hit1 = hit1 - damage2;

		cout << "�÷��̾� 1 (" << creature1.getSpecies() << ")�� ������ " << damage2 << "�� ���Խ��ϴ�. ���� ���� �Ǵ� " << hit1 << "�Դϴ�." << endl;
		
		hit2 = hit2 - damage1;
		cout << "�÷��̾� 2 (" << creature2.getSpecies() << ")�� ������ " << damage1 << "�� ���Խ��ϴ�. ���� ���� �Ǵ� " << hit2 << "�Դϴ�." << endl;
		cout << endl;
}
   // Results of tournament
}
*/
