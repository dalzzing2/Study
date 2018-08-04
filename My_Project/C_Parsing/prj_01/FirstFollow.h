#pragma once

typedef struct grammer{
	int select, location;	//�ܸ���ȣ, ��ܸ���ȣ & �Ҵ�� ��ġ
	char str[100];
	int leaf;
	grammer* link[5];
}grammer;
typedef struct rule{
	grammer left;		//����
	grammer right[10];	//����
	int rule_len;		//����
}rule;

class FirstFollow
{
protected:
	rule rule_v[23];
	typedef char SymbolName[10];
	SymbolName Terminals[22];
	SymbolName NonTerminals[9];
	//First Follow ���̺�
	int first[9][23];
	int follow[9][23];

public:
	int main();
	//����
	int first_string (grammer str[], int symbol_len, int result[]);
	//�ɺ�
	int follow_symbol(int NonTerminal);
	int first_symbol(grammer sym);
	//���� �Ҹ�
	FirstFollow(void);
	~FirstFollow(void);
};

