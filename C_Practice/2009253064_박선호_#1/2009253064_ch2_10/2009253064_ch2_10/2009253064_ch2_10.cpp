#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
	string text;
	ifstream stream;		//fstream 라이브러리의 클라스

	stream.open("Cplus.txt");		//Cplus라는 파일을 연다

	while(stream>>text){		//stream이 text가 끝날때까지
		if(text=="hate")		///text가 hate라는 단어일경우
			text = "love";		//love 로 바꿔준다.
		cout << text << " " ;	//text 출력
	}
	cout << endl;

	stream.close();			//파일을 닫는다.

	system("pause");
	return 0;
}