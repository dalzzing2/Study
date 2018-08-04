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
	cout << "0 : Human, 1 : CyberDemon, 2 : Balrog, 3 : Elf " << endl << "종족을 입력하세요 " << endl << "첫 번째 종족 : ";
	cin >> type1;
	cout << "두 번째 종족 : ";
	cin >> type2;

	//종족의 공격력 HP는 개발자가 지정하는 형식/
	//종족, 최대공격력, HP 
	Human Human(0, 13, 150);
	CyberDemon CyberDemon(1, 30, 40);
	Balrog Balrog(2, 20, 70);
	Elf Elf(3, 15,100);
	//battleArena 함수 호출
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


//battleArena 함수 -> 매개변수로 인간가 사이버데몬c
void battleArena(Creature &creature1, Creature &creature2)
{
	cout << "플레이어의 총 hp는 " << endl << creature1.getSpecies() << " : " << creature1.gethitpoints() << "   " << creature2.getSpecies() << " : " << creature2.gethitpoints() << " 입니다 " << endl;
	int hit1 = creature1.gethitpoints();
	int hit2 = creature2.gethitpoints();

	

	//죽은 캐릭터의 포인터 저장
	Creature *Die;
	Die = new Creature;

	//while문을 1로 바꾸고 try/catch문 사용
	while (1)
	{
		int damage1 = creature1.getDamage();
		int damage2 = creature2.getDamage();
		hit1 = hit1 - damage2;

		cout << "플레이어 1 (" << creature1.getSpecies() << ")에 데미지 " << damage2 << "가 들어왔습니다. 현재 남은 피는 " << hit1 << "입니다." << endl;

		//sethitpoints의 클래스함수 사용 - 클래스 함수 내부에는 예외처리 존재
		try{
			creature1.sethitpoints(hit1);
		}catch(int e){
			//현재 클래스를 저장
			Die = creature1.Die;
			//Die->getSpecies() = creature1.getSpecies();
			cout << Die->getSpecies() << "가 졌습니다." << endl;
			return ;
		}
		
		hit2 = hit2 - damage1;
		cout << "플레이어 2 (" << creature2.getSpecies() << ")에 데미지 " << damage1 << "가 들어왔습니다. 현재 남은 피는 " << hit2 << "입니다." << endl;
		cout << endl;

		//위 try문과 동일
		try{
			creature2.sethitpoints(hit2);
		}catch(int e){
			Die = creature2.Die;
			//Die->getSpecies() = creature2.getSpecies();
			cout << Die->getSpecies() << "가 졌습니다." << endl;
			return ;
		}
	}
}

//예외처리 안한부분
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

		cout << "플레이어 1 (" << creature1.getSpecies() << ")에 데미지 " << damage2 << "가 들어왔습니다. 현재 남은 피는 " << hit1 << "입니다." << endl;
		
		hit2 = hit2 - damage1;
		cout << "플레이어 2 (" << creature2.getSpecies() << ")에 데미지 " << damage1 << "가 들어왔습니다. 현재 남은 피는 " << hit2 << "입니다." << endl;
		cout << endl;
}
   // Results of tournament
}
*/
