#include "LinkedList.h"

LinkedList::~LinkedList()
{
	lNode* tmp = head;
	lNode* prev = nullptr;
	while (tmp != nullptr)
	{
		prev = tmp;
		tmp = tmp->next;
		delete prev;
	}
}
LinkedList::LinkedList(const LinkedList& old)
{
	lNode* tmp = old.head;
	head = nullptr;
	tail = nullptr;

	while (tmp != nullptr)
	{
		append(tmp->data);
		tmp = tmp->next;
	}
}

void LinkedList::append(int data)
{
	lNode* tmp = new lNode(data);

	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}
	tmp->prev = tail;
	tail = tmp;
}
void LinkedList::prepend(int data)
{
	lNode* tmp = new lNode(data);

	tmp->next = head;
	if (head == nullptr)
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}
	head = tmp;
}
bool LinkedList::remove(int data)
{
	lNode* tmp = head;

	while (tmp != nullptr)
	{
		if (data == tmp->data)
		{
			if (tmp->prev == nullptr)
			{
				head = tmp->next;
			}
			else
			{
				tmp->prev->next = tmp->next;
			}
			if (tmp->next == nullptr)
			{
				tail = tmp->prev;
			}
			else
			{
				tmp->next->prev = tmp->prev;
			}

			delete tmp;

			return true;
		}
		tmp = tmp->next;
	}
	return false;
}
bool LinkedList::search(int data)
{
	// implement your search code here
	lNode *tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}


void LinkedList::display(std::ostream& os)
{
	lNode* tmp = head;

	while (tmp != nullptr)
	{
		os << tmp->data << " ";
		tmp = tmp->next;
	}

}