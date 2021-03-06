// 在一个数组中实现两个堆栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef int Position;
struct SNode {
	ElementType *Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main()
{
	int N, Tag, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d %d", &Tag, &X);
			if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
			break;
		case pop:
			scanf("%d", &Tag);
			X = Pop(S, Tag);
			if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
			break;
		case end:
			PrintStack(S, 1);
			PrintStack(S, 2);
			done = 1;
			break;
		}
	}
	return 0;
}

Stack CreateStack(int MaxSize)
{
	Stack stack = (Stack)malloc(sizeof(struct SNode));
	stack->Data = (int*)malloc(sizeof(int) * MaxSize);
	stack->MaxSize = MaxSize ;
	stack->Top1 = -1;
	stack->Top2 = MaxSize;

	return stack;
}

bool Push(Stack S, ElementType X, int Tag)
{
	if (S->Top2 - S->Top1 == 1)
	{
		printf("Stack Full\n");
		return false;
	}

	switch (Tag)
	{
	case 1:
		S->Data[++(S->Top1)] = X;
		break;
	case 2:
		S->Data[--(S->Top2)] = X;
		break;
	}

	return true;
}

ElementType Pop(Stack S, int Tag)
{
	switch (Tag)
	{
	case 1:
		if (S->Top1 < 0)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S->Data[(S->Top1)--];
	case 2:
		if (S->Top2 >= S->MaxSize)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR;
		}
		return S->Data[(S->Top2)++];
	}
}