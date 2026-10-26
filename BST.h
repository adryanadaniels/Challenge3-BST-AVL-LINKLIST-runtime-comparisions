#pragma once
#include <iostream>

class Node
{
public:
	int data;
	int height;
	Node* left;
	Node* right;

	int degree() const
	{
		int deg = 0;
		if (left != nullptr) deg++;
		if (right != nullptr) deg++;
		return deg;
	}

	Node(): data(0), height(1), left(nullptr), right(nullptr) {}
	Node(int data) : data(data), height(1), left(nullptr), right(nullptr) {}

};

class BST
{
private:
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	bool search(Node* node, int data);
	void preorder(Node* node, std::ostream& os);

	void destroy(Node*& node);
	void copy(Node* node, Node *&node);

protected:
	Node* root;

public:
	BST() : root(nullptr) {}
	~BST() { destroy(root); }
	BST(const BST& old) { root = nullptr; copy(old.root,root); }

	bool insert(int data) { return insert(root, data); }
	bool remove(int data) { return remove(root, data); }
	bool search(int data) { return search(root, data); }

	void preorder(std::ostream& os) { preorder(root, os); }
};

