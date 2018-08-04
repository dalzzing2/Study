//모든 라이브러리 작성하였습니다.

#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

// Creature 클래스
class Creature {
private:
	int type;		// 0: human, 1: Cyberdemon, 2: balrog , 3: elf
	int strength;	// 가할 수 있는 최대의 양
	int hitpoints;	// 버틸 수 있는 손상의 양

public:
	////////////////////추가///////////////////
	//죽은 캐릭터의 정보 저장/
	Creature *Die;
	//1번 가상함수로의 변환
	virtual int getDamage ();		//한 라운드의 전투에서 가해지는 종족들의 손상 값을 반환
	
	Creature ();			// 인간, 10 strength, 10 hit points
	Creature (int newType, int newStrength, int newHit);

	// 질문 : 왜 string이라고 하면 에러가 나오는지 알지 못함

	//void getSpecies ();
	string getSpecies ();	//종족의 종류를 반환

	//accessor/mutator
	int getstrength() {return strength;}
	void setstrength(int setstrength) { strength=setstrength; }

	int gethitpoints() {return hitpoints;}
	void sethitpoints(int sethitpoints) 
		{
			////////////////////추가///////////////////
			//sethitpoints 가 0 이하이면 예외처리 발생 Die에 현재 객체 저장
			Die = this;
			if(sethitpoints<=0)
				throw(1);
			hitpoints=sethitpoints; }
};

// 생성자 초기화 - 인간, 10 강인함, 10 피해
Creature::Creature() {
	type = 0;
	strength = 10;
	hitpoints = 10;
}

// 종족을 new type, strength, hit points 로 초기화
Creature::Creature(int newType, int newStrength, int newHit) {
	type = newType;
	strength = newStrength;
	hitpoints = newHit;
}
/*
// 종족의 종류
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

// 종족의 종류
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
	//모든 종족이 가하는 손상은 strength 내의 임의의 수
	damage = (rand()%strength) + 1;
	//printf("Creature의 현재 데미지는 %d입니다.\n", damage);
	return damage;
}

// Human 클래스 - Creature 상속
class Human: public Creature {
public:
	Human ();
	Human(int newType, int newStrength, int newHit);
};
Human::Human():Creature() {
}
Human::Human(int newType, int newStrength, int newHit):Creature (newType, newStrength, newHit) {
}

// Elf 클래스 - Creature 상속
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

	// Creature의 데미지
	damage = Creature::getDamage();
	// 10퍼센트의 기회 계산, 임의의 수 1~10 까지중 10이 나오면 데미지 2배
	chance = (rand()%10)+1;
	if (chance == 10) {
		printf("10퍼센트 확률에 당첨되었습니다. ");
		damage = damage * 2;
	}
	return damage;
}

// Demon 클래스 - Creature 상속
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
	// Creature의 데미지
	damage = Creature::getDamage();
	// 5퍼센트의 기회 계산, 임의의 수 1~20 까지중 20이 나오면 데미지 50 증가
	chance = (rand()%20)+1;
	if (chance == 20) {
		printf("5퍼센트 확률에 당첨되었습니다. ");
		damage = damage + 50;
	}
	return damage;
}

// CyberDemon 클래스 - Demon 상속
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
	// 정의되어 있지 않아 악마 데미지 그대로 반환
	return Demon::getDamage();
}

// Balrog 클래스 - Demon 상속
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
	// 2번 공격
	return Demon::getDamage() * 2;
}