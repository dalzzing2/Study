// jdhgag1202@naver.com

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "2009253064_ch14_9.h"

using namespace std;

int main()
{
	srand(time(NULL));
	char choice='Y';
	int type, strength, hitpoints;
	cout << "0 : Human, 1 : CyberDemon, 2 : Balrog, 3 : Elf\n";
	cout << "종족을 입력하여 주세요 : ";
	cin >> type;

	switch(type){
	case 0:
		{
			cout << "\n\nHuman를 선택하셨습니다. 가할 수 있는 양과 버틸 수 있는 양을 입력해주세요.\n";
			cout << "가할 수 있는 양 : ";
			cin >> strength;
			cout << "버틸수 있는 양 : ";
			cin >> hitpoints;
			Human Human(type, strength, hitpoints);
			
			//access/mutator
			Human.setstrength(strength);
			int result_strength = Human.getstrength();
			cout << result_strength <<  " of strength accessor/mutator\n";

			Human.sethitpoints(hitpoints);
			int result_hitpoints = Human.gethitpoints();
			cout << result_hitpoints <<  " of hitpoints accessor/mutator\n";

			while(choice=='Y'||choice=='y'){
				Human.getSpecies();
				cout  << "현재 데미지는 " << Human.getDamage() << "입니다" << endl;
				cout << "계속하시겠습니까? (Y/N) : ";
				cin >> choice;
			}
			break;
		}
	case 1:
		{
			cout << "\n\nCyberDemon를 선택하셨습니다. 가할 수 있는 양과 버틸 수 있는 양을 입력해주세요.\n";
			cout << "가할 수 있는 양 : ";
			cin >> strength;
			cout << "버틸수 있는 양 : ";
			cin >> hitpoints;
			CyberDemon CyberDemon(type, strength, hitpoints);

			//access/mutator
			CyberDemon.setstrength(strength);
			int result_strength = CyberDemon.getstrength();
			cout << result_strength <<  " of strength accessor/mutator\n";

			CyberDemon.sethitpoints(hitpoints);
			int result_hitpoints = CyberDemon.gethitpoints();
			cout << result_hitpoints <<  " of hitpoints accessor/mutator\n";

			while(choice=='Y'||choice=='y'){
				CyberDemon.getSpecies();
				cout  << "현재 데미지는 " << CyberDemon.getDamage() << "입니다" << endl;
				cout << "계속하시겠습니까? (Y/N) : ";
				cin >> choice;
			}
			break;
		}
	case 2:
		{
			cout << "\n\nBalrog를 선택하셨습니다. 가할 수 있는 양과 버틸 수 있는 양을 입력해주세요.\n";
			cout << "가할 수 있는 양 : ";
			cin >> strength;
			cout << "버틸수 있는 양 : ";
			cin >> hitpoints;
			Balrog Balrog(type, strength, hitpoints);

			//access/mutator
			Balrog.setstrength(strength);
			int result_strength = Balrog.getstrength();
			cout << result_strength <<  " of strength accessor/mutator\n";

			Balrog.sethitpoints(hitpoints);
			int result_hitpoints = Balrog.gethitpoints();
			cout << result_hitpoints <<  " of hitpoints accessor/mutator\n";

			while(choice=='Y'||choice=='y'){
				Balrog.getSpecies();
				cout << "현재 데미지는 " << Balrog.getDamage() << "입니다" << endl;
				cout << "계속하시겠습니까? (Y/N) : ";
				cin >> choice;
			}
			break;
		}
	case 3:
		{
			cout << "\n\nElf를 선택하셨습니다. 가할 수 있는 양과 버틸 수 있는 양을 입력해주세요.\n";
			cout << "가할 수 있는 양 : ";
			cin >> strength;
			cout << "버틸수 있는 양 : ";
			cin >> hitpoints;
			Elf Elf(type, strength, hitpoints);

			//access/mutator
			Elf.setstrength(strength);
			int result_strength = Elf.getstrength();
			cout << result_strength <<  " of strength accessor/mutator\n";

			Elf.sethitpoints(hitpoints);
			int result_hitpoints = Elf.gethitpoints();
			cout << result_hitpoints <<  " of hitpoints accessor/mutator\n";

			while(choice=='Y'||choice=='y'){
				Elf.getSpecies();
				cout  << "현재 데미지는 " << Elf.getDamage() << "입니다" << endl;
				cout << "계속하시겠습니까? (Y/N) : ";
				cin >> choice;
			}
			break;
		}
	}
	system ("pause");
	return 0;
}

//cpp에서도 동일한 에러가 뜹니다.
/*
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
*/