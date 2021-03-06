// 一元多项式的乘法与加法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polynomial
{
public:
	struct Data
	{
		double  coefficient;
		int exponential;
	};

	struct Node
	{
		Data data;
		Node * next;
	};

	Node *head = nullptr;
	Node *last = nullptr;
	int length;

	Polynomial()
	{
		head = new Node{ {0, 0}, nullptr };
		last = head;
	}
	
	Polynomial(const Polynomial & p) : Polynomial()
	{
		Node *curr = p.head->next;
		while (curr)
		{
			this->newNode(curr->data.coefficient, curr->data.exponential);
			curr = curr->next;
		}
	}

	bool newNode(double coefficient, int exponential)
	{
		last->next = new Node{ {coefficient, exponential}, nullptr };
		last = last->next;

		if (!last)
			return false;
		else
			return true;
	}

	Polynomial operator+ (const Polynomial & p)
	{
		Polynomial newP;

		Node *a = head->next;
		Node *b = p.head->next;

		while (a && b)
		{
			if (a->data.exponential > b->data.exponential)
			{
				newP.newNode(a->data.coefficient, a->data.exponential);
				a = a->next;
			}
			else if (a->data.exponential < b->data.exponential)
			{
				newP.newNode(b->data.coefficient, b->data.exponential);
				b = b->next;
			}
			else
			{
				if (a->data.coefficient + b->data.coefficient != 0)
					newP.newNode(a->data.coefficient + b->data.coefficient, a->data.exponential);
				a = a->next;
				b = b->next;
			}
		}
		
		while (a)
		{
			newP.newNode(a->data.coefficient, a->data.exponential);
			a = a->next;
		}
		while (b)
		{
			newP.newNode(b->data.coefficient, b->data.exponential);
			b = b->next;
		}

		return newP;
	}

	Polynomial operator* (const Data & data)
	{
		Polynomial p;
		Node *curr = head->next;

		while (curr)
		{
			p.newNode(curr->data.coefficient * data.coefficient, curr->data.exponential + data.exponential);
			curr = curr->next;
		}

		return p;
	}

	Polynomial operator* (const Polynomial & p)
	{
		Polynomial ans;
		Node *curr = p.head->next;

		while (curr)
		{
			Polynomial temp = *this * curr->data;
			Polynomial temp2 = ans + temp;
			ans = temp2;
			curr = curr->next;
		}

		return ans;
	}

	friend ostream& operator<< (ostream & os, Polynomial p)
	{
		Polynomial::Node * curr = p.head->next;

		if (!curr)
		{
			os << "0 0";

			return os;
		}

		while (curr)
		{
			os << curr->data.exponential << " " << curr->data.coefficient;
			curr = curr->next;
			if (curr)
				cout << " ";
		}

		return os;
	}

	Polynomial operator= (const Polynomial & p)
	{
		if (head != nullptr)
			delete head;

		head = new Node{ {0, 0}, nullptr };
		last = head;

		Node *curr = p.head->next;
		while (curr)
		{
			this->newNode(curr->data.coefficient, curr->data.exponential);
			curr = curr->next;
		}

		return *this;
	}
};

int main()
{
	int n1, n2;
	Polynomial p1, p2;

	cin >> n1;
	for (int i = 0; i < n1; ++i)
	{
		int exponential;
		double cofficient;
		cin >> exponential >> cofficient;

		p1.newNode(cofficient, exponential);
	}
	cin >> n2;
	for (int i = 0; i < n2; ++i)
	{
		int exponential;
		double cofficient;
		cin >> exponential >> cofficient;

		p2.newNode(cofficient, exponential);
	}

	Polynomial p3 = p1 + p2;
	//Polynomial p4 = p1 * p2;

	//cout << p4 << endl;
	cout << p3;
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
