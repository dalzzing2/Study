#pragma once
#include "FirstFollow.h"

typedef struct token{
	char* tokenName;
	char strbuf[100];
	int tokenType;		//0:ID, 1:NUM, 2:ROP, 3~15:30, 16~27:50, 28~43:KEWORD, 44:EOF
	int attribute;
	int Nval0;
	double Nval1;
};

typedef struct typeitemnode *point_itemnode;
typedef struct typeitemnode{
	int	RuleNum;
	int	DotNum;
	point_itemnode link;
};

typedef struct statenode* point_statenode;
typedef struct statenode{
	int	id;				//�ڽ��� ID(��ȣ)
	int	item_cnt;		//�����ϰ� �ִ� Item ���� ��
	point_itemnode item_start;		//�����ϰ� �ִ� Item_list�� �����ּ�
	point_statenode	next;			//���� state���� arc
};

typedef struct itemnode* point_arcnode;
typedef struct itemnode{
	int	from_state;		//���ȣ
	int	to_state;		//����ġ
	grammer	gram_sym;		//���� �ɺ�
	point_arcnode link;
}itemnode;

//Go_to �׷����� ��� ����
typedef struct gotoset* point_gotoset;
typedef struct gotoset{
	point_arcnode Arc_list;
	point_statenode	State_Node_List;
};

//�׼� �Ľ����̺��� ���� Ÿ�Լ���
typedef struct cell_action_tbl{
	char Kind;	//s,r,a,e �� �� ����/
	int num;	//s �̸� ������Ʈ ��ȣ,r �̸� �� ��ȣ�� ��Ÿ��.
};

class LRParsing : public FirstFollow
{
private:
	enum relop_attr{GT,GE,LT,LE,LG,EQ,NE,AND,OR};

	typedef struct keyword{
		char* strbuf;
		int tokenType;
	};

	typedef struct symbol{
		int entry;
		char strbuf[100];
		symbol* down;
	};

	int read_type;
	FILE* read_fp;

	void* stack[400];
	int NumberOfState;
	int top;
	int height;
	int width;
	grammer* root;
	FILE* fp_error;
	//Goto�׷����� ���, �Ľ� �׼�, �Ľ� goto���̺� ����
	point_gotoset States_And_Arcs;
	cell_action_tbl Action_Table[100][22];
	int Goto_Table[100][9];

public:
	token lexicalAnalizer();
	void initKeyTab();
	int compare_keyword(char[]);
	int compare_symbol(char[]);
	void ret_back(int*, char[], int buf_index);
	void main();

	CString readAll;
	CString resurt;
	CString resurt_editbox;
	int* index;
	keyword keywordTable[16];
	symbol* symbolRoot;

	LRParsing(CString readAll);
	LRParsing(FILE* fp);
	LRParsing(void);
	~LRParsing(void);

	int parsetable_mfc(void);
	int parsetree_mfc(FILE* read_fp, CDC *pDC, CSize *size);
	void parsedraw_mfc(CDC* pDC, grammer* curr, CRect rect);
	grammer input_string(LRParsing lex);
	int leafcount(grammer* curr);
protected:

	void* pop(void);
	void push(void* temp);

	void linkinit(grammer* temp);


	point_itemnode closure(point_itemnode IS);
	point_itemnode GoTo(point_itemnode IS, grammer sym_val);
	point_gotoset makeGotoGraph(point_itemnode IS_0);

	point_arcnode findArc(point_statenode from_state, grammer Symbol);
	bool CheckExistItem(point_itemnode IS, point_itemnode temp);
	int itemListCounter(point_itemnode To_list);
	void Add_An_Arc(point_arcnode *Arc_List_Header, int from_num, int to_num, grammer Symbol);
	point_itemnode getLastItem(point_itemnode IS);
	point_statenode Add_A_State_Node(point_statenode state_node, point_itemnode To_list);
};


