//���÷��� 5.6 ���� template <class T> �� ��ȯ

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
	// �˻��� target set�� ���� �°� Ÿ�� ã�ƾ��ϱ� ������ ������ 3�� ����
	int target1;
	double target2;
	char target3;

	char sel;
	// �迭���� ��������
	int arr1[DECLARED_SIZE];
	double arr2[DECLARED_SIZE];
	char arr3[DECLARED_SIZE];

	cout << "���� : i, �Ǽ� : d, ���� : c �� �Է��ϼ���. : ";
	cin >> sel;
	//���� �Ǽ� ���� �� ���� ȣ�� ����
	if(sel=='i'){
		//�Ű����� ���
		//ù ��° : �迭�̸�, �� ��° : �迭�ִ�ũ��, �� ��° : �Է��� �迭�� ũ�� �����Ҵ�
		t.fillArray(arr1, DECLARED_SIZE, listSize);
	}
	else if(sel=='d'){
		d.fillArray(arr2, DECLARED_SIZE, listSize);
	}
	else if(sel=='c'){
		cout << "���ڴ� z�� �����մϴ�." << endl;
		c.fillArray(arr3, DECLARED_SIZE, listSize);
	}
	char ans;
	int result;
	do
	{
		cout << "Enter a number to search for : ";


		//�迭�� ã��
		//target ã�ƾ� �� ��� ��
		//���� ���������� target
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

	//T�� int �̹Ƿ� �̺κе� ���������� int next, index=0; �� ����
	S next;
	T index = 0;
	cin >> next;
	//���� �κп��� -1�� �Է��Ͽ��� if(next=='-1')�ƹ��� ��ȭ�� ��� z�� ���� �ؾ��մϴ�.
	while ((next>=0) && (index < size))
	{
		if(next=='z')
			break;
		//�迭�� �� �ֱ�
		//-1�� �Է��ϱ� ���� index�� �ִ� ũ�⺸�� ������������
		a[index]=next;
		index++;
		cin >> next;
	}
	//-1 ���� �������� index ũ�� Ȥ�� �ִ� size=(20)
	numberUsed=index;
}
template <class S, class T>
int set<S,T>::search(const S a[], T numberUsed, S target)
{
	//���������� T�� int
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