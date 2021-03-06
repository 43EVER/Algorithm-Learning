// StringSearch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

const int ASIZE = 256;

int Sunday(const string & T, const string & P, int *shift)
{
	unsigned int sLen = T.length();
	unsigned int pLen = P.length();

	for (unsigned int i = 0; i < 256; ++i)	shift[i] = pLen + 1;
	for (unsigned int i = 0; i < pLen; ++i) shift[P[i]] = pLen - i;

	unsigned int j, s = 0;
	while (s <= sLen - pLen)
	{
		j = 0;
		while (T[s + j] == P[j])
		{
			j++;
			if (j >= pLen)
				return s;
		}
		s += shift[T[s + pLen]];
	}

	return -1;
}

//https://www.cnblogs.com/yjiyjige/p/3263858.html
int KMP(const string & T, const string & P, int * next)
{
	int i, j, k;
	int sLen = T.length();
	int pLen = P.length();

	//求next
	k = -1, j = 0;
	next[0] = -1;

	while (j < P.length() - 1)
	{
		if (k == -1 || P[k] == P[j])
		{
			if (P[++j] == P[++k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
			k = next[k];
	}

	//KMP
	i = 0, j = 0;
	while (i < sLen && j < pLen)
	{
		if (j == -1 || T[i] == P[j])
			++i, ++j;
		else
			j = next[j];
	}

	return j == P.length() ? i - j : -1;
}

//理解思想：http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
//理解代码: https://www.cnblogs.com/xubenben/p/3359364.html
int * getBc(const string & P)
{
	int *bc = new int[ASIZE];
	int pLen = P.length();

	for (int i = 0; i < ASIZE; ++i)
		bc[i] = -1;
	for (int i = 0; i < pLen; ++i)
		bc[P[i]] = i;

	return bc;
}
//仅利用坏字符规则优化后缀暴力
int badcBF(const string & T, const string & P)
{
	int *bc = getBc(P);
	int patAt = 0;
	int cmp;

	const size_t PATLASTID = P.length() - 1;
	const size_t tLen = T.length();
	const size_t pLen = P.length();

	while (patAt + pLen <= tLen)
	{
		for (cmp = PATLASTID; cmp >= 0 && P[cmp] == T[patAt + cmp]; --cmp);

		if (cmp == -1)
			break;
		else
		{
			int span = cmp - bc[T[patAt + cmp]];
			patAt += span > 0 ? span : 1;
		}
	}

	delete[] bc;

	return cmp == -1 ? patAt : -1;
}

//后缀暴力
int postfixBFMatch(const string & T, const string & P)
{
	int patAt = 0;
	int cmp;
	const size_t PATLAST = P.length() - 1;
	while (patAt + P.length() <= T.length())
	{
		for (cmp = PATLAST; cmp >= 0 && P[cmp] == T[patAt + cmp]; --cmp);

		if (cmp == -1)
			break;
		else
			++patAt;
	}

	return cmp == -1 ? patAt : -1;
}

int *preBMBc(const string & P)
{
	int pLen = P.length();
	int *bmBc = new int[ASIZE];

	for (int i = 0; i < ASIZE; ++i)
		bmBc[i] = pLen;
	for (int i = 0; i < pLen - 1; ++i)
		bmBc[P[i]] = pLen - 1 - i;

	return bmBc;
}

int *suffixes(const string & P)
{
	int pLen = P.length();
	int *suff = new int[pLen];
	suff[pLen - 1] = pLen;

	for (int i = pLen - 2; i >= 0; --i)
	{
		for (int num = 0, )

		s
	}

	return suff;
}

int BM(const string & T, const string & P)
{
	//未完成

	return -1;
}


int main()
{
	string T, P;
	string a;

	int *badc = NULL;
	int *goods = NULL;

	while (cin >> T >> P >> a)
	{
		badc = (int*)malloc(sizeof(int) * ASIZE);
		goods = (int*)malloc(sizeof(int) * P.length());

		switch (a[0])
		{
		case 'S':
			cout << "Sunday Search" << endl;
			cout << Sunday(T, P, badc) << endl;
			break;
		case 'K':
			cout << "KMP Search" << endl;
			cout << KMP(T, P, goods) << endl;
			break;
		case 'B':
			cout << "BM Search" << endl;
			cout << BM(T, P) << endl;
			break;
		}
	}

	return 0;
}

