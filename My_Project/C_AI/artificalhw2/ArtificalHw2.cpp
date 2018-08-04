#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node Node;
typedef struct Leaf Leaf;

FILE *file = fopen("output.txt","wt");

struct Node{			//�迭���� �θ�, �ڽ��� �����ϱ� ���� ��� �ڷᱸ�� 
	int element[4][4];
	float fnvalue;		//���Լ��� ���� 
	int depth;			//����� ���̰� ���� 
	int unfold;			//�ڽ��� Ȯ���� ����� �Ǻ��� ���� ������ 

	Node *parent;		//�θ� ��带 ����Ű�� ������ 
	Node *child[4];		//�ڽ� ��带 ����Ű�� ������ 
};


struct Leaf{			//��� ������ �ܼ� ���� ����Ʈ�� ����Ű�� ������ ������ ���� �ڷᱸ�� 
	Node *leaf;			//Ʈ���� �� ��带 ����Ŵ 
	Leaf *next;			//���� ��带 ����Ű�� ������ 	
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

Node *Root;		//�ʱ� ��Ʈ ��� ����(���� ����)
Node *Current;	//�ӽ� ������ ����
Leaf *Support;	//��� ������ �����ϱ� ���� ��ǥ ������ 
Leaf *Last;		//Support ����Ʈ�� �� ��带 ����Ŵ(��� �̾ �����ϱ� ����)

int	startnode[4][4];	//��ǥ ����
int goalnode[4][4];		//  �ʱ� ���� ���� 

int ChildNum=0;		// Ȯ��� ������ ī��Ʈ�ϱ� ���� ���� ���� 

int cord[17][2] = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2},{3,3}};

//���Լ���
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


///// �ʱ� ��Ʈ ��带 ������ �迭 ���·� �Է��ϰ� �� �����͸� NULL�� ����� �ʱ�ȭ �Լ� /////
void Init(Node *node, int array[4][4]){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			node->element[i][j] = array[i][j];
		}
	}

	node->depth = 0;
	node->fnvalue = CalcFnValue(node);	///�ʱ� ���Լ����� ����
	node->unfold = 0;

	node->parent = NULL;

	for(int i=0;i<4;i++){
		node->child[i] = NULL;
	}


}

///// �ڽ� ��带 ����� ���� �켱 �θ��� �迭���� �״�� �����ϰ� ������ �������� �ʱ�ȭ�ϴ� �Լ� /////
void CopyAndReset(Node *node, Node *temp){

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			temp->element[i][j] = node->element[i][j];
		}
	}

	temp->fnvalue = -1.0;	///�ʱ� ���Լ����� 0���� ���� ����
	temp->depth = 0;
	temp->unfold = 0;

	temp->parent = NULL;

	for(int i=0;i<4;i++){
		temp->child[i] = NULL;
	}


}


///// ���� ����� �迭 ���°� ary[4][4]�� �־����� �迭 ���¿� �������� Ȯ���ؼ� ������ 1 ����, �ƴϸ� 0 ���� /////
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

///// ���� �Ѱ����� �Ķ���� ����� �迭 ���¸� ȭ�鿡 ����ϴ� �Լ� /////
void PrintBoard(Node *node){

	printf("������������������\n");
	printf("��%2d��%2d��%2d��%2d��\n", node->element[0][0], node->element[0][1], node->element[0][2], node->element[0][3]);
	printf("������������������\n");
	printf("��%2d��%2d��%2d��%2d��\n", node->element[1][0], node->element[1][1], node->element[1][2], node->element[1][3]);
	printf("������������������\n");
	printf("��%2d��%2d��%2d��%2d��\n", node->element[2][0], node->element[2][1], node->element[2][2], node->element[2][3]);
	printf("������������������\n");
	printf("��%2d��%2d��%2d��%2d��\n", node->element[3][0], node->element[3][1], node->element[3][2], node->element[3][3]);
	printf("������������������\n");

	fprintf(file,"������������������\n");
	fprintf(file,"��%2d��%2d��%2d��%2d��\n", node->element[0][0], node->element[0][1], node->element[0][2], node->element[0][3]);
	fprintf(file,"������������������\n");
	fprintf(file,"��%2d��%2d��%2d��%2d��\n", node->element[1][0], node->element[1][1], node->element[1][2], node->element[1][3]);
	fprintf(file,"������������������\n");
	fprintf(file,"��%2d��%2d��%2d��%2d��\n", node->element[2][0], node->element[2][1], node->element[2][2], node->element[2][3]);
	fprintf(file,"������������������\n");
	fprintf(file,"��%2d��%2d��%2d��%2d��\n", node->element[3][0], node->element[3][1], node->element[3][2], node->element[3][3]);
	fprintf(file,"������������������\n");
}

///// �̹� ������ ��� ���� ���� �ߺ��� �ִ��� �˻�. �ߺ��Ǵ� ���� ������ 1 ����, ������ 0 ���� /////
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
	
///// �ڽ� ����� �迭���� ���� ��ĭ�� ������ ������ �ϳ��� ��ȯ�ϱ� ���� �Լ� /////
void Swap(int *a, int *b){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

///// 0���� ǥ���Ǵ� ��ĭ�� �ϳ� �������� ���� ����(�ڽ�) ��带 ������ ������ŭ ���� �ڽ����� �����ϴ� �Լ� /////
///// �̹� ������ ��� ����� �Ź� ���ϸ鼭 �ߺ��� ���� ��쿡�� ������. /////
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

		CopyAndReset(node, temp);	// �θ� �迭�� �״�� ���� 

		Swap(&temp->element[izero][jzero],&temp->element[izero-1][jzero]);  //���� �ϳ��� �����̴� �� ó�� �� ���� ��ȯ 

		temp->parent = node;

		if(DuplicateAll(temp)){
			free(temp);		// �ߺ��� ����̸� �̹� �Ҵ��� �޸𸮸� ������ 
		}
		else{
			node->child[i] = temp;
			ChildNum++;		// ��尡 ������ �� ���� ��� Ȯ����� ���� 
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

			node->child[i]->depth = node->depth + 1;		// ������ �ڽ� ������ ���̰��� �ϳ� ���� 

			node->child[i]->fnvalue = CalcFnValue(node->child[i]);		//�� �Լ����� ���� ����Ͽ� ���� 
		}
	}

	node->unfold = 1;

}

///// ������ �ڽ� ������ Support ����Ʈ�� ��� �Ŵٴ� �Լ� /////
void StoreLeaf(Node *current){

	int i;
	Leaf *templeaf;

	for(i = 0;i<4;i++){

		if(current->child[i]){

			templeaf = (Leaf *)malloc(sizeof(Leaf));		// ���� ������ ������ ����Ű�� ���� ����Ʈ �޸� ���� 

			Last->next = templeaf;
			templeaf->leaf = current->child[i];
			templeaf->next = NULL;
			Last = Last->next;

		}
	}
}

///// best first Ž���� ���� �� ������ ��� �ĺ� ������ �򰡰��� ���Ͽ� ���� ����(����) ���� ������ ��带 ���� /////
///// ���õ� ��忡 ���� ������ �ּҰ� ���� /////
Node *ChooseBestNode(void){

	Leaf *trace, *best;
	Node *tempbest;
	float tempmin=9999999.0;

	trace = Support->next;

	while(trace){

		if((trace->leaf->fnvalue < tempmin) && trace->leaf->unfold == 0){
			best = trace;
			tempmin = trace->leaf->fnvalue;		
			// �������� ���� ���(unfold == 0�� ���)�� �߿��� fnvalue�� ���� ���� ��带 ã��.
		}
		trace = trace->next;
	}

	tempbest = best->leaf;

	return tempbest;		//��� �ּ� ���� 
}

void main(){

	

	printf("���۳�� : ");
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			scanf("%d", &startnode[i][j]);
	printf("��ǥ��� : ");
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			scanf("%d", &goalnode[i][j]);
	int ch, done;
	int de;
	Node *solution, *trace;


	Root = (Node *)malloc(sizeof(Node));	//�ʱ� ��Ʈ ��忡 �޸� �Ҵ�
	Support = (Leaf *)malloc(sizeof(Leaf));	//�ʱ� �ܼ� ���� ����Ʈ�� �޸� �Ҵ� 

	Init(Root, goalnode);			// ���� ���·� ��Ʈ ��� ���� 

	if(Same(Root, startnode)){		//�ʱ� ������ ��� ���� ��쿡�� �ٷ� �ذ�� ����̹Ƿ� ���α׷� ���� 
		printf("Done!\n");
		return;
	}

	Current = Root;		//Ȯ�� ����� ��带 ����Ű�� Current �����͸� ó������ ��Ʈ�� ����Ű�� ��

	Support->leaf = Root;
	Support->next = NULL;
	Last = Support;

	done = 0;

	do{

		MakeChildren(Current);		//�ڽ� ��� ���� 
		
		for(ch=0;ch<4;ch++){

			if(Current->child[ch]){
				if(Same(Current->child[ch], startnode)){		// ������ �ڽĵ� �߿� �ش��� �ִ��� ã��, ������ ǥ���ϰ� ���� ���� 
					solution = Current->child[ch]; 
					PrintBoard(solution);
					printf("Ž���� ���ϽôϿ�? (yes=1/ exit=0) : ");
					scanf("%d", &de);
					if(de==0) {done=1; return;}
					done = 1;
					break;
				}
			}
		}

		if(done == 1){		// �ش��� ã���� ��츦 �ǹ��ϰ� �� �� do �ݺ����� �����ϵ��� �Ѵ�.
			break;
		}
		StoreLeaf(Current);		// ���� ���� ��� ������ Current�� �ڽĵ��� �ܼ� ���� ����Ʈ�� ����Ű�� ��.

		Current = ChooseBestNode();		// �ٽ� ���ο� ����Ʈ �ĺ� ��带 ���� 

	}while(1);


	getchar();

	trace = solution;	// ������ �ذ�� ��� solution ��尡 �߰ߵ� ���� ��带 ����Ŵ. �̸� �̿��Ͽ� ������� 
						// �������� �������� ��� ���� ���¸� ����ϱ� ����  
	
	while(trace){		// �������� ���带 ����ϴ� ��ƾ 
		PrintBoard(trace);
		trace = trace->parent;
		getchar();
	}
	fclose(file);
	printf("Number of move required = %d\n", solution->depth);
}


