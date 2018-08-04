//CSV : Comma Separated Values


//���ڰ� 0�� ��� ������ ���� ���� ���̹Ƿ�, ������ 0�� ����
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	//��� ������ �𸣹Ƿ� vector
	vector<string> productNames;
	vector<int> productRatings;
	vector<int> ratingCounts;

	ifstream inFile("productratings.txt");
	
	if(inFile.fail() == false){
		string line;
		getline(inFile, line);

		istringstream iss(line);
		string name;

		//A���ڰ� name��, �ٽ� B���ڰ� name�� -----
		while(getline(iss, name, ',')){
			productNames.push_back(name);
			productRatings.push_back(0);//���� ���� 0��(�ʱ�ȭ)
			ratingCounts.push_back(0); //�ƹ��� ������ ������ ����
		}

		while(getline(inFile, line)){
			istringstream iss(line);
			string rating;

			int field=0;
			while(getline(iss, rating, ',')){
				istringstream iss(rating);
				int iRating;
				iss >> iRating;
				if(iRating==0){
				}
				else{
					productRatings[field] += iRating;	//����
					ratingCounts[field] += 1;	//�� ����
				}
				field++;
			}
		}
		int flagsettings = cout.flags();

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		//iomanip ���̺귯�� �ʿ� setw(5) 5����, setprecision(2) �Ҽ��� 2�ڸ�
		for(int i=0; i<productNames.size(); i++){
			cout << setw(5) << productNames[i] << " : ";
			cout << setw(5) << productRatings[i] << " : " ;
			cout << setw(5) << ratingCounts[i] << " " ;
			cout << setw(5) << setprecision(2) << static_cast <double>(productRatings[i])/ratingCounts[i] << endl;
		}

		cout.flags(flagsettings);
	}
	inFile.close();
	return 0;
}