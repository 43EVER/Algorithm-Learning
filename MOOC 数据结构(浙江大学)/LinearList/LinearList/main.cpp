#include "pch.h"
#include <iostream>
#include "List.h"
using namespace std;

struct Node
{
	int x;
	int y;

	friend ostream & operator<< (ostream & os, Node d)
	{
		os << d.x << " " << d.y;

		return os;
	}
};

int main()
{
	Node a[] = { {1, 2}, {3, 4}, {5, 6} };

	List<Node> l(a, 3);

	cout << l[0] << endl;

}