#pragma once
#include <iostream>

class lNode
{
public:
	int data;
	lNode* next;
	lNode* prev;

	lNode() : data(0), next(nullptr), prev(nullptr) {}
	lNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};



class LinkedList
{
private:
	lNode* head;
	lNode* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList();
	LinkedList(const LinkedList& old);

	void append(int data);
	void prepend(int data);
	bool remove(int data);
	bool search(int data);

	void display(std::ostream& os);
};

