#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
	string text;
	ifstream stream;		//fstream ���̺귯���� Ŭ��

	stream.open("Cplus.txt");		//Cplus��� ������ ����

	while(stream>>text){		//stream�� text�� ����������
		if(text=="hate")		///text�� hate��� �ܾ��ϰ��
			text = "love";		//love �� �ٲ��ش�.
		cout << text << " " ;	//text ���
	}
	cout << endl;

	stream.close();			//������ �ݴ´�.

	system("pause");
	return 0;
}