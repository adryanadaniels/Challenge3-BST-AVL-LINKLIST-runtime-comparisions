#include "AVL.h"

static int MAX(int x, int y)
{
	return (x > y) ? x : y;
}


int AVL::height(Node* node)
{
	if (node == nullptr) return 0;
	return node->height;
}
void AVL::balance(Node*& node)
{
	int balance = BF(node);

	if (balance > 1)
	{

		if (BF(node->left) < 0)
			leftRotate(node->left);
		rightRotate(node);
	}
	if (balance < -1)
	{
		if (BF(node->right) > 0)
			rightRotate(node->right);
		leftRotate(node);
	}
}

int AVL::BF(Node* node)
{
	if(node == nullptr)
		return 0;
	return height(node->left) - height(node->right);
}
void AVL::rightRotate(Node*& node)
{
	Node* left = node->left;
	Node* hold = left->right;
	left->right = node;
	node->left = hold;
	node->height = MAX(height(node->left),height(node->right)) + 1;
	left->height = MAX(height(left->left),height(left->right)) + 1;
	node = left;
}
void AVL::leftRotate(Node*& node)
{
	Node* right = node->right;
	Node* hold = right->left;
	right->left = node;
	node->right = hold;
	node->height = MAX(height(node->left),height(node->right)) + 1;
	right->height = MAX(height(right->left),height(right->right)) + 1;
	node = right;
}

bool AVL::insert(Node*& node, int data)
{
	bool success = false;
	if (node == nullptr)
	{
		node = new Node(data);
		return true;
	}
	if (data < node->data) success = insert(node->left, data);
	if (data > node->data) success = insert(node->right, data);
	if (!success) return false;

	node->height = MAX(height(node->left),height(node->right)) + 1;
	balance(node);
	return true;
}
bool AVL::remove(Node*& node, int data)
{
	bool success = true;
	if (node == nullptr) return false;
	if (data < node->data) success = remove(node->left, data);
	if (data > node->data) success = remove(node->right, data);
	if (!success) return false;
	// found the node to delete
	if (data == node->data)
	{
		int deg = node->degree();
		Node* tmp = node->left;

		switch (deg)
		{
		case 0:
			delete node;
			node = nullptr;
			break;
		case 1:
			if (node->right) tmp = node->right;
			delete node;
			node = tmp;
			break;
		case 2:
			// replace with the immediate pred
			// left then all the way right
			// tmp is already one left
			// now take it all the way right
			while (tmp->right != nullptr)
				tmp = tmp->right;
			node->data = tmp->data;
			remove(node->left, node->data);
			break;
		}
	}
	if (node != nullptr)
	{
		node->height = MAX(height(node->left), height(node->right)) + 1;
		balance(node);
	}
	return true;
}

void AVL::destroy(Node*& node)
{
	if (node == nullptr) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = nullptr;
}
void AVL::copy(Node* node, Node &*cnode)
{
	if (node == nullptr) return;
	cnode = new Node(node->data);
	cnode->height = node->height;
	copy(node->left, cnode->left);
	copy(node->right, cnode->right);
}