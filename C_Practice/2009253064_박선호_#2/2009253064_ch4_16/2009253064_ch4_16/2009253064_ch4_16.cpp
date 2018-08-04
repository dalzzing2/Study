#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int getHighScore(string name, int value);

static int store_value=0;
string store_name;				//store_value 값이 변경됨을 저장해줘야 하기 때문에 static 으로 선언, string은 함께 변경용 문자열

int main()
{
	int value;
	string name;

	ifstream stream;
	stream.open("Score.txt");		//Score 라는 파일을 읽어온다.

	while(stream>>name>>value){		//파일이 끝날때까지
		cout << name << " " << value ;	//파일의 내용 출력
		getHighScore(name, value);		//getHighScore 함수에 이름과 값의 매개변수 전달
		cout << endl;
	}

	cout << endl << endl << "Result : " << store_name << ", " << store_value << endl;		//최종 결과 출력
	stream.close();		//Score 라는 파일을 닫는다.
	system("pause");
	return 0;
}

int getHighScore(string name, int value)
{
	if(value > store_value){			//전달되어 온 값이 저장되어 있는 값보다 크다면 (초기 저장값은 0)
		store_value=value;				//전달되어 온 값을 저장되어 있는 값에서 변경
		store_name=name;				//마찬가지로 이름도 함께 변경
		cout << "       Curret Best Score : " << store_name << " , " << store_value; //변경되었을때 변경되었음을 출력해줌
	}
	return 0;
}