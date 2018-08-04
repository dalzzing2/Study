//CSV : Comma Separated Values


//숫자가 0일 경우 별점을 주지 않은 것이므로, 나눌때 0은 제외
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	//몇개가 들어올지 모르므로 vector
	vector<string> productNames;
	vector<int> productRatings;
	vector<int> ratingCounts;

	ifstream inFile("productratings.txt");
	
	if(inFile.fail() == false){
		string line;
		getline(inFile, line);

		istringstream iss(line);
		string name;

		//A문자가 name에, 다시 B문자가 name에 -----
		while(getline(iss, name, ',')){
			productNames.push_back(name);
			productRatings.push_back(0);//현재 별점 0점(초기화)
			ratingCounts.push_back(0); //아무도 별점을 내리지 않음
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
					productRatings[field] += iRating;	//별점
					ratingCounts[field] += 1;	//준 갯수
				}
				field++;
			}
		}
		int flagsettings = cout.flags();

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		//iomanip 라이브러리 필요 setw(5) 5공간, setprecision(2) 소수점 2자리
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