#include "StdAfx.h"
#include "LRParsing.h"

LRParsing::LRParsing(void)
{
	index=new int;
	*index=0;
	symbolRoot=NULL;
	initKeyTab();
	resurt.Format("");
	resurt_editbox.Format("");
	read_fp = NULL;
	read_type=-1;

	States_And_Arcs = NULL;
	NumberOfState=1;
	root = NULL;
	
	height = width = 0;
}

LRParsing::LRParsing(FILE* fp)
{
	index=new int;
	*index=0;
	symbolRoot=NULL;
	this->readAll.Format("");
	initKeyTab();
	resurt.Format("");
	resurt_editbox.Format("");
	read_fp = fp;
	read_type=0;
}

LRParsing::LRParsing(CString readAll)
{
	index=new int;
	*index=0;
	symbolRoot=NULL;
	this->readAll = readAll;
	initKeyTab();
	resurt.Format("");
	resurt_editbox.Format("");
	read_fp = NULL;
	read_type=1;
}


LRParsing::~LRParsing(void)
{
}

void LRParsing::main(){
	token tok;
	int i=1;
	int read=0;
	CString outfilename;

	resurt.AppendFormat("%-20s %-20s %-20s %-20s %-20s\n", "일련번호", "토큰번호", "토큰종류", "토큰스트링", "애트리뷰트");
	resurt_editbox.AppendFormat("%-20s %-20s %-20s %-20s %-20s\r\n", "일련번호", "토큰번호", "토큰종류", "토큰스트링", "애트리뷰트");
	index=&read;

	do{
		fflush(stdin);
		tok = lexicalAnalizer();
		if(tok.tokenType==0){
			resurt.AppendFormat("%-20d %-20d %-20s %-20s %-20d\n", i, tok.tokenType, tok.tokenName, tok.strbuf, tok.attribute);
			resurt_editbox.AppendFormat("%-20d %-20d %-20s %-20s %-20d\r\n", i++, tok.tokenType, tok.tokenName, tok.strbuf, tok.attribute);
		}else if(tok.tokenType==1){
			if(tok.attribute==0){
				resurt.AppendFormat("%-20d %-20d %-20s %-20s %-20d\n", i, tok.tokenType, tok.tokenName, tok.strbuf, tok.Nval0);
				resurt_editbox.AppendFormat("%-20d %-20d %-20s %-20s %-20d\r\n", i++, tok.tokenType, tok.tokenName, tok.strbuf, tok.Nval0);
			}
			else if(tok.attribute==1){
				resurt.AppendFormat("%-20d %-20d %-20s %-20s %-20f\n", i, tok.tokenType, tok.tokenName, tok.strbuf, tok.Nval1);
				resurt_editbox.AppendFormat("%-20d %-20d %-20s %-20s %-20f\r\n", i++, tok.tokenType, tok.tokenName, tok.strbuf, tok.Nval1);
			}
		}else if(tok.tokenType==2){
			resurt.AppendFormat("%-20d %-20d %-20s %-20s %-20s\n", i, tok.tokenType, tok.tokenName, tok.strbuf, tok.strbuf);
			resurt_editbox.AppendFormat("%-20d %-20d %-20s %-20s %-20s\r\n", i++, tok.tokenType, tok.tokenName, tok.strbuf, tok.strbuf);
		}else {
			resurt.AppendFormat("%-20d %-20d %-20s %-20s\n", i, tok.tokenType, tok.tokenName, tok.strbuf);
			resurt_editbox.AppendFormat("%-20d %-20d %-20s %-20s\r\n", i++, tok.tokenType, tok.tokenName, tok.strbuf);
		}
	}while(tok.tokenType!=44);
}

token LRParsing::lexicalAnalizer(){
	char readchar;
	int state=0;//0=start
	char readbuf[100];
	token ret_tok={"","",0,0,0,0};
	int buf_index=0;
	double num;
	int multifier;
	int num_index=0;

	//readAll.AppendChar(' ');
	if(read_type == 1)
		readAll.AppendChar(EOF);
	do{
		//readchar = fgetc(fp);
		if(read_type == 1){
			readchar = readAll.GetAt(*index);
			(*index)++;
		} else if(read_type ==0){
			readchar = fgetc(read_fp);
		}

		if(readchar == EOF && state==0){
				ret_tok.tokenName="EOF";
				strcpy_s(ret_tok.strbuf,"\0");
				ret_tok.tokenType=44;
				return ret_tok;
		}

		readbuf[buf_index++]=readchar;
		readbuf[buf_index]='\0';
		switch(state){
		case 0:
			if((readchar>='a' && readchar<='z') || (readchar>='A' && readchar<='Z') || readchar=='_') state=1;
			
			else if(readchar == '>') state=5;
			else if(readchar == '<') state=6;
			else if(readchar == '=') state=7;
			else if(readchar == '!') state=8;
			else if(readchar == '&') state=9;
			else if(readchar == '|') state=10;

			else if(readchar == '+') state=30;
			else if(readchar == '-') state=31;
			else if(readchar == '*') {ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=5; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '/') state=32;
			else if(readchar == '%') {ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=7; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '.') {ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=11; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == ',') {ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=12; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}

			else if(readchar == '(') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=16; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == ')') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=17; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '{') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=18; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '}') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=19; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '[') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=20; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == ']') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=21; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '\\') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=22; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == ':') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=23; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == ';') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=24; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '"') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=25; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '\'') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=26; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar == '#') {ret_tok.tokenName="METADATA"; ret_tok.tokenType=27; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}

			else if(readchar>='0' && readchar<='9') {state=70; num=readchar-48;}

			else if(readchar=='\n') { strcpy_s(readbuf,""); buf_index=0; state=0;}
			else if(readchar=='\t') {strcpy_s(readbuf,""); buf_index=0; state=0;}
			else if(readchar==' ') {strcpy_s(readbuf,""); buf_index=0; state=0;}

			else state=ERROR;
			break;
		case 1:
			if((readchar>='a' && readchar<='z') || (readchar>='A' && readchar<='Z') || readchar=='_' || (readchar>='0' && readchar<='9')) state=1;
			else {
				ret_back(index, readbuf, buf_index);
				ret_tok.tokenType= compare_keyword(readbuf);
				if(ret_tok.tokenType!=-1){
					ret_tok.tokenName="KEYWORD";
					strcpy_s(ret_tok.strbuf,readbuf);
				}else{
					ret_tok.tokenType=0;
					strcpy_s(ret_tok.strbuf,readbuf);
					ret_tok.tokenName="ID";
					ret_tok.attribute=compare_symbol(readbuf);}
				return ret_tok;
			}
			break;

		case 5:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='='){ ret_tok.attribute=GE; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else{ret_back(index, readbuf, buf_index); ret_tok.attribute=GT; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 6:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='='){ ret_tok.attribute=LE; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar=='>'){ ret_tok.attribute=LG; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else{ret_back(index, readbuf, buf_index); ret_tok.attribute=LT; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 7:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='='){ ret_tok.attribute=EQ; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else {ret_back(index,readbuf,buf_index); ret_tok.tokenName="="; ret_tok.tokenType=8; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 8:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='='){ ret_tok.attribute=NE; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else {ret_back(index,readbuf,buf_index); ret_tok.tokenName="!"; ret_tok.tokenType=10; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 9:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='&'){ ret_tok.attribute=AND; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else {ret_back(index,readbuf,buf_index); ret_tok.tokenName="&"; ret_tok.tokenType=13; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 10:
			ret_tok.tokenName="ROP";
			ret_tok.tokenType=2;
			if(readchar=='|'){ ret_tok.attribute=OR; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else state=ERROR;
			break;

		case 30:
			if(readchar=='+'){ ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=14; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else{ ret_back(index, readbuf, buf_index); ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=3; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 31:
			if(readchar=='-'){ ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=15; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else if(readchar=='>'){ ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=9; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			else{ ret_back(index, readbuf, buf_index); ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=4; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;
		case 32:
			if(readchar == '/') state=100;
			else if(readchar == '*') state=101;
			else {ret_back(index, readbuf, buf_index); ret_tok.tokenName="OPERATOR"; ret_tok.tokenType=6; strcpy_s(ret_tok.strbuf,readbuf); return ret_tok;}
			break;

		case 70:
			if(readchar>='0' && readchar<='9') {state=70; num = num*10+(readchar-48);}
			else if (readchar == '.') state=71;
			else if (readchar == 'E') state=73;
			else {ret_back(index, readbuf, buf_index); ret_tok.tokenName="NUM"; ret_tok.tokenType=1; strcpy_s(ret_tok.strbuf,readbuf); ret_tok.attribute=0; ret_tok.Nval0=static_cast<int>(num); return ret_tok;}
			break;
		case 71:
			if(readchar>='0' && readchar<='9') {state=72; num_index++; num=num*10+(readchar-48);}
			else state=ERROR;
			break;
		case 72:
			if(readchar>='0' && readchar<='9') {state=72; num_index++; num=num*10+(readchar-48);}
			else if(readchar == 'E') {
				state=73;
				for(int i=0;i<num_index; i++){
					num=num/10.0;
				}
			}
			else {
				for(int i=0;i<num_index; i++){
					num=num/10.0;
				}
				ret_back(index, readbuf, buf_index); ret_tok.tokenName="NUM"; ret_tok.tokenType=1; strcpy_s(ret_tok.strbuf,readbuf); ret_tok.attribute=1; ret_tok.Nval1=num; return ret_tok;
			}
			break;
		case 73:
			if(readchar>='0' && readchar<='9') {state=74; multifier=readchar-48;}
			else if(readchar=='+' || readchar=='-') {state=74; multifier=0;}
			else state=ERROR;
			break;
		case 74:
			if(readchar>='0' && readchar<='9') {state=74; multifier=multifier*10+(readchar-48);}
			else{
				for(int i=0;i<multifier; i++)
					num*=10;
				ret_back(index, readbuf, buf_index); ret_tok.tokenName="NUM"; ret_tok.tokenType=1; strcpy_s(ret_tok.strbuf,readbuf);
				if(num_index<=multifier){ret_tok.attribute=0; ret_tok.Nval0=static_cast<int>(num);}
				else{ret_tok.attribute=1; ret_tok.Nval1=num;}
				return ret_tok;
			}
			break;

		case 100:
			strcpy_s(readbuf,"");
			buf_index=0;
			if(readchar == '\n') state=0;
			break;
		case 101:
			strcpy_s(readbuf,"");
			buf_index=0;
			if(readchar == '*') state=100+2;
			break;
		case 102:
			strcpy_s(readbuf,"");
			buf_index=0;
			if(readchar == '/') state=0;
			else state=101;
			break;
		
		case -1:
			strcpy_s(readbuf,"");
			buf_index=0;
			if(readchar==' ' || readchar=='\t' || readchar=='\n') state=0;
			break;
		}
	}while(readbuf[0] != EOF);
	return ret_tok;
}

void  LRParsing::ret_back(int* index, char readbuf[], int buf_index){//안읽은걸로 되돌리기 함수.=
	if(read_type == 1)
		(*index)--;
	else if(read_type == 0)
		fseek(read_fp, -1, SEEK_CUR);
	readbuf[buf_index-1]='\0'; 
}
int  LRParsing::compare_keyword(char buf[]){//키워드가 아닐시 -1리턴 키워드일시 해당하는토큰타입 리턴
	for(int i=0;i<16; i++){
		if(strcmp(buf, keywordTable[i].strbuf)==0)
			return keywordTable[i].tokenType;
	}
	return -1;
}
int  LRParsing::compare_symbol(char buf[]){//해당하는 심볼엔트리번호 리턴
	symbol* cur_symbol;
	symbol* temp;
	int temp_entry=0;

	if(symbolRoot==NULL){
		temp=(symbol*)malloc(sizeof(symbol));
		temp->entry=0;
		strcpy_s(temp->strbuf, buf);
		temp->down=NULL;
		symbolRoot=temp;
		return temp->entry;
	}

	else{
		for(cur_symbol=symbolRoot;;  temp_entry=cur_symbol->entry+1, cur_symbol=cur_symbol->down){
			if(strcmp(cur_symbol->strbuf,buf)==0)
				return cur_symbol->entry;
			if(cur_symbol->down==NULL)
				break;
		}
		temp=(symbol*)malloc(sizeof(symbol));
		temp->entry=temp_entry+1;
		strcpy_s(temp->strbuf, buf);
		temp->down=NULL;
		cur_symbol->down=temp;
		return temp->entry;
	}
}
void  LRParsing::initKeyTab(){
	keywordTable[0].strbuf="if";
	keywordTable[1].strbuf="else";
	keywordTable[2].strbuf="while";
	keywordTable[3].strbuf="do";
	keywordTable[4].strbuf="for";
	keywordTable[5].strbuf="include";
	keywordTable[6].strbuf="define";
	keywordTable[7].strbuf="typedef";
	keywordTable[8].strbuf="struct";
	keywordTable[9].strbuf="int";
	keywordTable[10].strbuf="char";
	keywordTable[11].strbuf="float";
	keywordTable[12].strbuf="double";
	keywordTable[13].strbuf="main";
	keywordTable[14].strbuf="void";
	keywordTable[15].strbuf="return";

	keywordTable[0].tokenType=28;
	keywordTable[1].tokenType=29;
	keywordTable[2].tokenType=30;
	keywordTable[3].tokenType=31;
	keywordTable[4].tokenType=32;
	keywordTable[5].tokenType=33;
	keywordTable[6].tokenType=34;
	keywordTable[7].tokenType=35;
	keywordTable[8].tokenType=36;
	keywordTable[9].tokenType=37;
	keywordTable[10].tokenType=38;
	keywordTable[11].tokenType=39;
	keywordTable[12].tokenType=40;
	keywordTable[13].tokenType=41;
	keywordTable[14].tokenType=42;
	keywordTable[15].tokenType=43;
}

void LRParsing::push(void* temp){
	if(top<399)
		stack[++top] = temp;
}
void* LRParsing::pop(){
	if(top>=0)
		return stack[top--];
}

grammer LRParsing::input_string(LRParsing lex){
	grammer ret;
	token tok=lex.lexicalAnalizer();
	int flag=0;

	ret.select=0;
	if (tok.tokenType == 0){
		ret.location = 16; strcpy_s(ret.str, tok.strbuf);
	}
	else if (tok.tokenType == 1){
		ret.location = 17; strcpy_s(ret.str, tok.strbuf);
	}
	else if (tok.tokenType == 2 && !(strcmp(tok.strbuf, "||") == 0 || strcmp(tok.strbuf, "&&") == 0)){
		ret.location = 15; strcpy_s(ret.str, tok.strbuf);
	}
	else if (tok.tokenType == 44){
		ret.location = 22 -2;
	}
	else{
		for(int i=0;i<22; i++){
			if(strcmp(tok.strbuf,Terminals[i]) == 0){
				ret.location=i;flag=1;
				break;}}
		if(flag==0)
			ret.select=-1;
	}
	return ret;
}

int LRParsing::parsetree_mfc(FILE *read_fp, CDC *pDC, CSize *size){
	top=-1;
	fseek(read_fp, 0, SEEK_SET);
	CString terminalString;
	LRParsing lex(read_fp);	//모든내용을 읽어들여 분석한다.
	grammer *X, a, *temp;
	int *S;
	int k;
	cell_action_tbl action;
	int cnt=0, cnt_s = 0, cnt_r = 0;

	int err = parsetable_mfc();
	if(err == -1)
		return -1;

	//상태0을 삽입.
	S = (int*) malloc(sizeof(int));
	*S = 0;
	push((void*)S);
	//처음 심볼을 읽음.
	a = input_string(lex);
	if(a.select == -1) return -4;
	do{
		cnt++;
		if(cnt == 95)
			cnt = 95;
		S = (int*)stack[top];				//stack의 탑의 상태를 읽는다. (popX)
		//각 액션테이블 값에 따른 행동
		action = Action_Table[*S][a.location];	//해당 상태와 심볼에 대한 Action_Table값
		switch (action.Kind){
		//읽어드린 토큰을 푸시. 상태도 푸시.
		case 's':
			cnt_s++;
			X = (grammer*) malloc(sizeof(grammer));
			linkinit(X);
			X->select = a.select; X->location = a.location;
			if(a.select == 0 && (a.location == 16 || a.location == 17 || a.location == 15))
				strcpy_s(X->str, a.str);
			push((void*)X);

			S = (int*)malloc(sizeof(int));
			*S = action.num;
			push((void*)S);
			//남은 input string의 첫 심볼을 읽고 다음심볼을 가리킴.
			a = input_string(lex);
			if(a.select == -1) return -4;				
			break;

		//팝해서 리듀스하고 다시 푸시. 상태도 푸시.
		case 'r':
			cnt_r++;
			X = (grammer*)malloc(sizeof(grammer));
			linkinit(X);
			X->select = rule_v[action.num].left.select;
			X->location = rule_v[action.num].left.location;

			//입실론을 리듀스할때, 팝하지말고 입실론을 추가로 링크.
			if(rule_v[action.num].rule_len == 1 && rule_v[action.num].right[0].select == 0 && rule_v[action.num].right[0].location == 22-1){
				temp = (grammer*)malloc(sizeof(grammer));
				linkinit(temp);
				temp->select = 0; temp->location = 22-1;
				X->link[0] = temp;
			}
			//다른기호에 대해선 정상적인 팝과 링크를 걸어준다.
			else{
				for(int i=rule_v[action.num].rule_len-1; i>=0; i--){
					free((int*)pop());
					X->link[i] = (grammer*)pop();
				}//상태와 심볼, 두배로 pop;
			}
			k = *(int*)stack[top];

			//룰의 왼쪽심볼을 푸시
			push((void*)X);
			//상태도 푸시.
			S = (int*)malloc(sizeof(int));
			*S = Goto_Table[k][rule_v[action.num].left.location];
			push((void*)S);
			break;

		//성공했으므로 파스트리를 그리는 함수 호출.
		case 'a':
			//상태는 팝해서 없애주고, 심볼은 루트에다 연결.
			free((int*)pop());
			root = (grammer*)pop();
			free((int*)pop());
			break;

		//에러이므로 음수 리턴값 출력
		case 'e':
			break;
		default:
			return -3;
			break;
		}
	}while(!(action.Kind == 'a' && a.select == 0 && a.location == 22-2));

	width = leafcount(root)*70;
	CRect rect(0,5,5+width,5+35);
	height = 5;
	this->parsedraw_mfc(pDC, root, rect);
	size->cx = width; size->cy = height;
	return 0;
}

void LRParsing::linkinit(grammer* temp){
	for(int i=0;i<5; i++)
		temp->link[i]=NULL;
}

int LRParsing::leafcount(grammer* curr){
	curr->leaf=0;
	for(int i=0;i<5; i++){
		if(curr->link[i]!=NULL)
			curr->leaf+=leafcount(curr->link[i]);
	}
	if(curr->select==0)
		curr->leaf=1;
	
	return curr->leaf;
}

point_itemnode LRParsing::closure(point_itemnode IS){
	//지역변수 선언
	point_itemnode	new_cs, curr, cursor;
	grammer					SymAfterDot;
	int					r_num, d_num;
	int					i_0 = 0;
	//포인터 curr가 CS의 첫 노드를 가리키게 한다.
	curr = IS;

	//Core Routine
	while(curr){
		//curr 노드의 rule번호
		r_num = curr->RuleNum;
		d_num = curr->DotNum;

		//SynAfterDot : type.grammer {int select / int location}
		SymAfterDot = rule_v[r_num].right[d_num];

		//단말기호이면 무시하고 넘어간다.
		if(!SymAfterDot.select){
			curr = curr->link;
			continue;
		}//if:select == 0
		for(i_0 = 0; i_0<23; i_0++){
			//룰 i_0의 좌측 심볼이 SymAfterDot이
			//아니면 continue
			if(rule_v[i_0].left.location != SymAfterDot.location)
				continue;

			//item node 하나를 만든다.
			new_cs=(point_itemnode)malloc(sizeof(typeitemnode));

			//rule 번호 r; dot number = 0 을 여기에 넣는다.
			new_cs->RuleNum = i_0;
			new_cs->DotNum = 0;
			new_cs->link=NULL;

			//new_cs가 이미 존재하면 continue
			if(CheckExistItem(IS, new_cs)){
				free(new_cs);
				continue;
			}//if : CheckExistItem()

			//NewItemNodePtr를 CS의 맨 뒤에 붙인다.
			cursor = getLastItem(IS);
			cursor->link = new_cs;
		}//for : i_0
		curr = curr->link;
	}//while : curr


	return IS;
}//closure()

bool LRParsing::CheckExistItem(point_itemnode IS, point_itemnode temp){
	point_itemnode curr;
	for(curr = IS; curr != NULL; curr=curr->link){
		if(curr->RuleNum == temp->RuleNum && curr->DotNum == temp->DotNum)
			return true;
	}
	return false;
}

point_itemnode LRParsing::getLastItem(point_itemnode IS){
	point_itemnode curr;
	for(curr = IS; curr->link != NULL; curr=curr->link)
		;

	return curr;
}

point_itemnode LRParsing::GoTo(point_itemnode IS, grammer sym_val){
	int r_num, d_num;
	grammer SymAfterDot;
	point_itemnode cursor, New_Item, Go_To_Result_List = NULL, temp_item = NULL;
	//point_itemnode i_cursor;

	cursor = IS;
	while(cursor){
		//curr노드의 rule번호
		r_num = cursor->RuleNum;
		d_num = cursor->DotNum;

		//dot이 맨 끝에 존재하는 아이템은 무시.
		if(d_num >= rule_v[r_num].rule_len){
			cursor = cursor->link;
			continue;
		}

		SymAfterDot = rule_v[r_num].right[d_num];

		//점 다음의 심볼과 goto할 심볼이 다르면 다음 아이템으로 넘어 감.
		if(!(SymAfterDot.select == sym_val.select && SymAfterDot.location == sym_val.location)){
			cursor = cursor->link;
			continue;
		}

		//도트를 한칸 우측으로 옮긴 아이템 생성
		New_Item = (point_itemnode) malloc(sizeof(typeitemnode));
		New_Item->DotNum = d_num+1;
		New_Item->RuleNum = r_num;
		New_Item->link = NULL;

		//New_Item가 이미 존재하면 다음 cursor로 스킵.
		if(CheckExistItem(Go_To_Result_List,New_Item)){
			free(New_Item);
			cursor = cursor->link;
			continue;
		}

		//NewItemNodePtr를 Go_To_Result_List의 맨 뒤에 붙인다.
		if(Go_To_Result_List == NULL){
			Go_To_Result_List = New_Item;
		}else{
			temp_item = getLastItem(Go_To_Result_List);
			temp_item->link = New_Item;
		}//if

		cursor = cursor->link;
	}//while : cursor

	if(Go_To_Result_List)
		return closure(Go_To_Result_List);
	else
		return NULL;
}//GoTo()

point_gotoset LRParsing::makeGotoGraph(point_itemnode IS_0){
	//지역변수 선언
	int i_0, i_1, i_max;
	grammer sym_temp;
	point_gotoset result = NULL;
	point_statenode State_Node_List_Header = NULL, state_cursor, To_state_node;

	point_arcnode Arc_List_Header = NULL;
	point_itemnode To_item_list=NULL;

	//스테이트 0를 스테이트 리스트에 넣도록 함.(맨 처음으로 넣는 것임.)
	state_cursor = State_Node_List_Header = Add_A_State_Node(State_Node_List_Header, IS_0);
	//itemListPrint(IS_0);

	while(state_cursor){
		//단말기호, 비단말기호
		for(i_0 = 0; i_0 < 2; i_0++){//i_0 = 0이면 단말기호에 대한 처리이고, 1이면 비단말기호에 대한 처리임
			//i_max는 각 경우 (단말/비단말)가 가진 총 기호의 수를 가지게함.
			i_max = i_0 ? 9 : 22-2;//-2을 한 이유는 $단말기호와 입실론을 무시하기 위함.

			for(i_1 = 0; i_1 < i_max; i_1++){//i_1은 단말/비단말 각경우에서 기호의 번호를 나타냄.
				//문법 심볼 하나를 만듬.
				sym_temp.select = i_0;
				sym_temp.location = i_1;

				//현재 스테이트에서 문법심볼 sym_temp에 의해 goto할 아이템 리스트를 알아 옴.
				To_item_list = GoTo(state_cursor->item_start, sym_temp);//goto를 하여 결과를 알아 옴.
				
				if(To_item_list){
					//goto할 아이템리스트를 스테이트 노드에 없으면 등록하고,
					//있으면 어느것인지 판별함. 그리고 그 스테이트 노드를 알아옴.
					To_state_node = Add_A_State_Node(State_Node_List_Header, To_item_list);

					//알아낸 아크에 대하여 이것이 없으면 새로운 아크로 추가함.
					Add_An_Arc(&Arc_List_Header, state_cursor->id, To_state_node->id, sym_temp);
				}//if: To_item_list
			}//for: i_1: 모든기호에 대해 goto 수행
		}//for: i_0: 단말기호->비단말기호
		state_cursor = state_cursor->next;
	}//while: state_cursor

	//반환할 변수에값을 입력합니다.
	result = (point_gotoset)malloc(sizeof(gotoset));

	result->State_Node_List = State_Node_List_Header;
	result->Arc_list = Arc_List_Header;

	return result;
}//:makeGotoGraph()

point_statenode LRParsing::Add_A_State_Node(point_statenode State_Node_List_Header, point_itemnode To_list){
	//지역변수 선언
	int Number_Of_Items, same_node_found, two_lists_are_different;
	point_statenode cursor=State_Node_List_Header, last_cursor = NULL, new_state_node;
	point_itemnode list_it_ptr, new_it_ptr;

	Number_Of_Items = itemListCounter(To_list);
	//state list 내의 값들과 비교하여 list 추가 여부를 경정합니다.
	while(cursor){
		//item 개수가 서로 같은지 확인하여 다르면 다음 cursor로 스킵함
		//주의:last_cursor도 변경하면서.
		if(cursor->item_cnt != Number_Of_Items){
			last_cursor = cursor;
			cursor = cursor->next;
			continue;
		}

		//두 아이템 리스트가 동일한지 확인하다. 이를 위해 cursor의 스테이트 노드의 아이템 리스트의 각 노드마다
		//이것이 To_list에 존재하는 지 검사하여 나간다.
		list_it_ptr = cursor->item_start;
		two_lists_are_different = 0;

		//list_it_ptr을 state의 아이템 list안의 각 아이템을 가리키게 하면서
		//이것이 To_list 안에 있는지 조사한다. 모두 존재하면 동일한 리스트라고 결정한다.
		while(list_it_ptr){
			new_it_ptr = To_list;
			//state list내의 item list에 동일한 node가 있는지 확인한다.
			same_node_found = 0;
			//new_it_ptr로 하여금 To_list의 각 아이템을 가리키게 하면서
			//list_it_ptr이 가리키는 것과 같은것이 발견되는 지 조사한다.
			//발견되면 same_node_found를 1로 셋팅한다.
			while(new_it_ptr){
				if(new_it_ptr->RuleNum == list_it_ptr->RuleNum && new_it_ptr->DotNum == list_it_ptr->DotNum){
					same_node_found = 1;
					break;
				}
				new_it_ptr = new_it_ptr->link;
			}//while: new_it_ptr

			//To_list내에 같은 것이 발견되지 않았다면 이 두 리스트는 다르다고 경정한다.
			if(!same_node_found){
				two_lists_are_different = 1;
				break;//다음 state로 간다.
			}

			list_it_ptr = list_it_ptr->link;
		}//while: list_to_ptr: item node 단위
		if(!two_lists_are_different){//cursor의 state의 아이템 리스트와 To_list가 동일한 상황임.
			return cursor;//동일한 것으로 판명된 현 스테이트 노드의 포인터를 반환해 줌.
		}

		//두 아이템 리스트가 다른 것으로 판명되었으므로 다음 스테이트 노드로 커서를 옮김.
		last_cursor = cursor;
		cursor = cursor->next;
	}//while: cursor: state list단위

	//state node list 전체를 비교해도 같은 아이템리스트를 가진 스테이트 노드가 발견되지 않았음.
	//따라서 새로운 스테이트 노드를 만들어 To_list를 붙이고 이 노드를 스테이트 노드 리스트의 맨 뒤에 추가함.
	new_state_node = (point_statenode)malloc(sizeof(statenode));
	new_state_node->item_cnt = Number_Of_Items;
	new_state_node->item_start = To_list;
	new_state_node->next = NULL;
	//state list에 새로운 state node를 연결합니다.
	if(last_cursor){
		NumberOfState++;
		new_state_node->id = last_cursor->id+1;
		last_cursor->next = new_state_node;
	}else{ //처음으로 추가되는 스테이트 노드임. 이 경우는 맨 처음에 IS_0을 추가할 때 일어남.
		new_state_node->id = 0;
	}
	return new_state_node;
}//Add_A_State_Node()

int LRParsing::itemListCounter(point_itemnode To_list){
	int count;
	
	for(count=0; To_list!=NULL; count++)
		To_list=To_list->link;

	return count;
}

void LRParsing::Add_An_Arc(point_arcnode *Arc_List_Header, int from_num, int to_num, grammer Symbol){
	point_arcnode Arc_cursor, Arc_last = NULL, Arc_new = NULL;

	Arc_new = (point_arcnode)malloc(sizeof(itemnode));
	Arc_new->from_state = from_num;
	Arc_new->to_state = to_num;
	Arc_new->gram_sym = Symbol;
	Arc_new->link = NULL;
	if(*Arc_List_Header){
		//Arc_cursor로 하여금 마지막 노드를 가리키게 함.
		Arc_cursor = *Arc_List_Header;
		while(Arc_cursor){
			//동일한 아크가 존재하면 넣지 않음.
			if(Arc_cursor->from_state == from_num && Arc_cursor->to_state == to_num && Arc_cursor->gram_sym.select == Symbol.select && Arc_cursor->gram_sym.location == Symbol.location){
				free(Arc_new);
				return ;
			}
			else{
				Arc_last = Arc_cursor;
				Arc_cursor = Arc_cursor->link;
			}
		}
		Arc_last->link = Arc_new;
	}
	else{
		*Arc_List_Header = Arc_new; // 맨 처음 아크를 달아 준다.
	}
}//Add_An_Arc()

int LRParsing::parsetable_mfc(void){
	//지역변수 선언
	int r_num, d_num;
	point_itemnode IS_0;
	point_statenode curr_state = NULL;
	point_arcnode curr_Arc = NULL, find_Arc;
	point_itemnode curr_item= NULL;

	//Grammer에 대해 Canonical collection C및 GotoGraph를 만든다.
	IS_0 = (point_itemnode)malloc(sizeof(typeitemnode));
	IS_0->DotNum=0;
	IS_0->RuleNum=0;
	IS_0->link=NULL;

	IS_0 = closure(IS_0);

	States_And_Arcs = makeGotoGraph(IS_0);

	//Action_Table, Goto_Table 초기화
	for(int i=0; i<100; i++){
		for(int j=0; j<22; j++){
			Action_Table[i][j].Kind = 'e';
			Action_Table[i][j].num = -1;
		}
	}
	for(int i=0; i<100; i++){
		for(int j=0; j<9; j++){
			Goto_Table[i][j] = -1;
		}
	}

	//Action_Table만들기.
	curr_state = States_And_Arcs->State_Node_List;
	while(curr_state){
		for(curr_item=curr_state->item_start; curr_item; curr_item=curr_item->link){
			r_num = curr_item->RuleNum;
			d_num = curr_item->DotNum;
			//curr_item의 dot이 룰의 오른쪽끝에 있지 않고,
			//dot다음의 심볼이 단말기호이며 아크로 연결되 있다면 시프트액션 추가
			if(d_num < rule_v[r_num].rule_len && rule_v[r_num].right[d_num].select == 0){
				find_Arc = findArc(curr_state, rule_v[r_num].right[d_num]);
				if(find_Arc){
					int numOfSymAfterDot = rule_v[r_num].right[d_num].location;
					if(Action_Table[curr_state->id][numOfSymAfterDot].Kind != 'e'){
						if(!(Action_Table[curr_state->id][numOfSymAfterDot].Kind=='s' && Action_Table[curr_state->id][numOfSymAfterDot].num == find_Arc->to_state))
							return -1;
					}else{
						Action_Table[curr_state->id][numOfSymAfterDot].Kind='s';
						Action_Table[curr_state->id][numOfSymAfterDot].num = find_Arc->to_state;
					}
				}
			}
			//dot이 룰 오른쪽의 맨끝에 있다면 || 룰의 오른쪽이 입실론이라면
			//리듀스 액션 추가.
			if(d_num >= rule_v[r_num].rule_len || (rule_v[r_num].rule_len == 1 && rule_v[r_num].right[0].select == 0 && rule_v[r_num].right[0].location == 22-1)){
				for(int i=0; i<22; i++){
					if(follow[rule_v[r_num].left.location][i]==1){
						if(Action_Table[curr_state->id][i].Kind != 'e'){
							if(!(Action_Table[curr_state->id][i].Kind=='r' && Action_Table[curr_state->id][i].num == r_num))
								return -1;
						}else{
							Action_Table[curr_state->id][i].Kind='r';
							Action_Table[curr_state->id][i].num = r_num;
						}
					}
				}
			}
			//첫번째 룰의 우측 끝에 dot이 있다면 어셉트.
			if(r_num == 0 && d_num == 1){
				Action_Table[curr_state->id][22-2].Kind='a';
				Action_Table[curr_state->id][22-2].num=0;
			}
		}//for: curr_state->curr_item
		curr_state = curr_state->next;
	}//while: curr_state
	
	//Goto_Table 만들기
	curr_Arc = States_And_Arcs->Arc_list;
	while(curr_Arc){
		if(curr_Arc->gram_sym.select == 1){
			Goto_Table[curr_Arc->from_state][curr_Arc->gram_sym.location] = curr_Arc->to_state;
		}
		curr_Arc = curr_Arc->link;
	}

	return 0;
}

point_arcnode LRParsing::findArc(point_statenode from_state, grammer Symbol){
	point_arcnode curr = States_And_Arcs->Arc_list;

	while(curr){
		if(curr->from_state == from_state->id && curr->gram_sym.select == Symbol.select && curr->gram_sym.location == Symbol.location)
			return curr;
		curr = curr->link;
	}
	return NULL;
}

void LRParsing::parsedraw_mfc(CDC* pDC, grammer* curr, CRect rect){
	//size 30+20,35
	
	height = (height < rect.bottom) ? rect.bottom : height;

	CRect child_rect[5];
	int child_width[5]={0};
	int childcnt=0;
	int between_node_height = 50;
	
	if(curr->select==0){
		if(curr->location==16 || curr->location==17 || curr->location == 15){
			//id 혹은 num 일경우
		//빨강으로 출력
			pDC->SetTextColor(RGB(1000,0,0));
			pDC->DrawText(curr->str,rect,DT_CENTER);
		}
		//id 혹은 num을 제외한 다른 경우
		//녹색으로 출력
		else{
			pDC->SetTextColor(RGB(0,1000,0));
			pDC->DrawText(Terminals[curr->location], rect, DT_CENTER);
		}
	}
	//비단말기호
	//파란색으로 출력
	else if (curr->select==1){
		pDC->SetTextColor(RGB(0,0,1000));
			pDC->DrawText(NonTerminals[curr->location], rect, DT_CENTER);
	}
	//너비 계산
	for(int i=0; i<5; i++){
		if(curr->link[i]!=NULL){
			child_width[i]=(rect.Width()/curr->leaf)*curr->link[i]->leaf;
			childcnt++;
		}
		else
			child_width[i]=0;
	}

	int left=rect.left;
	//좌표 얻고 라인그리기

	for(int i=0;i<childcnt;i++){
		child_rect[i] = CRect(left, rect.bottom+between_node_height, left + child_width[i], rect.bottom+between_node_height+rect.Height());
		left+=child_width[i];
	}
	for (int i=0;i<childcnt;i++){
		parsedraw_mfc(pDC, curr->link[i], child_rect[i]);
		pDC->MoveTo(rect.CenterPoint().x, rect.bottom);
		pDC->LineTo(child_rect[i].CenterPoint().x,child_rect[i].top-10);
	}
}