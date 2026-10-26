#include "BST.h"


bool BST::insert(Node*& node, int data)
{
	if (node == nullptr)
	{
		node = new Node(data);
		return true;
	}
	if (data < node->data) return insert(node->left, data);
	if (data > node->data) return insert(node->right, data);

	return false;
}
bool BST::remove(Node*& node, int data)
{
	if (node == nullptr) return false;
	if (data < node->data) return remove(node->left, data);
	if (data > node->data) return remove(node->right, data);

	// found the node to delete

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

	return true;
}
bool BST::search(Node* node, int data)
{
	// implement your search code here
	if (node == nullptr) 
	{
		return false;
	}
	if (data > node->data)
	{
		return search(node->right, data);
	}
	if (data < node->data)
	{
		return search(node->left, data);
	}
	
	return true;
	

}
void BST::preorder(Node* node, std::ostream& os)
{
	if (node == nullptr) return;
	os << node->data << " ";
	preorder(node->left, os);
	preorder(node->right, os);
}

void BST::destroy(Node*& node)
{
	if (node == nullptr) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = nullptr;
}
void BST::copy(Node* node, Node *&cnode)
{
	if (node == nullptr) return;
	cnode = new Node(node->data);
	copy(node->left,cnode->left);
	copy(node->right,cnode->right);
}