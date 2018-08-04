
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
char world[80][22];
char new_world[80][22];	//��������� ���� �� ������ ������ ������ ���鼭 ����� ���� �������� �����ؾ� �� ���� ����Ǽ��� �ȵǱ� ������ ���ο� �迭�� ������ ��Ű���� ����

int i, j;

void generation();
void display();

int main()
{
	//�ʱ� ������ �� ���� (�ƽ�Ű �ڵ�� �����Ǳ� ������ �ƽ�Ű �ڵ尪 1�̰ų� 0�� ���� * �� _(����) ���� �ٽ� �����ϰ� ��� display�Լ��κ�
	int sel; // ��� ������ �����Ұ��� ����� ����

	//�ʱ� �� �� �������� ����
	srand(time(0));
	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			world[i][j] = rand()%2;
		}
	}

	while(1){
		display();		//���� ����ϴ� �Լ� - �⺻ �� ����
		cout << "���� �����Ͻðڽ��ϱ�? ��)1 �ƴϿ�)2 : " ;
		cin >> sel;

		if(sel==2)
			break;
		else if(sel==1)
			generation();	//���� ���� �����ϴ� �Լ�
		else
			assert(0);		// 1�� 2�� ���� ��� ���� ���
	}
	system("pause");
	return 0;
}

void generation()
{
	// �̿����� 2���ϰ�� ������� �״�� ����
	// �̿����� 0���̰ų� 1�� Ȥ�� 3�� �ʰ��� ��� �ڱ��ڽ��� ���� ����(0)
	// �̿����� 3���ϰ�� �ڱ��ڽ��� ���� ��Ƴ�(1)

	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			//  i-1,j-1  i-1,j  i-1,j+1
			//   i,j-1    i,j    i,j+1
			//  i+1,j-1  i+1,j  i+1,j+1

			//3���� �𼭸� ��
			//if�� ������ if ���� ��� ���� ��Ģ

			//2�� �̸��̸� 0, 3�� �ʰ��̸� 0, 3���̸� 1, 2���̸� ������� �״�� ����

			if(i==0&&j==0){		//���� �� �𼭸�
				if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==0&&j==21){	//���� �� �𼭸�
				if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j==0){		//���� �Ʒ� �𼭸�
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j==21){		//���� �Ʒ� �𼭸�
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//4���� �����ڸ� ��
			else if(i==0&&j!=0&&j!=21){		//�����̸鼭 �𼭸� ����
				if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j!=0&&j!=21){		//�Ʒ����̸鼭 �𼭸� ����
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==0&&i!=0&&i!=79){		//�����̸鼭 �𼭸� ����
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==21&&i!=0&&i!=79){		//�����̸鼭 �𼭸� ����
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//����(8���� �̿����� �����κ�)
			else{
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
		}
	}

	//��� ���� ������ ������
	//���ο� �迭�� �⺻ �迭�� �ٽ� �������
	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			world[i][j]=new_world[i][j];
		}
	}
}
void display()
{
	//��� 1�̸� * 0�̸� _(����)
	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			if(world[i][j]==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout << endl;
	}
}

// �� ���� �ʹ� ũ�⶧����
// 3 �� 3�� �� �� �����ϰ� ���� ���� �����ϴ��� (����)

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
char world[3][3]={0,1,0,0,1,0,0,1,0};
char new_world[3][3];
int i, j;

void generation();
void display();

int main()
{
	//�ʱ� ������ �� ���� (�ƽ�Ű �ڵ�� �����Ǳ� ������ �ƽ�Ű �ڵ尪 1�̰ų� 0�� ���� * �� _(����) ���� �ٽ� �����ϰ� ��� display�Լ��κ�
	int sel; // ��� ������ �����Ұ��� ����� ����

	while(1){
		display();		//���� ȭ���� �ѹ� ������� - �⺻ �� ����
		cout << "���� �����Ͻðڽ��ϱ�? ��)1 �ƴϿ�)2 : " ;
		cin >> sel;
		if(sel==2)
			break;
		else if(sel==1)
			generation();	//���¿� ���� 0�� 1�� ���� �ٲ���
		else
			assert(0);
	}
	system("pause");
	return 0;
}

void generation()
{
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			//  i-1,j-1  i-1,j  i-1,j+1
			//   i,j-1    i,j    i,j+1
			//  i+1,j-1  i+1,j  i+1,j+1

			//3���� �𼭸� ��
			if(i==0&&j==0){		//���� �� �𼭸�
				if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==0&&j==2){	//���� �� �𼭸�
				if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j==0){		//���� �Ʒ� �𼭸�
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j==2){		//���� �Ʒ� �𼭸�
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//4���� �����ڸ� ��
			else if(i==0&&j!=0&&j!=2){		//�����̸鼭 �𼭸� ����
				if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j!=0&&j!=2){		//�Ʒ����̸鼭 �𼭸� ����
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==0&&i!=0&&i!=2){		//�����̸鼭 �𼭸� ����
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==2&&i!=0&&i!=2){		//�����̸鼭 �𼭸� ����
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//����(8���� �̿����� �����κ�)
			else{
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			world[i][j]=new_world[i][j];
		}
	}
}
void display()
{
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(world[i][j]==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout << endl;
	}
}
*/