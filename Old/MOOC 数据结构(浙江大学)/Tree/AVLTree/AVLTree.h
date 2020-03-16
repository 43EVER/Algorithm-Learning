#pragma once
#include <algorithm>
#include <iostream>

template<typename T>
class AVLNode {
public :
	T key;
	int balance;
	AVLNode *left, *right, *parent;
	
	AVLNode(T k, AVLNode *p) :	key(k), parent(p),
													left(nullptr), right(nullptr) {}

	~AVLNode() {
		delete left;
		delete right;
	}
};

template<typename T>
class AVLTree {
public :
	AVLTree(void);
	~AVLTree(void);
	bool insert(const T & key);
	void remove(const T & delKey);
	void printBalance();

private :
	AVLNode<T> *root;

	AVLNode<T> *rotateLeft						(AVLNode<T> *a);
	AVLNode<T> *rotateRight					(AVLNode<T> *a);
	AVLNode<T> *rotateLeftThenRight		(AVLNode<T> *n);
	AVLNode<T> *rotateRightThenLeft		(AVLNode<T> *n);
	void rebalance										(AVLNode<T> *n);
	int height												(AVLNode<T> *n);
	void setBalance									(AVLNode<T> *n);
	void printBalance									(AVLNode<T> *n);
	//void clearNode									(AVLNode<T> *n);
};

template<typename T>
AVLTree<T>::AVLTree(void) : root(nullptr) {}

template<typename T>
inline AVLTree<T>::~AVLTree(void) {
	delete root;
}

template<typename T>
bool AVLTree<T>::insert(const T & key) {
	if (root == nullptr) {
		return new AVLNode<T>(key, nullptr);
	}
	else {
		AVLNode<T>
			*n = root,
			*parent;

		while (true) {
			if (n->key == key)
				return false;

			parent = n;

			bool goLeft = n->key > key;
			n = goLeft ? n->left : n->right;

			if (n == nullptr) {
				if (goLeft) {
					parent->left = new AVLNode<T>(key, parent);
				}
				else {
					parent->right = new AVLNode<T>(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

template<typename T>
void AVLTree<T>::remove(const T & delKey) {
	if (root == nullptr)
		return;

	AVLNode<T>
		*n						= root,
		*parent				= root,
		*delNode			= nullptr,
		*child				= root;

	while (child != nullptr) {
		parent = n;
		n = child;
		child = delKey >= n->key ? n->right : n->left;
		if (delKey == n->key)
			delNode = n;
	}

	if (delNode != nullptr) {
		delNode->key = n->key;

		child = n->left != nullptr ? n->left : n->right;

		if (root->key == delKey) {
			root = child;
		}
		else {
			if (parent->left == n) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template<typename T>
void AVLTree<T>::printBalance() {
	printBalance(root);
	std::cout << std::endl;
}

template<typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* a) {
	AVLNode<T> *b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if (a->right != nullptr)
		a->right->parent = a;

	b->left = a;
	a->parent = b;

	if (b->parent != nullptr) {
		if (b->parent->right == a) {
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template<typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* a) {
	AVLNode<T> *b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if (a->left->parent != nullptr)
		a->left->parent = a;

	b->right = a;
	a->parent = b;

	if (b->parent != nullptr) {
		if (b->parent->right == a)
			b->parent->right = b;
		else
			b->parent->left = b;
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template<typename T>
AVLNode<T>* AVLTree<T>::rotateLeftThenRight(AVLNode<T>* n) {
	n->left = rotateLeft(n->left);
	return rotateRight(n);
}

template<typename T>
AVLNode<T>* AVLTree<T>::rotateRightThenLeft(AVLNode<T>* n) {
	n->right = rotateRight(n->right);
	return rotateLeft(n);
}

template<typename T>
void AVLTree<T>::rebalance(AVLNode<T>* n) {
	setBalance(n);
	
	if (n->balance == -2) {
		if (height(n->left->left) >= height(n->left->right))
			n = rotateRight(n);
		else
			n = rotateLeftThenRight(n);
	}
	else if (n->balance == 2) {
		if (height(n->right->right) >= height(n->right->left))
			n = rotateLeft(n);
		else
			n = rotateRightThenLeft(n);
	}

	if (n->parent != nullptr) {
		rebalance(n->parent);
	}
	else {
		root = n;
	}
}

template<typename T>
int AVLTree<T>::height(AVLNode<T>* n) {
	if (n == nullptr)
		return -1;
	return 1 + std::max(height(n->left), height(n->right));
}

template<typename T>
void AVLTree<T>::setBalance(AVLNode<T>* n) {
	n->balance = height(n->right) - height(n->left);
}

template<typename T>
void AVLTree<T>::printBalance(AVLNode<T>* n) {
	if (n != nullptr) {
		printBalance(n->left);
		std::cout << n->balance << " ";
		printBalance(n->right);
	}
}
