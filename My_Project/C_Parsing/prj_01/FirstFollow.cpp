#include "StdAfx.h"
#include "FirstFollow.h"


//이전의 FirstFollow 이용

FirstFollow::FirstFollow(void)
{
	/*
	//단말기호
	strcpy(Terminals[0], "+");
	strcpy(Terminals[1], "d");
	strcpy(Terminals[2], "*");
	strcpy(Terminals[3], "/");
	strcpy(Terminals[4], "(");
	strcpy(Terminals[5], ")");
	strcpy(Terminals[6], "id");
	strcpy(Terminals[7], "num");
	strcpy(Terminals[8], "$");
	strcpy(Terminals[9], "ε");

	//비단말기호
	strcpy(NonTerminals[0], "E");
	strcpy(NonTerminals[1], "E'");
	strcpy(NonTerminals[2], "T");
	strcpy(NonTerminals[3], "T'");
	strcpy(NonTerminals[4], "F");

	//룰
	//select = 1 : 비단말기호, select = 0 : 단말기호
	//left.loaction : 비단말기호 위치(E, E', T, T', F)
	//right.location : 단말기호 위치(+, -, * ... )
	//rule_len : -> 우측부분의 길이

	// E -> TE'
	rule_v[0].left.select=1;rule_v[0].left.location=0;			// E : 비단말기호
	rule_v[0].right[0].select=1;rule_v[0].right[0].location=2;	// T : 비단말기호
	rule_v[0].right[1].select=1;rule_v[0].right[1].location=1;	// E' : 비단말기호
	rule_v[0].rule_len=2;										// 룰의 길이 2

	// E' -> +TE'
	rule_v[1].left.select=1;rule_v[1].left.location=1;			// E' : 비단말기호
	rule_v[1].right[0].select=0;rule_v[1].right[0].location=0;	// + : 단말기호
	rule_v[1].right[1].select=1;rule_v[1].right[1].location=2;	// T : 비단말기호
	rule_v[1].right[2].select=1;rule_v[1].right[2].location=1;	// E' : 비단말기호
	rule_v[1].rule_len=3;										// 룰의 길이 3

	// E' -> -TE'
	rule_v[2].left.select=1;rule_v[2].left.location=1;			// 이후도 마찬가지의 룰(주석생략)
	rule_v[2].right[0].select=0;rule_v[2].right[0].location=1;	
	rule_v[2].right[1].select=1;rule_v[2].right[1].location=2;	
	rule_v[2].right[2].select=1;rule_v[2].right[2].location=1;
	rule_v[2].rule_len=3;

	// E' -> ε
	rule_v[3].left.select=1;rule_v[3].left.location=1;
	rule_v[3].right[0].select=0;rule_v[3].right[0].location=9;
	rule_v[3].rule_len=1;

	// T -> FT'
	rule_v[4].left.select=1;rule_v[4].left.location=2;
	rule_v[4].right[0].select=1;rule_v[4].right[0].location=4;	
	rule_v[4].right[1].select=1;rule_v[4].right[1].location=3;
	rule_v[4].rule_len=2;

	// T' -> *FT'
	rule_v[5].left.select=1;rule_v[5].left.location=3;
	rule_v[5].right[0].select=0;rule_v[5].right[0].location=2;	
	rule_v[5].right[1].select=1;rule_v[5].right[1].location=4;	
	rule_v[5].right[2].select=1;rule_v[5].right[2].location=3;
	rule_v[5].rule_len=3;

	// T' -> /FT'
	rule_v[6].left.select=1;rule_v[6].left.location=3;
	rule_v[6].right[0].select=0;rule_v[6].right[0].location=3;	
	rule_v[6].right[1].select=1;rule_v[6].right[1].location=4;	
	rule_v[6].right[2].select=1;rule_v[6].right[2].location=3;
	rule_v[6].rule_len=3;

	// T' -> ε
	rule_v[7].left.select=1;rule_v[7].left.location=3;
	rule_v[7].right[0].select=0;rule_v[7].right[0].location=9;
	rule_v[7].rule_len=1;

	// F -> (E)
	rule_v[8].left.select=1;rule_v[8].left.location=4;
	rule_v[8].right[0].select=0;rule_v[8].right[0].location=4;	
	rule_v[8].right[1].select=1;rule_v[8].right[1].location=0;	
	rule_v[8].right[2].select=0;rule_v[8].right[2].location=5;
	rule_v[8].rule_len=3;

	// F -> id
	rule_v[9].left.select=1;rule_v[9].left.location=4;
	rule_v[9].right[0].select=0;rule_v[9].right[0].location=6;
	rule_v[9].rule_len=1;

	// F -> num
	rule_v[10].left.select=1;rule_v[10].left.location=4;
	rule_v[10].right[0].select=0;rule_v[10].right[0].location=7;
	rule_v[10].rule_len=1;
	*/

	strcpy(Terminals[0], "if");
	strcpy(Terminals[1], "while");
	strcpy(Terminals[2], "{");
	strcpy(Terminals[3], "}");
	strcpy(Terminals[4], "(");
	strcpy(Terminals[5], ")");
	strcpy(Terminals[6], ";");
	strcpy(Terminals[7], "+");
	strcpy(Terminals[8], "-");
	strcpy(Terminals[9], "*");
	strcpy(Terminals[10], "/");
	strcpy(Terminals[11], "=");
	strcpy(Terminals[12], "||");
	strcpy(Terminals[13], "&&");
	strcpy(Terminals[14], "!");
	strcpy(Terminals[15], "relop");
	strcpy(Terminals[16], "id");
	strcpy(Terminals[17], "num");
	strcpy(Terminals[18], "[");
	strcpy(Terminals[19], "]");
	strcpy(Terminals[20], "$");
	strcpy(Terminals[21], "ε");

	strcpy(NonTerminals[0], "P");
	strcpy(NonTerminals[1], "L");
	strcpy(NonTerminals[2], "S");
	strcpy(NonTerminals[3], "AE");
	strcpy(NonTerminals[4], "AT");
	strcpy(NonTerminals[5], "AF");
	strcpy(NonTerminals[6], "BE");
	strcpy(NonTerminals[7], "BT");
	strcpy(NonTerminals[8], "BF");

	//룰
	//select = 1 : 비단말기호, select = 0 : 단말기호
	//left.loaction : 비단말기호 위치(P, L, S, ..)
	//right.location : 비단말 혹은 단말기호 위치(+, -, * ... )
	//rule_len : -> 우측부분의 길이

	// 0번룰 P -> L
	rule_v[0].left.select=1;rule_v[0].left.location=0;			// P : 비단말기호
	rule_v[0].right[0].select=1;rule_v[0].right[0].location=1;	// L : 비단말기호
	rule_v[0].rule_len=1;			// 룰의 길이 : 1

	// 1번룰 L -> ε
	rule_v[1].left.select=1;rule_v[1].left.location=1;
	rule_v[1].right[0].select=0;rule_v[1].right[0].location=22-1;
	rule_v[1].rule_len=1;

	// 2번룰 L -> L S
	rule_v[2].left.select=1;rule_v[2].left.location=1;
	rule_v[2].right[0].select=1;rule_v[2].right[0].location=1;
	rule_v[2].right[1].select=1;rule_v[2].right[1].location=2;
	rule_v[2].rule_len=2;

	// 3번룰 S -> if ( BE ) S
	rule_v[3].left.select=1;rule_v[3].left.location=2;
	rule_v[3].right[0].select=0;rule_v[3].right[0].location=0;
	rule_v[3].right[1].select=0;rule_v[3].right[1].location=4;
	rule_v[3].right[2].select=1;rule_v[3].right[2].location=6;
	rule_v[3].right[3].select=0;rule_v[3].right[3].location=5;
	rule_v[3].right[4].select=1;rule_v[3].right[4].location=2;
	rule_v[3].rule_len=5;

	// 과제에서 작성해준 룰 계속 작성
	rule_v[4].left.select=1;rule_v[4].left.location=2;
	rule_v[4].right[0].select=0;rule_v[4].right[0].location=1;	
	rule_v[4].right[1].select=0;rule_v[4].right[1].location=4;	
	rule_v[4].right[2].select=1;rule_v[4].right[2].location=6;	
	rule_v[4].right[3].select=0;rule_v[4].right[3].location=5;	
	rule_v[4].right[4].select=1;rule_v[4].right[4].location=2;
	rule_v[4].rule_len=5;

	rule_v[5].left.select=1;rule_v[5].left.location=2;
	rule_v[5].right[0].select=0;rule_v[5].right[0].location=16;	
	rule_v[5].right[1].select=0;rule_v[5].right[1].location=11;
	rule_v[5].right[2].select=1;rule_v[5].right[2].location=3;	
	rule_v[5].right[3].select=0;rule_v[5].right[3].location=6;
	rule_v[5].rule_len=4;

	rule_v[6].left.select=1;rule_v[6].left.location=2;
	rule_v[6].right[0].select=0;rule_v[6].right[0].location=2;
	rule_v[6].right[1].select=1;rule_v[6].right[1].location=1;
	rule_v[6].right[2].select=0;rule_v[6].right[2].location=3;
	rule_v[6].rule_len=3;

	rule_v[7].left.select=1;rule_v[7].left.location=3;
	rule_v[7].right[0].select=1;rule_v[7].right[0].location=4;
	rule_v[7].rule_len=1;

	rule_v[8].left.select=1;rule_v[8].left.location=3;
	rule_v[8].right[0].select=1;rule_v[8].right[0].location=3;
	rule_v[8].right[1].select=0;rule_v[8].right[1].location=7;
	rule_v[8].right[2].select=1;rule_v[8].right[2].location=4;
	rule_v[8].rule_len=3;

	rule_v[9].left.select=1;rule_v[9].left.location=3;
	rule_v[9].right[0].select=1;rule_v[9].right[0].location=3;
	rule_v[9].right[1].select=0;rule_v[9].right[1].location=8;
	rule_v[9].right[2].select=1;rule_v[9].right[2].location=4;
	rule_v[9].rule_len=3;

	rule_v[10].left.select=1;rule_v[10].left.location=4;
	rule_v[10].right[0].select=1;rule_v[10].right[0].location=5;
	rule_v[10].rule_len=1;

	rule_v[11].left.select=1;rule_v[11].left.location=4;
	rule_v[11].right[0].select=1;rule_v[11].right[0].location=4;
	rule_v[11].right[1].select=0;rule_v[11].right[1].location=9;
	rule_v[11].right[2].select=1;rule_v[11].right[2].location=5;
	rule_v[11].rule_len=3;

	rule_v[12].left.select=1;rule_v[12].left.location=4;
	rule_v[12].right[0].select=1;rule_v[12].right[0].location=4;
	rule_v[12].right[1].select=0;rule_v[12].right[1].location=10;
	rule_v[12].right[2].select=1;rule_v[12].right[2].location=5;
	rule_v[12].rule_len=3;

	rule_v[13].left.select=1;rule_v[13].left.location=5;
	rule_v[13].right[0].select=0;rule_v[13].right[0].location=4;
	rule_v[13].right[1].select=1;rule_v[13].right[1].location=3;
	rule_v[13].right[2].select=0;rule_v[13].right[2].location=5;
	rule_v[13].rule_len=3;

	rule_v[14].left.select=1;rule_v[14].left.location=5;
	rule_v[14].right[0].select=0;rule_v[14].right[0].location=16;
	rule_v[14].rule_len=1;

	rule_v[15].left.select=1;rule_v[15].left.location=5;
	rule_v[15].right[0].select=0;rule_v[15].right[0].location=17;
	rule_v[15].rule_len=1;

	rule_v[16].left.select=1;rule_v[16].left.location=6;
	rule_v[16].right[0].select=1;rule_v[16].right[0].location=7;
	rule_v[16].rule_len=1;

	rule_v[17].left.select=1;rule_v[17].left.location=6;
	rule_v[17].right[0].select=1;rule_v[17].right[0].location=6;
	rule_v[17].right[1].select=0;rule_v[17].right[1].location=12;
	rule_v[17].right[2].select=1;rule_v[17].right[2].location=7;
	rule_v[17].rule_len=3;

	rule_v[18].left.select=1;rule_v[18].left.location=7;
	rule_v[18].right[0].select=1;rule_v[18].right[0].location=8;
	rule_v[18].rule_len=1;

	rule_v[19].left.select=1;rule_v[19].left.location=7;
	rule_v[19].right[0].select=1;rule_v[19].right[0].location=7;
	rule_v[19].right[1].select=0;rule_v[19].right[1].location=13;
	rule_v[19].right[2].select=1;rule_v[19].right[2].location=8;
	rule_v[19].rule_len=3;

	rule_v[20].left.select=1;rule_v[20].left.location=8;
	rule_v[20].right[0].select=0;rule_v[20].right[0].location=4;
	rule_v[20].right[1].select=1;rule_v[20].right[1].location=6;
	rule_v[20].right[2].select=0;rule_v[20].right[2].location=5;
	rule_v[20].rule_len=3;

	rule_v[21].left.select=1;rule_v[21].left.location=8;
	rule_v[21].right[0].select=0;rule_v[21].right[0].location=14;
	rule_v[21].right[1].select=1;rule_v[21].right[1].location=8;
	rule_v[21].rule_len=2;

	rule_v[22].left.select=1;rule_v[22].left.location=8;
	rule_v[22].right[0].select=1;rule_v[22].right[0].location=3;
	rule_v[22].right[1].select=0;rule_v[22].right[1].location=15;
	rule_v[22].right[2].select=1;rule_v[22].right[2].location=3;
	rule_v[22].rule_len=3;

	main();
}


FirstFollow::~FirstFollow(void)
{
}

int FirstFollow::main(){
	//구조체 grammer 의sym_temp 객체 생성
	grammer sym_temp;
	int i, j;
	//First 테이블 초기화
	for(i=0;i<9;i++){
		for(j=0;j<24;j++){
			first[i][j]=0;
		}
	}
	for(i=0;i<9;i++){
		// 비단말기호 , i번째 위치의 심볼
		sym_temp.select=1;
		sym_temp.location=i;
		//첫번째 심볼함수 호출
		first_symbol(sym_temp);
	}

	//Follow 테이블 초기화
	for(i=0;i<9;i++){
		for(j=0;j<23;j++){
			follow[i][j]=0;
		}
	}

	//follow 의 시작 비단말기호와 $ 단말기호 값을 1로
	follow[0][20]=1;

	//비단말기호 계산
	for(i=0;i<9;i++){
		//비단말기호 매개변수
		follow_symbol(i);
	}

	return 0;
}



int FirstFollow::first_symbol(grammer sym){
	int top = -1;
	int stack[10];

	if(sym.select==0) 
		return 0;
	if(first[sym.location][22]==1)
		return 0;
	for(int r=0;r<23;r++){
		//룰을 하나하나검사
		if(sym.location == rule_v[r].left.location){
			//왼쪽이 sym인 룰만 처리
			if(rule_v[r].rule_len==1 && rule_v[r].right[0].select == 0 && rule_v[r].right[0].location == 22-1)
				//룰이 입실론이라면 퍼스트에 입실론 추가
				first[sym.location][22-1]=1;
			else
				for(int i=0;i<rule_v[r].rule_len;i++){
					//오른쪽의 symbol들을 하나하나처리
					if(rule_v[r].right[i].select==0){
						//오른쪽의 i번째 심볼이 단말기호일때
						first[sym.location][rule_v[r].right[i].location]=1;
						break;
					}else if(rule_v[r].right[i].select==1){
						//비단말기호일때
						if(first[rule_v[r].right[i].location][22]==0){
							//재귀호출이 리커시브하게 반복되면 잠시 보류해논다
							if(rule_v[r].right[i].select == sym.select && rule_v[r].right[i].location == sym.location){
								stack[++top] = r;
								break;
							}
							else
								first_symbol(rule_v[r].right[i]);
						}

						for(int j=0;j<22;j++)
							if(first[rule_v[r].right[i].location][j]==1)
								first[sym.location][j] =1;
						if(first[rule_v[r].right[i].location][21]==0)
							//오른쪽의 i번째 심볼이 입실론을 퍼스트로 갖고있지않다면
							break;
						else
							//오른쪽의 i번째의 퍼스트가 입실론 갖고있다면
							if(i==rule_v[r].rule_len-1)
								//i가 오른쪽에서 마지막심볼일때 sym퍼스트에 입실론 추가
								first[sym.location][21]=1;
					}
				}
		}
	}
	if(top>=0){
		if(first[sym.location][21] == 1){
			while(top>=0){
				int r = stack[top--];
				for(int i=0;i<rule_v[r].rule_len;i++){
					//오른쪽의 symbol들을 하나하나처리
					if(rule_v[r].right[i].select==0){
						//오른쪽의 i번째 심볼이 단말기호일때
						first[sym.location][rule_v[r].right[i].location]=1;
						break;
					}else if(rule_v[r].right[i].select==1){
						//비단말기호일때
						if(first[rule_v[r].right[i].location][22]==0){
							//재귀호출이 리커시브하게 반복되면 잠시 보류해논다
							if(rule_v[r].right[i].select == sym.select && rule_v[r].right[i].location == sym.location){
								;
							}
							else
								first_symbol(rule_v[r].right[i]);
						}

						for(int j=0;j<22;j++)
							if(first[rule_v[r].right[i].location][j]==1)
								first[sym.location][j] =1;
						if(first[rule_v[r].right[i].location][21]==0)
							//오른쪽의 i번째 심볼이 입실론을 퍼스트로 갖고있지않다면
							break;
						else
							//오른쪽의 i번째의 퍼스트가 입실론 갖고있다면
							if(i==rule_v[r].rule_len-1)
								//i가 오른쪽에서 마지막심볼일때 sym퍼스트에 입실론 추가
								first[sym.location][21]=1;
					}
				}
			}
		}
	}
	first[sym.location][22]=1;
	return 0;
}

int FirstFollow::follow_symbol(int NonTerminal){
	//비단말기호

	int i, j, k;
	//result[10] 변수 0으로 초기화
	int result[22];
	//구조체 grammer의 grammer_string[10] 선언
	grammer grammer_string[10];

	//i : 룰의 번호
	for(i=0; i<23; i++){
		//오른쪽의 심볼들
		for(j=0; j<rule_v[i].rule_len; j++){
			//오른쪽에 있는 룰 i 번째의 j 가 비단말 기호일 경우
			if(rule_v[i].right[j].select == 1){
				//오른쪽 i번째 룰 j 번째에 위치한 값이 매개변수로 받아온 비단말기호 값과 다르면 처음으로 돌아감
				if(rule_v[i].right[j].location != NonTerminal)
					continue;

				//오른쪽 i번째 룰 j 번째에 위치한 값이 매개변수로 받아온 비단말기호 값과 같으면 수행함
				//j 가 (오른쪽 i번째 룰 길이-1) 과 다르면 수행 => j 가 오른쪽 맨 끝 심볼이 아닐경우

				// 예
				// i = 5 라면
				// T' -> *FT' (len=3)
				// j는 0 ~ 2
				// j 가 0 1이라면 수행
				if(j != rule_v[i].rule_len-1){
					//k의 초기값 j+1, k 가 우측 i 번째 룰 길이와 같아질 때까지 증가

					//j가 0일때
					//k 는 1 k < 3 ; k ++
					//grammer_string[0] = rule_v[5].right[1]
					//grammer_string[1] = rule_v[5].right[2] .. 이런 원리
					//j가 1일때
					//k 는 2 k < 3; k ++
					//grammer_string[0] = rele_v[5].right[2]
					for(k=j+1; k<rule_v[i].rule_len; k++)
						//오른쪽 i번째 룰의 k 번째 위치 심볼의 값 - grammer_string[k-(j+1)]에 대입
						grammer_string[k-(j+1)]=rule_v[i].right[k];
					//첫번째 문자 계산 함수
					first_string(grammer_string, rule_v[i].rule_len-(j+1), result);

					for(k=0; k<21; k++){
						//받은 결과 result[k] 가 1이면
						if(result[k] == 1)
							//팔로우 테이블에 [비단말기호 번호][K] 저장
							follow[NonTerminal][k]=result[k];
					}
				}

				//오른쪽 i번째 룰 j 번째에 위치한 값이 매개변수로 받아온 비단말기호 값과 같으면 처음으로 돌아감
				if(rule_v[i].left.location == NonTerminal)
					continue;

				//result에 입실론이 포함되었거나, j가 우측 마지막 심볼이라면
				if(result[21]==1 || j==rule_v[i].rule_len-1){
					//왼쪽 i 번째 룰의 비단말기호 다시 호출
					follow_symbol(rule_v[i].left.location);
					for(k=0; k<22; k++)
						//[왼쪽 i 번째 룰의 비단말기호 값][k] 가 1이면
						if(follow[rule_v[i].left.location][k] == 1)
							//팔로우테이블의 [매개변수 비단말기호 Nonterminal][k] 에 대입
							follow[NonTerminal][k]=follow[rule_v[i].left.location][k];
				}
			}
		}
	}
	return 0;
}

//Follow함수의 첫번째 문자
int FirstFollow::first_string (grammer str[], int symbol_len, int result[]){
	//grammer_string, rele_v[i].rule_len-(j+1), result

	int i, j;
	//첫 스트링의 초기화
	for(i=0; i<22; i++){
		result[i]=0;
	}

	//스티링 길이가 0 이면 - 심볼이 없는 경우
	if(symbol_len == 0)
		//입실론이 있다는 의미이므로 result[9] 는 1 : 입실론 위치
		result[21]=1;

	//심볼이 들어있을경우
	else{
		//심볼길이만큼
		for(int i=0;i<symbol_len;i++){
			//i번째 스트링이 비단말기호일때
			if(str[i].select==1){
				for(int j=0;j<22;j++){
					//퍼스트 테이블의 [str의 i번째 위치값][j] 이 1 이면
					if(first[str[i].location][j]==1)
						//result[j] 에 값 대입
						result[j]=first[str[i].location][j];
				}
				//입실론이 아니라면 포문 종료
				if(first[str[i].location][22-1]==0)
					break;
				//입실론이라면 1 대입
				else
						result[22-1]=1;
			}
			//i번째 스트링이 단말기호일때
			else if(str[i].select==0){
				result[str[i].location]=1;
				return 0;
			}
		}
	}
	return 0;
}