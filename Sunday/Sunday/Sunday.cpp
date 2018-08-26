// Sunday.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

int Sunday(const string & S, const string & P, int *shift)
{
	unsigned int sLen = S.length();
	unsigned int pLen = P.length();

	for (unsigned int i = 0; i < 256; ++i)	shift[i] = pLen + 1;
	for (unsigned int i = 0; i < pLen; ++i) shift[P[i]] = pLen - i;

	unsigned int j, s = 0;
	while (s <= sLen - pLen)
	{
		j = 0;
		while (S[s + j] == P[j])
		{
			j++;
			if (j >= pLen)
				return s;
		}
		s += shift[S[s + pLen]];
	}

	return -1;
}

int KMP(const string & S, const string & P, int * next)
{
	int i, j, k;
	int sLen = S.length();
	int pLen = P.length();

	//求next
	k = -1, j = 0;
	next[0] = -1;

	while (j < P.length() - 1)
	{
		if (k == -1 || P[k] == P[j])
			next[++j] = ++k;
		else
			k = next[k];
	}

	//KMP
	i = 0, j = 0;
	while (i < sLen && j < pLen)
	{
		if (j == -1 || S[i] == P[j])
			++i, ++j;
		else
			j = next[j];
	}

	return j == P.length() ? i - j : -1;
}

int BM(const string & S, const string & P, int *badc, int *goods)
{


	return -1;
}

int main()
{
	const int MAXN = 256;

	string S, P;
	string a;

	int *badc = NULL;
	int *goods = NULL;

	while (cin >> S >> P >> a)
	{
		badc = (int*)malloc(sizeof(int) * MAXN);
		goods = (int*)malloc(sizeof(int) * P.length());

		switch (a[0])
		{
		case 'S':
			cout << "Sunday Search" << endl;
			cout << Sunday(S, P, badc) << endl;
			break;
		case 'K':
			cout << "KMP Search" << endl;
			cout << KMP(S, P, goods) << endl;
			break;
		case 'B':
			cout << "BM Search" << endl;
			cout << BM(S, P, badc, goods) << endl;
			break;
		}
	}

    return 0;
}

