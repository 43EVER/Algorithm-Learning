#pragma once

template<typename T>
class List
{
public:
	struct Node
	{
		T data;
		Node* next;
	};
	Node *head = nullptr;

	int size;
	
public:
	List() : size(0)
	{
		head = new Node();
		head->next = nullptr;
	}

	List(T a[], int n) : List()
	{
		Node *pre = head;
		for (int i = 0; i < n; ++i)
		{
			pre->next = new Node{ a[i], nullptr };
			pre = pre->next;
		}

		size = n;
	}

	T & operator[] (int n)
	{
		int i = 0;
		Node *cur = head->next;
		while (i != n && cur)
		{
			cur = cur->next;
			++i;
		}

		return cur->data;
	}

	bool erase(int n)
	{
		int cnt = 0;
		for (Node** cur = &(head->next); *cur; ++cnt)
		{
			Node * entry = *cur;
			if (cnt == n)
			{
				*cur = entry->next;
				free(entry);
				size--;

				return true;
			}
			else
				cur = &entry->next;
		}

		return false;
	}

	bool push_back(const T data)
	{
		Node *ptr = head;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		ptr->next = new Node{ data, nullptr };
		++size;

		return true;
	}

	int getSize()
	{
		return size;
	}

	~List() {}
};

