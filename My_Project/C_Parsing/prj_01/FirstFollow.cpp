#include "StdAfx.h"
#include "FirstFollow.h"


//������ FirstFollow �̿�

FirstFollow::FirstFollow(void)
{
	/*
	//�ܸ���ȣ
	strcpy(Terminals[0], "+");
	strcpy(Terminals[1], "d");
	strcpy(Terminals[2], "*");
	strcpy(Terminals[3], "/");
	strcpy(Terminals[4], "(");
	strcpy(Terminals[5], ")");
	strcpy(Terminals[6], "id");
	strcpy(Terminals[7], "num");
	strcpy(Terminals[8], "$");
	strcpy(Terminals[9], "��");

	//��ܸ���ȣ
	strcpy(NonTerminals[0], "E");
	strcpy(NonTerminals[1], "E'");
	strcpy(NonTerminals[2], "T");
	strcpy(NonTerminals[3], "T'");
	strcpy(NonTerminals[4], "F");

	//��
	//select = 1 : ��ܸ���ȣ, select = 0 : �ܸ���ȣ
	//left.loaction : ��ܸ���ȣ ��ġ(E, E', T, T', F)
	//right.location : �ܸ���ȣ ��ġ(+, -, * ... )
	//rule_len : -> �����κ��� ����

	// E -> TE'
	rule_v[0].left.select=1;rule_v[0].left.location=0;			// E : ��ܸ���ȣ
	rule_v[0].right[0].select=1;rule_v[0].right[0].location=2;	// T : ��ܸ���ȣ
	rule_v[0].right[1].select=1;rule_v[0].right[1].location=1;	// E' : ��ܸ���ȣ
	rule_v[0].rule_len=2;										// ���� ���� 2

	// E' -> +TE'
	rule_v[1].left.select=1;rule_v[1].left.location=1;			// E' : ��ܸ���ȣ
	rule_v[1].right[0].select=0;rule_v[1].right[0].location=0;	// + : �ܸ���ȣ
	rule_v[1].right[1].select=1;rule_v[1].right[1].location=2;	// T : ��ܸ���ȣ
	rule_v[1].right[2].select=1;rule_v[1].right[2].location=1;	// E' : ��ܸ���ȣ
	rule_v[1].rule_len=3;										// ���� ���� 3

	// E' -> -TE'
	rule_v[2].left.select=1;rule_v[2].left.location=1;			// ���ĵ� ���������� ��(�ּ�����)
	rule_v[2].right[0].select=0;rule_v[2].right[0].location=1;	
	rule_v[2].right[1].select=1;rule_v[2].right[1].location=2;	
	rule_v[2].right[2].select=1;rule_v[2].right[2].location=1;
	rule_v[2].rule_len=3;

	// E' -> ��
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

	// T' -> ��
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
	strcpy(Terminals[21], "��");

	strcpy(NonTerminals[0], "P");
	strcpy(NonTerminals[1], "L");
	strcpy(NonTerminals[2], "S");
	strcpy(NonTerminals[3], "AE");
	strcpy(NonTerminals[4], "AT");
	strcpy(NonTerminals[5], "AF");
	strcpy(NonTerminals[6], "BE");
	strcpy(NonTerminals[7], "BT");
	strcpy(NonTerminals[8], "BF");

	//��
	//select = 1 : ��ܸ���ȣ, select = 0 : �ܸ���ȣ
	//left.loaction : ��ܸ���ȣ ��ġ(P, L, S, ..)
	//right.location : ��ܸ� Ȥ�� �ܸ���ȣ ��ġ(+, -, * ... )
	//rule_len : -> �����κ��� ����

	// 0���� P -> L
	rule_v[0].left.select=1;rule_v[0].left.location=0;			// P : ��ܸ���ȣ
	rule_v[0].right[0].select=1;rule_v[0].right[0].location=1;	// L : ��ܸ���ȣ
	rule_v[0].rule_len=1;			// ���� ���� : 1

	// 1���� L -> ��
	rule_v[1].left.select=1;rule_v[1].left.location=1;
	rule_v[1].right[0].select=0;rule_v[1].right[0].location=22-1;
	rule_v[1].rule_len=1;

	// 2���� L -> L S
	rule_v[2].left.select=1;rule_v[2].left.location=1;
	rule_v[2].right[0].select=1;rule_v[2].right[0].location=1;
	rule_v[2].right[1].select=1;rule_v[2].right[1].location=2;
	rule_v[2].rule_len=2;

	// 3���� S -> if ( BE ) S
	rule_v[3].left.select=1;rule_v[3].left.location=2;
	rule_v[3].right[0].select=0;rule_v[3].right[0].location=0;
	rule_v[3].right[1].select=0;rule_v[3].right[1].location=4;
	rule_v[3].right[2].select=1;rule_v[3].right[2].location=6;
	rule_v[3].right[3].select=0;rule_v[3].right[3].location=5;
	rule_v[3].right[4].select=1;rule_v[3].right[4].location=2;
	rule_v[3].rule_len=5;

	// �������� �ۼ����� �� ��� �ۼ�
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
	//����ü grammer ��sym_temp ��ü ����
	grammer sym_temp;
	int i, j;
	//First ���̺� �ʱ�ȭ
	for(i=0;i<9;i++){
		for(j=0;j<24;j++){
			first[i][j]=0;
		}
	}
	for(i=0;i<9;i++){
		// ��ܸ���ȣ , i��° ��ġ�� �ɺ�
		sym_temp.select=1;
		sym_temp.location=i;
		//ù��° �ɺ��Լ� ȣ��
		first_symbol(sym_temp);
	}

	//Follow ���̺� �ʱ�ȭ
	for(i=0;i<9;i++){
		for(j=0;j<23;j++){
			follow[i][j]=0;
		}
	}

	//follow �� ���� ��ܸ���ȣ�� $ �ܸ���ȣ ���� 1��
	follow[0][20]=1;

	//��ܸ���ȣ ���
	for(i=0;i<9;i++){
		//��ܸ���ȣ �Ű�����
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
		//���� �ϳ��ϳ��˻�
		if(sym.location == rule_v[r].left.location){
			//������ sym�� �길 ó��
			if(rule_v[r].rule_len==1 && rule_v[r].right[0].select == 0 && rule_v[r].right[0].location == 22-1)
				//���� �ԽǷ��̶�� �۽�Ʈ�� �ԽǷ� �߰�
				first[sym.location][22-1]=1;
			else
				for(int i=0;i<rule_v[r].rule_len;i++){
					//�������� symbol���� �ϳ��ϳ�ó��
					if(rule_v[r].right[i].select==0){
						//�������� i��° �ɺ��� �ܸ���ȣ�϶�
						first[sym.location][rule_v[r].right[i].location]=1;
						break;
					}else if(rule_v[r].right[i].select==1){
						//��ܸ���ȣ�϶�
						if(first[rule_v[r].right[i].location][22]==0){
							//���ȣ���� ��Ŀ�ú��ϰ� �ݺ��Ǹ� ��� �����س��
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
							//�������� i��° �ɺ��� �ԽǷ��� �۽�Ʈ�� ���������ʴٸ�
							break;
						else
							//�������� i��°�� �۽�Ʈ�� �ԽǷ� �����ִٸ�
							if(i==rule_v[r].rule_len-1)
								//i�� �����ʿ��� �������ɺ��϶� sym�۽�Ʈ�� �ԽǷ� �߰�
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
					//�������� symbol���� �ϳ��ϳ�ó��
					if(rule_v[r].right[i].select==0){
						//�������� i��° �ɺ��� �ܸ���ȣ�϶�
						first[sym.location][rule_v[r].right[i].location]=1;
						break;
					}else if(rule_v[r].right[i].select==1){
						//��ܸ���ȣ�϶�
						if(first[rule_v[r].right[i].location][22]==0){
							//���ȣ���� ��Ŀ�ú��ϰ� �ݺ��Ǹ� ��� �����س��
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
							//�������� i��° �ɺ��� �ԽǷ��� �۽�Ʈ�� ���������ʴٸ�
							break;
						else
							//�������� i��°�� �۽�Ʈ�� �ԽǷ� �����ִٸ�
							if(i==rule_v[r].rule_len-1)
								//i�� �����ʿ��� �������ɺ��϶� sym�۽�Ʈ�� �ԽǷ� �߰�
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
	//��ܸ���ȣ

	int i, j, k;
	//result[10] ���� 0���� �ʱ�ȭ
	int result[22];
	//����ü grammer�� grammer_string[10] ����
	grammer grammer_string[10];

	//i : ���� ��ȣ
	for(i=0; i<23; i++){
		//�������� �ɺ���
		for(j=0; j<rule_v[i].rule_len; j++){
			//�����ʿ� �ִ� �� i ��°�� j �� ��ܸ� ��ȣ�� ���
			if(rule_v[i].right[j].select == 1){
				//������ i��° �� j ��°�� ��ġ�� ���� �Ű������� �޾ƿ� ��ܸ���ȣ ���� �ٸ��� ó������ ���ư�
				if(rule_v[i].right[j].location != NonTerminal)
					continue;

				//������ i��° �� j ��°�� ��ġ�� ���� �Ű������� �޾ƿ� ��ܸ���ȣ ���� ������ ������
				//j �� (������ i��° �� ����-1) �� �ٸ��� ���� => j �� ������ �� �� �ɺ��� �ƴҰ��

				// ��
				// i = 5 ���
				// T' -> *FT' (len=3)
				// j�� 0 ~ 2
				// j �� 0 1�̶�� ����
				if(j != rule_v[i].rule_len-1){
					//k�� �ʱⰪ j+1, k �� ���� i ��° �� ���̿� ������ ������ ����

					//j�� 0�϶�
					//k �� 1 k < 3 ; k ++
					//grammer_string[0] = rule_v[5].right[1]
					//grammer_string[1] = rule_v[5].right[2] .. �̷� ����
					//j�� 1�϶�
					//k �� 2 k < 3; k ++
					//grammer_string[0] = rele_v[5].right[2]
					for(k=j+1; k<rule_v[i].rule_len; k++)
						//������ i��° ���� k ��° ��ġ �ɺ��� �� - grammer_string[k-(j+1)]�� ����
						grammer_string[k-(j+1)]=rule_v[i].right[k];
					//ù��° ���� ��� �Լ�
					first_string(grammer_string, rule_v[i].rule_len-(j+1), result);

					for(k=0; k<21; k++){
						//���� ��� result[k] �� 1�̸�
						if(result[k] == 1)
							//�ȷο� ���̺� [��ܸ���ȣ ��ȣ][K] ����
							follow[NonTerminal][k]=result[k];
					}
				}

				//������ i��° �� j ��°�� ��ġ�� ���� �Ű������� �޾ƿ� ��ܸ���ȣ ���� ������ ó������ ���ư�
				if(rule_v[i].left.location == NonTerminal)
					continue;

				//result�� �ԽǷ��� ���ԵǾ��ų�, j�� ���� ������ �ɺ��̶��
				if(result[21]==1 || j==rule_v[i].rule_len-1){
					//���� i ��° ���� ��ܸ���ȣ �ٽ� ȣ��
					follow_symbol(rule_v[i].left.location);
					for(k=0; k<22; k++)
						//[���� i ��° ���� ��ܸ���ȣ ��][k] �� 1�̸�
						if(follow[rule_v[i].left.location][k] == 1)
							//�ȷο����̺��� [�Ű����� ��ܸ���ȣ Nonterminal][k] �� ����
							follow[NonTerminal][k]=follow[rule_v[i].left.location][k];
				}
			}
		}
	}
	return 0;
}

//Follow�Լ��� ù��° ����
int FirstFollow::first_string (grammer str[], int symbol_len, int result[]){
	//grammer_string, rele_v[i].rule_len-(j+1), result

	int i, j;
	//ù ��Ʈ���� �ʱ�ȭ
	for(i=0; i<22; i++){
		result[i]=0;
	}

	//��Ƽ�� ���̰� 0 �̸� - �ɺ��� ���� ���
	if(symbol_len == 0)
		//�ԽǷ��� �ִٴ� �ǹ��̹Ƿ� result[9] �� 1 : �ԽǷ� ��ġ
		result[21]=1;

	//�ɺ��� ����������
	else{
		//�ɺ����̸�ŭ
		for(int i=0;i<symbol_len;i++){
			//i��° ��Ʈ���� ��ܸ���ȣ�϶�
			if(str[i].select==1){
				for(int j=0;j<22;j++){
					//�۽�Ʈ ���̺��� [str�� i��° ��ġ��][j] �� 1 �̸�
					if(first[str[i].location][j]==1)
						//result[j] �� �� ����
						result[j]=first[str[i].location][j];
				}
				//�ԽǷ��� �ƴ϶�� ���� ����
				if(first[str[i].location][22-1]==0)
					break;
				//�ԽǷ��̶�� 1 ����
				else
						result[22-1]=1;
			}
			//i��° ��Ʈ���� �ܸ���ȣ�϶�
			else if(str[i].select==0){
				result[str[i].location]=1;
				return 0;
			}
		}
	}
	return 0;
}