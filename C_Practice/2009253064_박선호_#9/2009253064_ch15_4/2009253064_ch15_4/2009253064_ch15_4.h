//��� ���̺귯�� �ۼ��Ͽ����ϴ�.

#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

// Creature Ŭ����
class Creature {
private:
	int type;		// 0: human, 1: Cyberdemon, 2: balrog , 3: elf
	int strength;	// ���� �� �ִ� �ִ��� ��
	int hitpoints;	// ��ƿ �� �ִ� �ջ��� ��

public:
	////////////////////�߰�///////////////////
	//���� ĳ������ ���� ����/
	Creature *Die;
	//1�� �����Լ����� ��ȯ
	virtual int getDamage ();		//�� ������ �������� �������� �������� �ջ� ���� ��ȯ
	
	Creature ();			// �ΰ�, 10 strength, 10 hit points
	Creature (int newType, int newStrength, int newHit);

	// ���� : �� string�̶�� �ϸ� ������ �������� ���� ����

	//void getSpecies ();
	string getSpecies ();	//������ ������ ��ȯ

	//accessor/mutator
	int getstrength() {return strength;}
	void setstrength(int setstrength) { strength=setstrength; }

	int gethitpoints() {return hitpoints;}
	void sethitpoints(int sethitpoints) 
		{
			////////////////////�߰�///////////////////
			//sethitpoints �� 0 �����̸� ����ó�� �߻� Die�� ���� ��ü ����
			Die = this;
			if(sethitpoints<=0)
				throw(1);
			hitpoints=sethitpoints; }
};

// ������ �ʱ�ȭ - �ΰ�, 10 ������, 10 ����
Creature::Creature() {
	type = 0;
	strength = 10;
	hitpoints = 10;
}

// ������ new type, strength, hit points �� �ʱ�ȭ
Creature::Creature(int newType, int newStrength, int newHit) {
	type = newType;
	strength = newStrength;
	hitpoints = newHit;
}
/*
// ������ ����
void Creature::getSpecies () {
	switch (type)
	{
	case 0 : 
		printf("Human : ");
		break;
	case 1 : 
		printf("Cyberdemon : ");
		break;
	case 2 : 
		printf("Balrog : ");
		break;
	case 3 : 
		printf("Elf : ");
		break;
	}
}
*/

// ������ ����
string Creature::getSpecies () {
	switch (type)
	{
	case 0 : return "Human";
	case 1 : return "Cyberdemon";
	case 2 : return "Balrog";
	case 3 : return "Elf";
	}
	return "Unknown";
}

int Creature::getDamage() {
	int damage;
	//��� ������ ���ϴ� �ջ��� strength ���� ������ ��
	damage = (rand()%strength) + 1;
	//printf("Creature�� ���� �������� %d�Դϴ�.\n", damage);
	return damage;
}

// Human Ŭ���� - Creature ���
class Human: public Creature {
public:
	Human ();
	Human(int newType, int newStrength, int newHit);
};
Human::Human():Creature() {
}
Human::Human(int newType, int newStrength, int newHit):Creature (newType, newStrength, newHit) {
}

// Elf Ŭ���� - Creature ���
class Elf: public Creature {
public:
	Elf();
	Elf(int newType, int newStrength, int newHit);
	int getDamage ();
};
Elf::Elf():Creature() {
}
Elf::Elf(int newType, int newStrength, int newHit):Creature (newType, newStrength, newHit) {
}
int Elf::getDamage() {
	int chance, damage;

	// Creature�� ������
	damage = Creature::getDamage();
	// 10�ۼ�Ʈ�� ��ȸ ���, ������ �� 1~10 ������ 10�� ������ ������ 2��
	chance = (rand()%10)+1;
	if (chance == 10) {
		printf("10�ۼ�Ʈ Ȯ���� ��÷�Ǿ����ϴ�. ");
		damage = damage * 2;
	}
	return damage;
}

// Demon Ŭ���� - Creature ���
class Demon: public Creature {
protected:
	int getDamage ();
public:
	Demon();
	Demon(int newType, int newStrength, int newHit);
};
Demon::Demon():Creature() {
}
Demon::Demon(int newType, int newStrength, int newHit):Creature (newType, newStrength, newHit) {
}
int Demon::getDamage() {
	int chance, damage;
	// Creature�� ������
	damage = Creature::getDamage();
	// 5�ۼ�Ʈ�� ��ȸ ���, ������ �� 1~20 ������ 20�� ������ ������ 50 ����
	chance = (rand()%20)+1;
	if (chance == 20) {
		printf("5�ۼ�Ʈ Ȯ���� ��÷�Ǿ����ϴ�. ");
		damage = damage + 50;
	}
	return damage;
}

// CyberDemon Ŭ���� - Demon ���
class CyberDemon: public Demon {
public:
	CyberDemon();
	CyberDemon(int newType, int newStrength, int newHit);
	int getDamage ();
};
CyberDemon::CyberDemon():Demon() {
}
CyberDemon::CyberDemon(int newType, int newStrength, int newHit):Demon (newType, newStrength, newHit) {
}
int CyberDemon::getDamage() {
	// ���ǵǾ� ���� �ʾ� �Ǹ� ������ �״�� ��ȯ
	return Demon::getDamage();
}

// Balrog Ŭ���� - Demon ���
class Balrog: public Demon {
public:
	Balrog();
	Balrog(int newType, int newStrength, int newHit);
	int getDamage ();
};
Balrog::Balrog():Demon() {
}
Balrog::Balrog(int newType, int newStrength, int newHit):Demon (newType, newStrength, newHit) {
}
int Balrog::getDamage() {
	// 2�� ����
	return Demon::getDamage() * 2;
}