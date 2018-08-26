// Sunday.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

int Sunday(const string & S, const string & P)
{
	unsigned int shift[256];

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

int KMP(const string & S, const string & P)
{
	//未完成

	return -1;
}

int BM(const string & S, const string & P, int *badc, int badcLen, int *goods, int goodsLen)
{


	return -1;
}

int main()
{
	string S, P;
	string a;

	while (cin >> S >> P >> a)
	{
		switch (a[0])
		{
		case 'S':
			cout << "Sunday Search" << endl;
			cout << Sunday(S, P) << endl;
			break;
		case 'K':
			cout << "KMP Search" << endl;
			cout << KMP(S, P) << endl;
			break;
		case 'B':
			cout << "BM Search" << endl;
			cout << BM(S, P) << endl;
			break;
		}
	}

    return 0;
}

