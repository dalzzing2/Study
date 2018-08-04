#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream inFile;
	ofstream outFile;

	string filename;

	cout << "Enter your file name : ";
	cin >> filename;

	inFile.open(filename);
	outFile.open(filename+".html");

	if(inFile.fail() == false && outFile.fail() == false){
		outFile << "<pre>" << endl;
		char ch;
		//inFile>>ch 공백무시, 아래는 공백적용
		while(inFile.get(ch)){
			switch(ch){
			case '<':
				outFile << "&lt;";
				break;
			case '>':
				outFile << "&gt;";
				break;
			default:
				outFile << ch;
			}
		}
		outFile << "</pre>" << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}