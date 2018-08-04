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
	int	id;				//자신의 ID(번호)
	int	item_cnt;		//보유하고 있는 Item 들의 수
	point_itemnode item_start;		//보유하고 있는 Item_list의 시작주소
	point_statenode	next;			//다음 state로의 arc
};

typedef struct itemnode* point_arcnode;
typedef struct itemnode{
	int	from_state;		//룰번호
	int	to_state;		//점위치
	grammer	gram_sym;		//사용된 심볼
	point_arcnode link;
}itemnode;

//Go_to 그래프의 헤더 선언
typedef struct gotoset* point_gotoset;
typedef struct gotoset{
	point_arcnode Arc_list;
	point_statenode	State_Node_List;
};

//액션 파싱테이블의 셀의 타입선언
typedef struct cell_action_tbl{
	char Kind;	//s,r,a,e 중 한 글자/
	int num;	//s 이면 스테이트 번호,r 이면 룰 번호를 나타냄.
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
	//Goto그래프의 헤더, 파싱 액션, 파싱 goto테이블 선언
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


