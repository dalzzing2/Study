#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node Node;
typedef struct Leaf Leaf;

FILE *file = fopen("output.txt","wt");

struct Node{			//배열값과 부모, 자식을 연결하기 위한 노드 자료구조 
	int element[4][4];
	float fnvalue;		//평가함수값 저장 
	int depth;			//노드의 깊이값 저장 
	int unfold;			//자식을 확장한 노드의 판별을 위한 정수값 

	Node *parent;		//부모 노드를 가리키는 포인터 
	Node *child[4];		//자식 노드를 가리키는 포인터 
};


struct Leaf{			//모든 노드들을 단순 연결 리스트로 가리키는 포인터 변수를 위한 자료구조 
	Node *leaf;			//트리의 각 노드를 가리킴 
	Leaf *next;			//다음 노드를 가리키는 포인터 	
};

float CalcFnValue(Node *);
void Init(Node *, int array[4][4]);
void CopyAndReset(Node *, Node *);
int Same(Node *, int ary[4][4]);
void PrintBoard(Node *);
int DuplicateAll(Node *);
void Swap(int *, int *);
void MakeChildren(Node *);
void StoreLeaf(Node *);
Node *ChooseBestNode(void);

Node *Root;		//초기 루트 노드 선언(전역 변수)
Node *Current;	//임시 포인터 변수
Leaf *Support;	//모든 노드들을 저장하기 위한 대표 포인터 
Leaf *Last;		//Support 리스트의 끝 노드를 가리킴(계속 이어서 연결하기 위함)

int	startnode[4][4];	//목표 상태
int goalnode[4][4];		//  초기 문제 저장 

int ChildNum=0;		// 확장된 노드수를 카운트하기 위한 전역 변수 

int cord[17][2] = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2},{3,3}};

//평가함수값
float CalcFnValue(Node *node){
	int i, j, count = 0, temp_dist=0, dist_sum=0;
	float fnvalue, fdist=0.0;


	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(node->element[i][j] != startnode[i][j]){
				count++;
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){

			if(node->element[i][j] != 0){

				fdist = fdist + (float)pow(abs(cord[node->element[i][j]][0] - i) + abs(cord[node->element[i][j]][1] - j),(float)2); 
			}

		}
	}
	fnvalue = fdist ;
	return fnvalue;
}


///// 초기 루트 노드를 문제의 배열 형태로 입력하고 각 포인터를 NULL로 만드는 초기화 함수 /////
void Init(Node *node, int array[4][4]){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			node->element[i][j] = array[i][j];
		}
	}

	node->depth = 0;
	node->fnvalue = CalcFnValue(node);	///초기 평가함수값을 설정
	node->unfold = 0;

	node->parent = NULL;

	for(int i=0;i<4;i++){
		node->child[i] = NULL;
	}


}

///// 자식 노드를 만들기 위해 우선 부모의 배열값을 그대로 복사하고 나머지 변수들을 초기화하는 함수 /////
void CopyAndReset(Node *node, Node *temp){

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			temp->element[i][j] = node->element[i][j];
		}
	}

	temp->fnvalue = -1.0;	///초기 평가함수값을 0으로 임의 설정
	temp->depth = 0;
	temp->unfold = 0;

	temp->parent = NULL;

	for(int i=0;i<4;i++){
		temp->child[i] = NULL;
	}


}


///// 현재 노드의 배열 상태가 ary[4][4]로 주어지는 배열 형태와 같은지를 확인해서 같으면 1 리턴, 아니면 0 리턴 /////
int Same(Node *node1, int ary[4][4]){

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(node1->element[i][j] != ary[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

///// 현재 넘겨지는 파라메터 노드의 배열 형태를 화면에 출력하는 함수 /////
void PrintBoard(Node *node){

	printf("┌─┬─┬─┬─┐\n");
	printf("│%2d│%2d│%2d│%2d│\n", node->element[0][0], node->element[0][1], node->element[0][2], node->element[0][3]);
	printf("├─┼─┼─┼─┤\n");
	printf("│%2d│%2d│%2d│%2d│\n", node->element[1][0], node->element[1][1], node->element[1][2], node->element[1][3]);
	printf("├─┼─┼─┼─┤\n");
	printf("│%2d│%2d│%2d│%2d│\n", node->element[2][0], node->element[2][1], node->element[2][2], node->element[2][3]);
	printf("├─┼─┼─┼─┤\n");
	printf("│%2d│%2d│%2d│%2d│\n", node->element[3][0], node->element[3][1], node->element[3][2], node->element[3][3]);
	printf("└─┴─┴─┴─┘\n");

	fprintf(file,"┌─┬─┬─┬─┐\n");
	fprintf(file,"│%2d│%2d│%2d│%2d│\n", node->element[0][0], node->element[0][1], node->element[0][2], node->element[0][3]);
	fprintf(file,"├─┼─┼─┼─┤\n");
	fprintf(file,"│%2d│%2d│%2d│%2d│\n", node->element[1][0], node->element[1][1], node->element[1][2], node->element[1][3]);
	fprintf(file,"├─┼─┼─┼─┤\n");
	fprintf(file,"│%2d│%2d│%2d│%2d│\n", node->element[2][0], node->element[2][1], node->element[2][2], node->element[2][3]);
	fprintf(file,"├─┼─┼─┼─┤\n");
	fprintf(file,"│%2d│%2d│%2d│%2d│\n", node->element[3][0], node->element[3][1], node->element[3][2], node->element[3][3]);
	fprintf(file,"└─┴─┴─┴─┘\n");
}

///// 이미 생성된 모든 기존 노드와 중복이 있는지 검사. 중복되는 것이 있으면 1 리턴, 없으면 0 리턴 /////
int DuplicateAll(Node *node){

	int dup=0;
	Leaf *trace;

	trace = Support;
	
	while(trace){

		if(Same(node, trace->leaf->element)){
			dup = 1;
			break;
		}

		trace = trace->next;
	}

	return dup;
}
	
///// 자식 노드의 배열값에 대해 빈칸과 임의의 숫자판 하나를 교환하기 위한 함수 /////
void Swap(int *a, int *b){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

///// 0으로 표현되는 빈칸을 하나 움직여서 다음 상태(자식) 노드를 가능한 개수만큼 만들어서 자식으로 연결하는 함수 /////
///// 이미 생성된 모든 노드들과 매번 비교하면서 중복이 없을 경우에만 생성함. /////
void MakeChildren(Node *node){

	int izero, jzero;
	Node *temp;


	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(node->element[i][j] == 0){
				izero = i;
				jzero = j;
				break;
			}
		}

	}

	if((izero == 1 || izero == 2) && (jzero == 1 || jzero == 2)){
	
		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);	// 부모 배열을 그대로 복사 

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);  //조각 하나를 움직이는 것 처럼 두 값을 교환 

		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);		// 중복된 경우이면 이미 할당한 메모리를 해제함 
		}
		else{
			node->child[i] = temp;
			ChildNum++;		// 노드가 생성될 때 마다 노드 확장수를 증가 
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((izero ==1 || izero == 2) && (jzero == 0)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}

	if((izero ==1 || izero == 2) && (jzero == 3)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((jzero ==1 || jzero == 2) && (izero == 0)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((jzero ==1 || jzero == 2) && (izero == 3)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}


		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}

	if((izero ==0) && (jzero == 0)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((izero ==0) && (jzero == 3)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero+1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((izero ==3) && (jzero == 0)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero+1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}


	if((izero ==3) && (jzero == 3)){

		int i=0;

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}

		temp = (Node *)malloc(sizeof(Node));

		CopyAndReset(node, temp);

		Swap(&temp->element[izero][jzero],&temp->element[izero][jzero-1]);
		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);
		}
		else{
			node->child[i] = temp;
			ChildNum++;
			i++;
		}
	}

	for(int i=0;i<4;i++){

		if(node->child[i]){

			node->child[i]->depth = node->depth + 1;		// 생성된 자식 노드들의 깊이값을 하나 증가 

			node->child[i]->fnvalue = CalcFnValue(node->child[i]);		//평가 함수값을 새로 계산하여 저장 
		}
	}

	node->unfold = 1;

}

///// 생성된 자식 노드들을 Support 리스트에 모두 매다는 함수 /////
void StoreLeaf(Node *current){

	int i;
	Leaf *templeaf;

	for(i = 0;i<4;i++){

		if(current->child[i]){

			templeaf = (Leaf *)malloc(sizeof(Leaf));		// 새로 생성된 노드들을 가리키기 위해 리스트 메모리 생성 

			Last->next = templeaf;
			templeaf->leaf = current->child[i];
			templeaf->next = NULL;
			Last = Last->next;

		}
	}
}

///// best first 탐색에 의해 비교 가능한 모든 후보 노드들의 평가값을 비교하여 가장 작은(좋은) 값을 가지는 노드를 선택 /////
///// 선택된 노드에 대한 포인터 주소가 리턴 /////
Node *ChooseBestNode(void){

	Leaf *trace, *best;
	Node *tempbest;
	float tempmin=9999999.0;

	trace = Support->next;

	while(trace){

		if((trace->leaf->fnvalue < tempmin) && trace->leaf->unfold == 0){
			best = trace;
			tempmin = trace->leaf->fnvalue;		
			// 펼쳐지지 않은 노드(unfold == 0인 노드)들 중에서 fnvalue가 가장 작은 노드를 찾음.
		}
		trace = trace->next;
	}

	tempbest = best->leaf;

	return tempbest;		//노드 주소 리턴 
}

void main(){

	

	printf("시작노드 : ");
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			scanf("%d", &startnode[i][j]);
	printf("목표노드 : ");
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			scanf("%d", &goalnode[i][j]);
	int ch, done;
	int de;
	Node *solution, *trace;


	Root = (Node *)malloc(sizeof(Node));	//초기 루트 노드에 메모리 할당
	Support = (Leaf *)malloc(sizeof(Leaf));	//초기 단순 연결 리스트에 메모리 할당 

	Init(Root, goalnode);			// 문제 상태로 루트 노드 설정 

	if(Same(Root, startnode)){		//초기 문제가 답과 같은 경우에는 바로 해결된 경우이므로 프로그램 종료 
		printf("Done!\n");
		return;
	}

	Current = Root;		//확장 대상의 노드를 가리키는 Current 포인터를 처음에는 루트를 가리키게 함

	Support->leaf = Root;
	Support->next = NULL;
	Last = Support;

	done = 0;

	do{

		MakeChildren(Current);		//자식 노드 생성 
		
		for(ch=0;ch<4;ch++){

			if(Current->child[ch]){
				if(Same(Current->child[ch], startnode)){		// 생성된 자식들 중에 해답이 있는지 찾고, 있으면 표시하고 루프 종료 
					solution = Current->child[ch]; 
					PrintBoard(solution);
					printf("탐색을 원하시니요? (yes=1/ exit=0) : ");
					scanf("%d", &de);
					if(de==0) {done=1; return;}
					done = 1;
					break;
				}
			}
		}

		if(done == 1){		// 해답이 찾아진 경우를 의미하고 이 때 do 반복문을 종료하도록 한다.
			break;
		}
		StoreLeaf(Current);		// 답이 없는 경우 생성된 Current의 자식들을 단순 연결 리스트가 가리키게 함.

		Current = ChooseBestNode();		// 다시 새로운 베스트 후보 노드를 선정 

	}while(1);


	getchar();

	trace = solution;	// 문제가 해결된 경우 solution 노드가 발견된 정답 노드를 가리킴. 이를 이용하여 정답부터 
						// 문제까지 역순으로 모든 보드 형태를 출력하기 위함  
	
	while(trace){		// 역순으로 보드를 출력하는 루틴 
		PrintBoard(trace);
		trace = trace->parent;
		getchar();
	}
	fclose(file);
	printf("Number of move required = %d\n", solution->depth);
}


