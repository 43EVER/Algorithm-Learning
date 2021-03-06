// 二叉搜索树的操作集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT) /* 先序遍历，由裁判实现，细节不表 */
{
	if (!BT) return;
	
	printf("%d ", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}
void InorderTraversal(BinTree BT)  /* 中序遍历，由裁判实现，细节不表 */
{
	if (!BT) return;

	InorderTraversal(BT->Left);
	printf("%d ", BT->Data);
	InorderTraversal(BT->Right);
}

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) {
		BinTree temp = (BinTree)malloc(sizeof(struct TNode));
		temp->Left = NULL;
		temp->Right = NULL;
		temp->Data = X;
		return temp;
	}

	if (X < BST->Data)
		BST->Left = Insert(BST->Left, X);
	else
		BST->Right = Insert(BST->Right, X);

	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	if (!BST) {
		printf("Not Found\n");
		return NULL;
	}

	if (X < BST->Data)
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)
		BST->Right = Delete(BST->Right, X);
	else {
		if (BST->Left && BST->Right) {
			BinTree tmp = FindMax(BST->Left);
			BST->Data = tmp->Data;
			BST->Left = Delete(BST->Left, BST->Data);
		}
		else {
			BinTree tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(tmp);
		}
	}

	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	if (!BST)
		return NULL;

	if (X < BST->Data)
		return Find(BST->Left, X);
	else if (X > BST->Data)
		return Find(BST->Right, X);
	else
		return BST;
}

Position FindMin(BinTree BST)
{
	if (!BST)
		return NULL;

	if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if (!BST)
		return NULL;
	
	if (!BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
}
