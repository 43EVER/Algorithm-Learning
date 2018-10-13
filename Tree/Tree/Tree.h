#pragma once
#include <iostream>

using std::ostream;
using std::cout;

template<typename Data>
class Tree {

private:
	struct TNode {
		TNode *left;
		Data data;
		TNode *right;
	};

	TNode *root;

	TNode * newNode(Data data) {
		TNode *node = new TNode;
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;

		return node;
	}

	TNode *_insert(TNode *t, Data data) {
		if (t == nullptr)
			return newNode(data);
		
		if (data < t->data)
			t->left = _insert(t->left, data);
		else if (data > t->data)
			t->right = _insert(t->right, data);

		return t;
	}

	TNode *_minElement(TNode *t) {
		do {
			if (!t) break;

			while (t->left)
				t = t->left;
		} while (false);

		return t;
	}

	TNode *_maxElement(TNode *t) {
		do {
			if (!t) break;

			while (t->right)
				t = t->right;
		} while (false);

		return t;
	}

	TNode *_remove(TNode *t, const Data & data) {
		do {
			if (!t) break;

			if (data < t->data)
				t->left = _remove(t->left, data);
			else if (data > t->data)
				t->right = _remove(t->right, data);
			else
				if (t->left && t->right) {
					t->data = _maxElement(t->left)->data;
					t->left = _remove(t->left, t->data);
				
				} else {
					TNode *tmp = t;
					if (!t->left)
						t = t->right;
					else if (!t->right)
						t = t->left;

					free(tmp);
				}
		} while (false);

		return t;
	}

	void _preOrderTravel(TNode *t, ostream &os) {
		if (!t)
			return;

		os << t->data << " ";
		_preOrderTravel(t->left, os);
		_preOrderTravel(t->right, os);
	}

	void _inOrderTravel(TNode *t, ostream &os) {
		if (!t)
			return;

		_inOrderTravel(t->left, os);
		os << t->data << " ";
		_inOrderTravel(t->right, os);
	}

	void _afterOrderTravel(TNode *t, ostream &os) {
		if (!t)
			return;

		_afterOrderTravel(t->left, os);
		_afterOrderTravel(t->right, os);
		os << t->data << " ";
	}

	void removeAll(TNode *t) {
		if (!t)
			return;

		removeAll(t->left);
		t->left = nullptr;
		removeAll(t->right);
		t->right = nullptr;
		delete t;
		t = nullptr;
	}

public:
	Tree(const Data & data) {
		this->root = newNode(data);
	}

	bool remove(const Data & data) {
		root = this->_remove(root, data);
		
		if (root == nullptr)
			return false;
		else
			return true;
	}

	bool insert(const Data & data) {
		this->_insert(root, data);

		return true;
	}

	bool minElement(Data &data) {
		TNode *tmp = _minElement(root);
		
		if (tmp == nullptr)
			return false;
		
		data = tmp->data;
		return true;
	}

	bool maxElement(Data &data) {
		TNode *tmp = _maxElement(root);
		
		if (tmp == nullptr)
			return false;

		data = tmp->data;
		return true;
	}

	void preOrderTravel() {
		_preOrderTravel(root, cout);
	}

	void inOrderTravel() {
		_inOrderTravel(root, cout);
	}

	void afterOrderTravel() {
		_afterOrderTravel(root, cout);
	}

	~Tree() {
		removeAll(root);
	}
};
