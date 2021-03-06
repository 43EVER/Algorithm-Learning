// 顺序表操作集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		if (Insert(L, X, 0) == false)
			printf(" Insertion Error: %d is not in.\n", X);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
			printf("%d is at position %d.\n", X, P);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &P);
		if (Delete(L, P) == false)
			printf(" Deletion Error.\n");
		if (Insert(L, 0, P) == false)
			printf(" Insertion Error: 0 is not in.\n");
	}
	return 0;
}

List MakeEmpty()
{
	List NewList = (List)malloc(sizeof(struct LNode));
	NewList->Last = -1;

	return NewList;
}

Position Find(List L, ElementType X)
{
	for (int i = 0; i <= L->Last && i < MAXSIZE; i++)
	{
		if (L->Data[i] == X)
			return i;
	}

	return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
	if (L->Last == MAXSIZE - 1)
	{
		printf("FULL");
		return false;
	}
	if (P > L->Last + 1 || P >= MAXSIZE || P < 0)
	{
		printf("ILLEGAL POSITION");
		return false;
	}

	for (int i = L->Last + 1; i > P; i--)
		L->Data[i] = L->Data[i - 1];
	L->Data[P] = X;
	L->Last += 1;

	return true;
}

bool Delete(List L, Position P)
{
	if (P > L->Last || P < 0 || L->Last == -1)
	{
		printf("POSITION %d EMPTY", P);
		return false;
	}

	for (int i = P; i < L->Last; i++)
		L->Data[i] = L->Data[i + 1];
	L->Last -= 1;

	return true;
}