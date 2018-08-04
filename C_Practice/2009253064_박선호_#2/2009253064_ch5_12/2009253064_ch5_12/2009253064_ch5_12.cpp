
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
char world[80][22];
char new_world[80][22];	//최종변경된 값의 셀 지정한 이유는 포문을 돌면서 변경된 셀이 다음번에 변경해야 할 셀과 적용되서는 안되기 때문에 새로운 배열에 저장을 시키려고 만듬

int i, j;

void generation();
void display();

int main()
{
	//초기 임의의 값 지정 (아스키 코드로 지정되기 때문에 아스키 코드값 1이거나 0에 따라서 * 와 _(공백) 으로 다시 설정하고 출력 display함수부분
	int sel; // 계속 게임을 진행할건지 물어보는 변수

	//초기 셀 값 랜덤변수 지정
	srand(time(0));
	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			world[i][j] = rand()%2;
		}
	}

	while(1){
		display();		//셀을 출력하는 함수 - 기본 셀 부터
		cout << "셀을 변경하시겠습니까? 예)1 아니오)2 : " ;
		cin >> sel;

		if(sel==2)
			break;
		else if(sel==1)
			generation();	//셀의 값을 수정하는 함수
		else
			assert(0);		// 1과 2의 값일 경우 에러 출력
	}
	system("pause");
	return 0;
}

void generation()
{
	// 이웃셀이 2개일경우 현재상태 그대로 저장
	// 이웃셀이 0개이거나 1개 혹은 3개 초과일 경우 자기자신의 셀은 죽음(0)
	// 이웃셀이 3개일경우 자기자신의 셀은 살아남(1)

	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			//  i-1,j-1  i-1,j  i-1,j+1
			//   i,j-1    i,j    i,j+1
			//  i+1,j-1  i+1,j  i+1,j+1

			//3개의 모서리 측
			//if문 내부의 if 문은 모두 같은 규칙

			//2개 미만이면 0, 3개 초과이면 0, 3개이면 1, 2개이면 현재상태 그대로 저장

			if(i==0&&j==0){		//좌측 윗 모서리
				if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==0&&j==21){	//우측 윗 모서리
				if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j==0){		//좌측 아랫 모서리
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j==21){		//우측 아랫 모서리
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//4개의 가장자리 변
			else if(i==0&&j!=0&&j!=21){		//윗쪽이면서 모서리 제외
				if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==79&&j!=0&&j!=21){		//아랫쪽이면서 모서리 제외
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==0&&i!=0&&i!=79){		//좌측이면서 모서리 제외
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==21&&i!=0&&i!=79){		//우측이면서 모서리 제외
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//내부(8개의 이웃셀을 가진부분)
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

	//모든 셀의 수정이 끝나면
	//새로운 배열을 기본 배열로 다시 덮어씌워줌
	for(i=0; i<80; i++){
		for(j=0; j<22; j++){
			world[i][j]=new_world[i][j];
		}
	}
}
void display()
{
	//출력 1이면 * 0이면 _(공백)
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

// 윗 셀은 너무 크기때문에
// 3 행 3열 로 써 간단하게 모의 실험 성공하는지 (성공)

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
	//초기 임의의 값 지정 (아스키 코드로 지정되기 때문에 아스키 코드값 1이거나 0에 따라서 * 와 _(공백) 으로 다시 설정하고 출력 display함수부분
	int sel; // 계속 게임을 진행할건지 물어보는 변수

	while(1){
		display();		//먼저 화면을 한번 출력해줌 - 기본 셀 부터
		cout << "셀을 변경하시겠습니까? 예)1 아니오)2 : " ;
		cin >> sel;
		if(sel==2)
			break;
		else if(sel==1)
			generation();	//상태에 따라 0과 1의 값을 바꿔줌
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

			//3개의 모서리 측
			if(i==0&&j==0){		//좌측 윗 모서리
				if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==0&&j==2){	//우측 윗 모서리
				if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j==0){		//좌측 아랫 모서리
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j==2){		//우측 아랫 모서리
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//4개의 가장자리 변
			else if(i==0&&j!=0&&j!=2){		//윗쪽이면서 모서리 제외
				if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(i==2&&j!=0&&j!=2){		//아랫쪽이면서 모서리 제외
				if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==0&&i!=0&&i!=2){		//좌측이면서 모서리 제외
				if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]<2)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]>3)
					new_world[i][j]=0;
				else if(world[i-1][j]+world[i-1][j+1]+world[i][j+1]+world[i+1][j]+world[i+1][j+1]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}
			else if(j==2&&i!=0&&i!=2){		//우측이면서 모서리 제외
				if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]<2)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]>3)
					new_world[i][j]=0;
				else if(world[i-1][j-1]+world[i-1][j]+world[i][j-1]+world[i+1][j-1]+world[i+1][j]==3)
					new_world[i][j]=1;
				else
					new_world[i][j]=world[i][j];
			}

			//내부(8개의 이웃셀을 가진부분)
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