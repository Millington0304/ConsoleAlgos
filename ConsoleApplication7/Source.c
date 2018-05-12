#include <stdio.h>//For Win32 Debug
#include <stdlib.h>//For Win32 Debug
#include <time.h>//For Win32 Debug

typedef int ElemType;
/*
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode *lchild, *rchild;
}BiTree;
*/
typedef struct RBTreeNode
{
	ElemType data;
	struct RBTreeNode *lchild, *rchild, *parent;
	char isRed;
}RBNode;

typedef struct RBTree
{
	RBNode *root, *nil;
}Tree;
/*
BiTree *pbt;//Points To Root Node

void CreateEmptyBiTree(BiTree* param,ElemType iniValue);
BiTree *CreateBiTree();
void InOrderTraverse(BiTree* param);

void InsertRB(RBNode* root, ElemType val);
RBNode* findRoot(RBNode* oldRoot);
void CreateEmptyRBTree(RBNode* param, ElemType iniValue);
*/
void InOrderTraverseRB( RBNode* param,RBNode* nil);
void PreOrderTraverseRB(Tree*t,RBNode* param);

static int arr_[100000];
static int loc = 0;

Tree* InitNewRBTree(Tree* param);
void RBInsert(Tree* t, ElemType val);
void RBInsertFixup(Tree* t, RBNode* z);
//void RBDelete(Tree* t, RBNode* z);
void RBDelete(Tree*t, RBNode* z);
//void RBTransplant(Tree* t, RBNode* u, RBNode* v);
RBNode* TreeMin(Tree* t,RBNode* x);
//void RBDeleteFixup(Tree* t, RBNode* x);
void RBDeleteFixUp(RBNode* x, Tree* t);
RBNode* RBSearch(Tree*t, RBNode* x, ElemType key);

void radixSort(int data[], int n);
void quickSort(int data[], int low, int high);
void mergeSort(int data[], int first, int last);
void merge(int data[], int low, int mid, int high);
void bubleSort(int data[], int n);//DON'T USE!!! DO NOT EVER USE THIS!
int main()
{
	/*
	pbt = malloc(sizeof(BiTree));
	CreateBiTree(pbt, 0);
	printf("%d\n",pbt->data);
	*/

	/*
	pbt = CreateBiTree();
	printf("----------\n");
	InOrderTraverse(pbt);
	*/

	/*
	RBNode* root = malloc(sizeof(RBNode));
	CreateEmptyRBTree(root,5);
	InsertRB(root, 1);
	InsertRB(root, 2);
	InsertRB(root, 3);
	//InsertRB(root, 7);
	InsertRB(root, 4);

	PreOrderTraverseRB(root);
	printf("-------------------\n");
	InOrderTraverseRB(root);
	*/

	/*
	Tree* rbTree = malloc(sizeof(Tree));
	rbTree = InitNewRBTree(rbTree);
	RBInsert(rbTree, 101);
	RBInsert(rbTree, 130);
	for (size_t i = 0; i < 12; i++)
	{
		RBInsert(rbTree, i);
	}
	RBDelete(rbTree, rbTree->root);
	//InOrderTraverseRB(rbTree, rbTree->root);
	printf("%d\n", TreeMin(rbTree,rbTree->root)->data);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	PreOrderTraverseRB(rbTree, rbTree->root);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("%d,%d", RBSearch(rbTree, rbTree->root, 6)->parent->data, RBSearch(rbTree, rbTree->root, 6)->isRed);
	*/

	/*
	int arr1[100000] = { 0 }, arr0[100000] = { 0 }; //arr[100000] = { 0 };
	//*arr = malloc(1000000 * sizeof(int));
	//*arr0 = malloc(1000000 * sizeof(int));
	for (int i = 0; i < 100000; i++)
	{
		arr1[i] = arr0[i] = rand();
		//arr[i] = arr0[i] = (100000 - i);
	}
	//_sleep(100);
	clock_t start, end;
	start = clock();
	//radixSort(arr, 100000);
	end = clock();
	for (size_t i = 0; i < 50; i++)
	{
	//	printf("%d\t", arr[i]);
	}
	printf("\n%f ms", (double)(end - start));

	start = clock();
	mergeSort(arr0, 0, 99999);
	end = clock();
	for (size_t i = 0; i < 50; i++)
	{
		printf("%d\t", arr0[i]);
	}
	printf("\n%f ms", (double)(end - start));

	//_sleep(100);
	start=clock();
	quickSort(arr0, 0, 99999);
	end = clock();
	for (size_t i = 0; i < 50; i++)
	{
		printf("%d\t", arr0[i]);
	}
	printf("\n%f ms", (double)(end - start));
	*/

	int arr1[100000] = { 0 };

	for (int i = 0; i < 100000; i++)
	{
		
		arr1[i] = rand();
	}
	Tree* rbTree = malloc(sizeof(Tree));
	rbTree = InitNewRBTree(rbTree);

	clock_t start, end;

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		RBInsert(rbTree, arr1[i]);
	}


	//quickSort(arr1, 0, 99999);
	end = clock();
	printf("\n%f ms", (double)(end - start));
	start = clock();
	InOrderTraverseRB(rbTree->root/*->lchild->lchild->lchild->lchild->lchild->lchild->lchild->lchild->lchild->lchild*/,rbTree->nil);
	end = clock();
	printf("\n%f ms", (double)(end - start));

	for (size_t i = 0; i < 50; i++)
	{
		printf("%d", arr_[i]);
	}

	start = clock();
	bubleSort(arr1, 100000);
	end = clock();
	printf("\n%f ms", (double)(end - start));

	for (size_t i = 0; i < 50; i++)
	{
		printf("%d", arr1[i]);
	}
	system("pause");
}


/*
void CreateEmptyBiTree(BiTree* param,ElemType iniValue)
{
	param->data = iniValue;
	param->lchild = param->rchild = NULL;
}

BiTree *CreateBiTree()
{
	BiTree *bt;
	ElemType x;

	scanf_s("%d", &x);
	if (x == 0)
		bt = NULL;
	else
	{
		bt = malloc(sizeof(BiTree));
		bt->data = x;
		bt->lchild = CreateBiTree();
		bt->rchild = CreateBiTree();
	}
	return bt;
}	//PreOrderMethod

void InOrderTraverse(BiTree* param)
{
	if (param != NULL)
	{
		InOrderTraverse(param->lchild);
		printf("%d\n", param->data);
		InOrderTraverse(param->rchild);
	}
	else
		printf("0\n");
}



BiTree* SearchBiSTree(BiTree* param,ElemType val)
{
	if (param == NULL)
		return NULL;
	if (param->data > val)
		return SearchBiSTree(param->lchild, val);
	else if (param->data < val)
		return SearchBiSTree(param->rchild, val);
	else
		return param;
}

BiTree*	InsertBiSTree(BiTree* param,ElemType val)
{
	if (param == NULL)	//EOTree
	{
		param = malloc(sizeof(BiTree));
		if (param == NULL)
		{
			printf("OOMemory!\n");
		}
		else
		{
			CreateEmptyBiTree(param, val);
		}
	}
	else if(param->data>val)
	{
		param->lchild = InsertBiSTree(param->lchild, val);
	}
	else if(param->data<val)
	{
		param->rchild = InsertBiSTree(param->rchild, val);
	}
	//Already Exists!
	
	return param;
	
}



void CreateEmptyRBTree(RBNode* param, ElemType iniValue)
{
	param->data = iniValue;
	param->parent = param->lchild = param->rchild = NULL;
	param->isRed = 0;
}

void CreateNewNode(RBNode* parent, RBNode* location, ElemType inivalue)
{
	location->data = inivalue;
	location->parent = parent;
	if (parent->data>inivalue)  parent->lchild = location;else  parent->rchild = location;
	location->lchild = location->rchild = NULL;
	location->isRed = 0;
}

RBNode*	InsertRBTreeNormal(RBNode* parent,RBNode* param, ElemType val)
{
	if (param == NULL)	//EOTree
	{
		param = malloc(sizeof(RBNode));
		if (param == NULL)
		{
			printf("OOMemory!\n");
		}
		else
		{
			CreateNewNode(parent,param, val);
		}
	}
	else if (param->data>val)
	{
		param->lchild = InsertRBTreeNormal(param,param->lchild, val);
		return param->lchild;
	}
	else if (param->data<val)
	{
		param->rchild = InsertRBTreeNormal(param,param->rchild, val);
		return param->rchild;
	}
	//Already Exists!

	return param;

}
*/
void InOrderTraverseRB(RBNode* param,RBNode* nil)
{
	if (param!=nil)
	{
		InOrderTraverseRB(param->lchild,nil);
		//printf("%d\n", param->data);
		arr_[loc] = param->data;
		loc++;
		InOrderTraverseRB(param->rchild,nil);
	}
	//else
		//printf("nil\n");
}

void PreOrderTraverseRB(Tree* t,RBNode* param)
{
	if (param != t->nil)
	{
		printf("%d,%d\n", param->data,param->isRed);
		PreOrderTraverseRB(t,param->lchild);
		PreOrderTraverseRB(t,param->rchild);
	}
	else
		printf("nil\n");
}
/*
//Often Used && Improvement Required!
void RecolorRB(RBNode* param,char startRed)
{
	param->parent->isRed = startRed;
	param->parent->rchild->isRed = param->parent->lchild->isRed = !startRed;
}

RBNode* RotateRB(RBNode* param, char rotateLeft)
{
	if (rotateLeft)	//ROTATE LEFT
	{
		RBNode* tmpPointer=malloc(sizeof(RBNode*));
		RBNode* tmpPt = malloc(sizeof(RBNode*));
		if (param->parent->lchild == param) //Left Child Of Parent
		{ 
			tmpPointer = param->rchild;
			tmpPt = param->parent->parent;
			if (tmpPointer != NULL)
			tmpPointer->parent = param->parent;
			param->parent->lchild = tmpPointer;
			if (tmpPointer != NULL)
			
				param->rchild = tmpPointer->parent;
			if(param->rchild!=NULL)
				param->rchild->parent = param;
			
			param->parent = tmpPt;
			if (tmpPointer != NULL)
			tmpPointer->lchild = param;
		}
		else								//Right Child Of Parent
		{
			tmpPointer = param->rchild;
			if(tmpPointer!=NULL)
			tmpPointer->parent = param->parent;//
			param->parent->rchild = tmpPointer;//
			if(tmpPointer!=NULL)
			param->rchild = tmpPointer->lchild;//
			param->rchild->parent = param;//
			param->parent = tmpPointer;//
			if(tmpPointer!=NULL)
			tmpPointer->lchild = param;//
		}
		free(tmpPointer);
		free(tmpPt);
	}
	else			//ROTATE RIGHT
	{
		RBNode* tmpPointer = malloc(sizeof(RBNode*));
		if (param->parent->rchild == param) //Left Child Of Parent
		{
			tmpPointer = param->lchild;
			tmpPointer->parent = param->parent;
			param->parent->rchild = tmpPointer;
			param->lchild = tmpPointer->rchild;
			param->lchild->parent = param;
			param->parent = tmpPointer;
			tmpPointer->rchild = param;
		}
		else								//Right Child Of Parent
		{
			tmpPointer = param->lchild;
			tmpPointer->parent = param->parent;//
			param->parent->lchild = tmpPointer;//
			param->lchild = tmpPointer->rchild;//
			param->lchild->parent = param;//
			param->parent = tmpPointer;//
			tmpPointer->rchild = param;//
		}
		free(tmpPointer);
	}
	return param;
}


void InsertRB(RBNode* root, ElemType val)
{
	RBNode* currentLoc;
	if (val < root->data)
	{
		currentLoc = InsertRBTreeNormal(root, root->lchild, val);
	}
	else if (val > root->data)
	{
		currentLoc = InsertRBTreeNormal(root, root->rchild, val);
	}
	else
		return;//ROOT=VAL! IGNORE

	currentLoc->isRed = 1;
	while (currentLoc != root&&currentLoc->parent->isRed)
	{
		//if (currentLoc->parent->parent == NULL) goto END;
		if (currentLoc->parent == currentLoc->parent->parent->lchild)//BIG CASE ONE,LEFT
		{
			if (currentLoc->parent->parent->rchild!=NULL&&currentLoc->parent->parent->rchild->isRed==1)	//CASE ONE
			{
				RecolorRB(currentLoc->parent->parent, 1);//Recolor, GrandParent=Red
				currentLoc = currentLoc->parent->parent;//Move Up 2 units
			}
			else
			{
				if (currentLoc = currentLoc->parent->rchild)//ZIG-ZAG	CASE TWO
				{
					currentLoc=RotateRB(currentLoc->parent, 1);
				}
				//ZIG-ZIG	CASE THREE
				RotateRB(currentLoc->parent->parent, 0);
				RecolorRB(currentLoc->parent,0);
			}
		}
		else														//BIG CASE TWO,RIGHT
		{
			if (currentLoc->parent->parent->lchild->isRed)	//CASE ONE
			{
				RecolorRB(currentLoc->parent->parent, 1);//Recolor, GrandParent=Red
				currentLoc = currentLoc->parent->parent;//Move Up 2 units
			}
			else
			{
				if (currentLoc = currentLoc->parent->lchild)//ZIG-ZAG	CASE TWO
				{
					RotateRB(currentLoc->parent, 0);
				}
				//ZIG-ZIG	CASE THREE
				RotateRB(currentLoc->parent->parent, 1);
				RecolorRB(currentLoc->parent, 0);
			}
		}
	}
	root = findRoot(root);
	root->isRed = 0;
}

RBNode* findRoot(RBNode* oldRoot)
{
	while (oldRoot->parent!=NULL)
	{
		oldRoot = oldRoot->parent;
	}
	return oldRoot;
}

*/

RBNode* TreeMin(Tree*t, RBNode* x)
{
	//RBNode* x = t->root;
	if (x == t->nil)//EMPTY TREE?!
		return 0;
	while (x->lchild != t->nil)
	{
		x = x->lchild;
	}
	return x;
}

Tree* InitNewRBTree(Tree* param)
{
	param->root = malloc(sizeof(RBNode));
	param->nil = malloc(sizeof(RBNode));
	/*param->root->data =*/ param->nil->data = -1;
	//param->root->parent= param->root->lchild = param->root->rchild = param->nil;
	param->nil->parent = param->nil->lchild = param->nil->rchild = param->root;
	/*param->root->isRed =*/ param->nil->isRed = 0;
	param->root = param->nil;
	return param;
}

void Rotate(RBNode* x, Tree* T, char left)
{
	RBNode* y;
	if (left)
	{
		y = x->rchild;
		x->rchild = y->lchild;
		if (y->lchild != T->nil)
			y->lchild->parent = x;
		y->parent = x->parent;
		if (x->parent == T->nil)
			T->root = y;
		else if (x == x->parent->lchild)
			x->parent->lchild = y;
		else
			x->parent->rchild = y;
		y->lchild = x;
		x->parent = y;
	}
	else
	{
		y = x->lchild;
		x->lchild = y->rchild;
		if (y->rchild != T->nil)
			y->rchild->parent = x;
		y->parent = x->parent;
		if (x->parent == T->nil)
			T->root = y;
		else if (x == x->parent->rchild)
			x->parent->rchild = y;
		else
			x->parent->lchild = y;
		y->rchild = x;
		x->parent = y;
	}
}

void RBInsert(Tree* t,ElemType val)
{
	RBNode* y = t->nil;
	RBNode* x = t->root;
	RBNode *z = malloc(sizeof(RBNode));
	z->data = val;
	while (x != t->nil)
	{
		y = x;
		if (z->data<x->data)
			x = x->lchild;
		else
			x = x->rchild;
	}
	z->parent = y;
	if (y == t->nil)
	{
		t->root = z;
		//z->lchild = z->rchild = t->nil;
		//z->isRed = 0;
		//t->nil->lchild = t->nil->rchild = t->root;
		//return;
	}
	else if (z->data<y->data)
		y->lchild = z;
	else
		y->rchild = z;
	z->rchild = z->lchild = t->nil;
	z->isRed = 1;
	RBInsertFixup(t, z);
}

void RBInsertFixup(Tree* t, RBNode* z)
{
	while (z->parent->isRed)
	{
		if (z->parent == z->parent->parent->lchild)
		{
			RBNode*y = z->parent->parent->rchild;
			if (y->isRed)
			{
				z->parent->isRed = 0;
				y->isRed = 0;
				z->parent->parent->isRed = 1;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->rchild)
				{
					z = z->parent;
					Rotate(z, t, 1);
				}
				z->parent->isRed = 0;
				z->parent->parent->isRed = 1;
				Rotate(z->parent->parent, t, 0);
			}
		}
		else
		{
			RBNode*y = z->parent->parent->lchild;
			if (y->isRed)
			{
				z->parent->isRed = 0;
				y->isRed = 0;
				z->parent->parent->isRed = 1;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->lchild)
				{
					z = z->parent;
					Rotate(z, t, 0);
				}
				z->parent->isRed = 0;
				z->parent->parent->isRed = 1;
				Rotate(z->parent->parent, t, 1);
			}
		}
	}
	t->root->isRed = 0;
}

void RBTransplant(Tree*t,RBNode* u, RBNode* v)
{
	if (u->parent == t->nil)
		t->root = v;
	else if (u == u->parent->lchild)
		u->parent->lchild = v;
	else
		u->parent->rchild = v;
	v->parent = u->parent;
}

void RBDeleteFixUp(RBNode* x,Tree* t)
{
	while (x != t->root&&x->isRed == 0)
	{
		if (x == x->parent->lchild)///��x���丸������/�Һ��ӷ��������
		{///����Ĺ���Ҫ�����ֵܽ�����ɫ���з�������
			RBNode* w = x->parent->rchild; ///���ֵܽ��

									///Case 1
			if (w->isRed == 1)///����ֵܽ���Ǻ�ɫ
			{///��ʱ�����һ���Ǻ�ɫ���ڱ�֤�ڸߵ������
			 ///����ͨ��Ⱦɫ����תת�������ֵܽ��Ϊ��ɫ�����

				w->isRed = 0;
				x->parent->isRed = 1;
				Rotate(x->parent, t, 1);
				//LeftRotate(x->parent);
				w = x->parent->rchild;
			}

			///Case 2
			if (w->lchild->isRed == 0&&w->rchild->isRed == 0)
			{///ͨ��Ⱦɫ��x����һ��
				w->isRed = 1;
				x = x->parent; ///��x����������һ��,���x->p�Ǹ�����x->pԭ���Ǻ�ɫ�����ѭ��,����ת�����1
			}
			else ///���3,4
			{
				///Case 3
				if (w->rchild->isRed == 0)
				{///Ⱦɫ�����������4

					w->isRed = 1;
					w->lchild->isRed = 0;
					//RightRotate(w);
					Rotate(w, t, 0);
					w = x->parent->rchild;

					///Case 4
					///���4����ֱ�ӽ����ݹ�
					w->isRed = w->parent->isRed;
					w->parent->isRed = 0;
					w->rchild->isRed = 0; ///��Ҫ��w���Ҷ���Ⱦ�ɺ�ɫ�Ա�֤�ڸ�
					Rotate(x->parent,t,1);
					x = t->root;
					///break;
				}
			}
		}
		else ///����x�Ǹ������Ҷ��ӵ����
		{
			RBNode* w = x->parent->lchild;
			if (w->isRed == 1)
			{
				w->parent->isRed = 1;
				w->isRed = 0;
				//RightRotate(x->p);
				Rotate(x->parent, t, 0);
				w = x->parent->lchild;
			}
			else if (w->lchild->isRed == 0&&w->rchild->isRed == 0)
			{
				w->isRed = 1;
				x = x->parent;
			}
			else
			{
				if (w->lchild->isRed == 0)
				{
					w->rchild->isRed = 0;
					w->isRed = 1;
					//LeftRotate(w);
					Rotate(w, t, 1);
					w = x->parent->lchild;
				}
				w->isRed = x->parent->isRed;
				x->parent->isRed = 0;
				w->lchild->isRed = 0;
				Rotate(x->parent,t,0);
				x = t->root;
				///break
			}
		}
	}
	//����������
	x->isRed = 0;
}

void RBDelete(Tree*t,RBNode* z)
{ ///������Ĺ�����y����ָ�����лᱻɾ���Ľ����ǻᱻ����Ľ��
  ///x����ָ��Ҫ���z��y�Ľ��

	RBNode* x = NULL;
	RBNode* y = z;
	int ycolor = y->isRed; ///��¼yԭ������ɫ
	if (z->lchild == t->nil) ///ֻ���Ҷ���
	{
		x = z->rchild;
		RBTransplant(t,z, z->rchild);
	}
	else if (z->rchild == t->nil) ///ֻ�������
	{
		x = z->lchild;
		RBTransplant(t,z, z->lchild);
	}
	else  ///���Ҷ��Ӷ���
	{
		y = TreeMin(t,z->rchild); ///����z�ĺ��
		ycolor = y->isRed;
		x = y->rchild; ///��Ϊ����y�ᱻȾ��zԭ������ɫ,����Υ�����ʵľ���y���Ҷ���
		if (y->parent == z) ///y��z�ĺ��ӽ��
			x->parent = y;///���������,yΪx�ĸ����
		else ///y����z�ĺ��ӽ������
		{///����y���Һ���ȡ��y,Ȼ���ٸ���z���Һ��ӵ�ָ��
			RBTransplant(t,y, y->rchild);
			y->rchild = z->rchild;
			y->rchild->parent = y;
		}
		RBTransplant(t,z, y); ///yȡ��z
		y->lchild = z->lchild; ///z�����Ӹı�ָ��
		y->lchild->parent = y;
		y->isRed = z->isRed; ///����y����ɫ,�����Ļ���y���Ϻ���������ʶ�����Υ��
	}
	///���yԭ������ɫ�Ǻ�ɫ,��ô����ζ����һ����ɫ��㱻������,
	///����������ʿ��ܻᱻ�ƻ�(����4��5),��Ҫ����
	if (ycolor == 0)
		RBDeleteFixUp(x,t);
}

RBNode* RBSearch(Tree*t, RBNode* x,ElemType key)
{
	while (x != t->nil&& key != x->data)
	{
		if (key < x->data)
			x = x->lchild;
		else
			x = x->rchild;
	}
	return x;
}



int getNumPos(int num, int pos) {
	int i;
	int temp = 1;
	for (i = 0; i<pos - 1; i++) {
		temp *= 10;
	}
	return (num / temp) % 10;
}
void radixSort(int data[], int n) {
	int i, j, k, pos, num, index;
	//�⼸�仰�Ǵ���һ����0-9(��)�� (n+1)(��)�����񣬵�һ�д���������0-9,
	//�ڶ����Ǹ��а�����Ԫ�ظ�����Ĭ��Ϊ0��
	int *radixArrays[10];
	for (i = 0; i<10; i++) {
		radixArrays[i] = (int *)malloc(sizeof(int) * (n + 1));
		radixArrays[i][0] = 0;
	}
	//pos���Ϊ31Ϊ����������ܳ��ܵ����Χ��
	for (pos = 1; pos <= 31; pos++) {
		//��forѭ���ǽ������Ԫ�ذ���λ��(pos)��ֵ�Ž�������
		for (i = 0; i<n; i++) {
			num = getNumPos(data[i], pos);
			index = ++radixArrays[num][0];
			radixArrays[num][index] = data[i];
		}
		//��forѭ���ǽ������forѭ���Ѿ�����ĳ��λ��(pos)���кõ�Ԫ�ش�������
		for (i = 0, j = 0; i<10; i++) {
			for (k = 1; k <= radixArrays[i][0]; k++) {
				data[j++] = radixArrays[i][k];
			}
			//��������Ա���¸�λ������
			radixArrays[i][0] = 0;
		}
	}
}

int findPos(int data[], int low, int high) {
	//������t��Ԫ�ظϵ�t����ߣ�����t��Ԫ�ظϵ�t���ұ�
	int t = data[(low+high)/2];
	while (low < high) {
		while (low < high && data[high] >= t) {
			high--;
		}
		data[low] = data[high];
		while (low < high && data[low] <= t) {
			low++;
		}
		data[high] = data[low];
	}
	data[low] = t;
	//���ش�ʱt�������е�λ��
	return low;
}
//����������һ��Ԫ�أ��Դ��ڸ�Ԫ�غ�С�ڸ�Ԫ�ص������������������
//�ٶ����������Ϊ4�����飬������ֱ�����ÿ��ֻʣ��һ��Ԫ��Ϊֹ
void quickSort(int data[], int low, int high) {
	if (low > high) {
		return;
	}
	int pos = findPos(data, low, high);
	quickSort(data, low, pos - 1);
	quickSort(data, pos + 1, high);
}

void mergeSort(int data[], int first, int last) {
	int mid = 0;
	//�����鲻ͣ�Ķ��ַ�������ϣ�ֱ��ÿ��ֻʣһ��Ԫ��
	if (first < last) {
		mid = (first + last) / 2;
		mergeSort(data, first, mid);
		mergeSort(data, mid + 1, last);
		merge(data, first, mid, last);
	}
	return;
}
void merge(int data[], int low, int mid, int high) {
	int i, k;
	//����һ����ʱ�����Ŵ����������������ź���֮�������
	int *temp = (int *)malloc((high - low + 1) * sizeof(int));
	//����������ֳ���������
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	//���������бȽ�����С����ǰ
	for (k = 0; left_low <= left_high && right_low <= right_high; k++) {
		if (data[left_low] <= data[right_low]) {
			temp[k] = data[left_low++];
		}
		else {
			temp[k] = data[right_low++];
		}
	}
	//�����������ʣ��Ԫ��δ���򣬼ӵ���ʱ�����ĩβ
	if (left_low <= left_high) {
		for (i = left_low; i <= left_high; i++) {
			temp[k++] = data[i];
		}
	}
	//�����������ʣ��Ԫ��δ���򣬼ӵ���ʱ�����ĩβ
	if (right_low <= right_high) {
		for (i = right_low; i <= right_high; i++) {
			temp[k++] = data[i];
		}
	}
	//���ź����С����ת�Ƶ�ԭ������
	for (i = 0; i<high - low + 1; i++) {
		data[low + i] = temp[i];
	}
	free(temp);
	return;
}

void bubleSort(int data[], int n)	//DON'T USE! DON'T USE! DO NOT USE!
{
	int i, j, temp;
	for (j = 0; j<n - 1; j++) {
		for (i = 0; i<n - j - 1; i++) {
			if (data[i]>data[i + 1]) {
				temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
	}
}
/*
void RBDelete(Tree* t, RBNode* z)
{
	RBNode*x=NULL;
	RBNode*y = z;
	char y_original_isRed = y->isRed;
	if (z->lchild == t->nil)
	{
		x = z->rchild;
		RBTransplant(t, z, z->rchild);
	}
	else if (z->rchild == t->nil)
	{
		x = z->lchild;
		RBTransplant(t, z, z->lchild);
	}
	else
	{
		y = TreeMin(t, z->rchild);
		y_original_isRed = y->isRed;
		x = y->rchild;
		if (y->parent == z)
			x->parent = y;
		else
		{
			RBTransplant(t, y, y->rchild);
			y->rchild = z->rchild;
			y->rchild->parent = y;
		}
		RBTransplant(t, z, y);
		y->lchild = z->lchild;
		y->lchild->parent = y;
		y->isRed = z->isRed;
	}

	if (!y_original_isRed)//==Black
	{
		RBDeleteFixup(t, x);
	}
}

void RBTransplant(Tree* t, RBNode* u, RBNode* v)
{
	if (u->parent == t->nil)
		t->root = v;
	else if (u == u->parent->lchild)
		u->parent->lchild = v;
	else
		u->parent->rchild = v;
	v->parent = u->parent;
}

void RBDeleteFixup(Tree* t, RBNode* x)
{
	RBNode* w;
	if (x == t->nil)
	{
		if (t->root->rchild == t->nil)
		{
			Rotate(t->root->lchild, t, 1);
			t->root->rchild->isRed = 1;
			Rotate(t->root, t, 0);
			t->root->lchild->rchild->isRed = 0;
		}
		else
		{
			Rotate(t->root->rchild, t, 1);
			t->root->lchild->isRed = 1;
		}
	}
	while (x != t->root && !x->isRed)//IS BLACK
	{
		if (x == x->parent->lchild)
		{
			w = x->parent->rchild;
			if (w->isRed)								//Case 1
			{
				w->isRed = 0;
				x->parent->isRed = 1;
				Rotate(x->parent, t,1);
				w = x->parent->rchild;
			}
			if (!w->lchild->isRed && !w->rchild->isRed)//Both Black Case2
			{
				w->isRed = 1;
				x = x->parent;
			}
			else 
			{
				if (!w->rchild->isRed)//R==BLACK		Case3
				{
					w->lchild->isRed = 0;
					w->isRed = 1;
					Rotate(w, t, 0);
					w = x->parent->rchild;
				}
				w->isRed = x->parent->isRed;
				x->parent->isRed = 0;
				w->rchild->isRed = 0;
				Rotate(x->parent, t, 0);
				x = t->root;
			}
		}
		else
		{
			w = x->parent->rchild;
			if (w->isRed)								//Case 1
			{
				w->isRed = 0;
				x->parent->isRed = 1;
				Rotate(x->parent, t, 0);
				w = x->parent->lchild;
			}
			if (!w->rchild->isRed && !w->lchild->isRed)//Both Black Case2
			{
				w->isRed = 1;
				x = x->parent;
			}
			else
			{
				if (!w->lchild->isRed)//R==BLACK		Case3
				{
					w->rchild->isRed = 0;
					w->isRed = 1;
					Rotate(w, t, 1);
					w = x->parent->lchild;
				}
				w->isRed = x->parent->isRed;
				x->parent->isRed = 0;
				w->lchild->isRed = 0;
				Rotate(x->parent, t, 1);
				x = t->root;
			}
		}
	}
	x->isRed = 0;
}
*/