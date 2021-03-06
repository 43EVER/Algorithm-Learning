// 带头结点的链式表操作集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

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
	bool flag;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		flag = Insert(L, X, L->Next);
		if (flag == false) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			flag = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (flag == false)
				printf("Wrong Answer.\n");
		}
	}
	flag = Insert(L, X, NULL);
	if (flag == false) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	flag = Insert(L, X, P);
	if (flag == true) printf("Wrong Answer\n");
	flag = Delete(L, P);
	if (flag == true) printf("Wrong Answer\n");
	for (P = L->Next; P; P = P->Next) printf("%d ", P->Data);
	return 0;
}

List MakeEmpty()
{
	List temp = (List)malloc(sizeof(struct LNode));
	temp->Next = NULL;
	temp->Data = -0x3f3f3f3f;

	return temp;
}

Position Find(List L, ElementType X)
{
	List p = L->Next;
	while (p != NULL)
	{
		if (p->Data == X)
			return p;
		p = p->Next;
	}

	return ERROR;
}

List NewNode(ElementType X, Position Next)
{
	List temp = (List)malloc(sizeof(struct LNode));
	temp->Data = X;
	temp->Next = Next;

	return temp;
}

bool Insert(List L, ElementType X, Position P)
{
	List pre = L;
	List next = L->Next;
	while (next != P && next)
	{
		pre = next;
		next = next->Next;
	}

	if (next == P)
	{
		pre->Next = NewNode(X, next);
		return true;
	}

	printf("Wrong Position for Insertion\n");
	return false;
}

bool Delete(List L, Position P)
{
	List *p = &(L->Next);
	for (; *p; p = &((*p)->Next))
	{
		List entry = *p;
		if (entry == P)
		{
			*p = entry->Next;
			free(entry);
			return true;
		}
	}

	printf("Wrong Position for Deletion\n");
	return false;
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
