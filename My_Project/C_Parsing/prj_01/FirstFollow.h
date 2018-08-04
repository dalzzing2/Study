#pragma once

typedef struct grammer{
	int select, location;	//단말기호, 비단말기호 & 할당된 위치
	char str[100];
	int leaf;
	grammer* link[5];
}grammer;
typedef struct rule{
	grammer left;		//좌측
	grammer right[10];	//우측
	int rule_len;		//길이
}rule;

class FirstFollow
{
protected:
	rule rule_v[23];
	typedef char SymbolName[10];
	SymbolName Terminals[22];
	SymbolName NonTerminals[9];
	//First Follow 테이블
	int first[9][23];
	int follow[9][23];

public:
	int main();
	//문자
	int first_string (grammer str[], int symbol_len, int result[]);
	//심볼
	int follow_symbol(int NonTerminal);
	int first_symbol(grammer sym);
	//생성 소멸
	FirstFollow(void);
	~FirstFollow(void);
};

