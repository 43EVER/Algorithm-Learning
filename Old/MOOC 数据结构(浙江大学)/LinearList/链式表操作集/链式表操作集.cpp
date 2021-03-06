// 链式表操作集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		if (L == ERROR) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			L = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (L == ERROR)
				printf("Wrong Answer or Empty List.\n");
		}
	}
	L = Insert(L, X, NULL);
	if (L == ERROR) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	tmp = Insert(L, X, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	tmp = Delete(L, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
	return 0;
}

Position Find(List L, ElementType X)
{
	PtrToLNode temp = L;
	while (temp != NULL)
	{
		if (temp->Data == X)
			return temp;
		temp = temp->Next;
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

List Insert(List L, ElementType X, Position P)
{
	if (L == P)
		return NewNode(X, P);
	
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
		return L;
	}

	printf("Wrong Position for Insertion\n");
	return ERROR;

}

List Delete(List L, Position P)
{
	List *p = &L;
	for (; *p; p = &((*p)->Next))
	{
		List entry = *p;
		if (entry == P)
		{
			*p = entry->Next;
			free(entry);
			return L;
		}
	}

	printf("Wrong Position for Deletion\n");
	return ERROR;
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
