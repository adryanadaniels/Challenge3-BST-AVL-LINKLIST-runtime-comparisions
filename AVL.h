#pragma once
#include "BST.h"
class AVL : public BST
{
private:
	
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	
	void destroy(Node*& node);
	void copy(Node* node, Node *&cnode);


	int height(Node* node);
	void balance(Node*& node);
	int BF(Node* node);
	void rightRotate(Node*& node);
	void leftRotate(Node*& node);

public:
	AVL() : BST() {}
	~AVL() { destroy(root); }
	AVL(const AVL& old) { root = nullptr; copy(old.root,root); }

	bool insert(int data) { return insert(root, data); }
	bool remove(int data) { return remove(root, data); }
};

