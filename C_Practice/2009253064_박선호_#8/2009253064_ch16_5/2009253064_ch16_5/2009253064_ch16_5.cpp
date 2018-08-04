//디스플레이 5.6 에서 template <class T> 의 변환

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int DECLARED_SIZE = 20;

template <class S, class T>
class set{
public :
	set();
	void fillArray(S a[], T size, T& numberUsed);
	int search(const S a[], T numberUsed, S targer);
	~set();
};

int main()
{
	set<int, int> t;
	set<double, int> d;
	set<char, int> c;

	int listSize;
	// 검색할 target set의 형에 맞게 타겟 찾아야하기 때문에 형별로 3개 선언
	int target1;
	double target2;
	char target3;

	char sel;
	// 배열또한 같은이유
	int arr1[DECLARED_SIZE];
	double arr2[DECLARED_SIZE];
	char arr3[DECLARED_SIZE];

	cout << "정수 : i, 실수 : d, 문자 : c 를 입력하세요. : ";
	cin >> sel;
	//정수 실수 문자 에 따라서 호출 선택
	if(sel=='i'){
		//매개변수 기능
		//첫 번째 : 배열이름, 두 번째 : 배열최대크기, 세 번째 : 입력한 배열의 크기 동적할당
		t.fillArray(arr1, DECLARED_SIZE, listSize);
	}
	else if(sel=='d'){
		d.fillArray(arr2, DECLARED_SIZE, listSize);
	}
	else if(sel=='c'){
		cout << "문자는 z로 종료합니다." << endl;
		c.fillArray(arr3, DECLARED_SIZE, listSize);
	}
	char ans;
	int result;
	do
	{
		cout << "Enter a number to search for : ";


		//배열값 찾기
		//target 찾아야 할 대상 값
		//역시 마찬가지로 target
		if(sel=='i'){
			cin >> target1;
			int result = t.search(arr1, listSize, target1);

			if(result==-1)
				cout << target1 << " is not on the list : " << result << endl;
			else
				cout << target1 << " is stored in array position " << result << endl
				<< "(Remember: The first position is 0.)\n";
		}
		else if(sel=='d'){
			cin >> target2;
			int result = d.search(arr2, listSize, target2);

			if(result==-1)
				cout << target2 << " is not on the list : " << result << endl;
			else
				cout << target2 << " is stored in array position " << result << endl
				<< "(Remember: The first position is 0.)\n";
		}
		else if(sel=='c'){
			cin >> target3;
			
			int result = c.search(arr3, listSize, target3);

			if(result==-1)
				cout << target3 << " is not on the list : " << result << endl;
			else
				cout << target3 << " is stored in array position " << result << endl
				<< "(Remember: The first position is 0.)\n";
		}
		cout << "Search again?(y/n followed by Return): ";
		cin >> ans;

	} while ((ans != 'n') && (ans != 'N'));
	cout << "End of program.\n";
	return 0;
}

template <class S, class T>
set<S,T>::set(){
}
template <class S, class T>
set<S,T>::~set(){
}
template <class S, class T>
void set<S,T>::fillArray(S a[], T size, T &numberUsed)
{
	cout << "Enter up to " << size << " nonnegative whole numbers.\n"
		<< "Mark the end of the list with a negative number.\n";

	//T는 int 이므로 이부분도 마찬가지로 int next, index=0; 과 동일
	S next;
	T index = 0;
	cin >> next;
	//문자 부분에서 -1을 입력하여도 if(next=='-1')아무런 변화가 없어서 z로 종료 해야합니다.
	while ((next>=0) && (index < size))
	{
		if(next=='z')
			break;
		//배열에 값 넣기
		//-1을 입력하기 전과 index가 최대 크기보다 작을때까지만
		a[index]=next;
		index++;
		cin >> next;
	}
	//-1 값이 들어갔을때의 index 크기 혹은 최대 size=(20)
	numberUsed=index;
}
template <class S, class T>
int set<S,T>::search(const S a[], T numberUsed, S target)
{
	//마찬가지로 T는 int
	T index=0;
	bool found = false;
	while((!found) && (index<numberUsed)){
		if(target == a[index])
			found=true;
		else
			index++;
	}
	if(found)
		return index;
	else
		return -1;
}