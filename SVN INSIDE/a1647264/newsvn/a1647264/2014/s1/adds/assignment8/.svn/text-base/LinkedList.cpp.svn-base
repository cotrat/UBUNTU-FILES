#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::~LinkedList()
{
	Node* current = head;
	while( current != NULL ) 
	{
    		Node* next = current->next;
    		delete current;
    		current = next;
	}
}

void LinkedList::addNode(int a)
{
	if(head == NULL)
	{
		Node* new_node = new Node;
		new_node->value = a;
		new_node->next = NULL;
		middle = new_node;
		tail = new_node;
		head = new_node;
		length++;
	}
	else
	{
		// Create new node and append to tail, if list size becomes odd move middle
		Node* new_node = new Node;
		new_node->value = a;
		new_node->next = NULL;
		
		tail->next = new_node;
		tail = new_node;
		
		length++;
		if((length % 2) > 0)
		{
			middle = middle->next;
		}
	}
	
	
}

int LinkedList::getLength()
{
	return length;
}

Node* LinkedList::getHead()
{
	return head;
}


void LinkedList::getMiddle()
{
	if (length == 0)
	{
		cout << "0";
		return;
	}
	else if((length % 2) == 0) // If the list is even length there is 2 mid points
	{
		cout << middle->value << " " << middle->next->value;
		
	}
	else
	{
		cout << middle->value;
	}
}

void LinkedList::removeNode()
{

	if (length == 0)
	{
		return;
	}
	if (head!=NULL)
	{
		Node *temp = head->next;
		delete head;
		head = temp;
		length--;

		if((length % 2) > 0) // If we delete a node and the length is now odd, we have to move mid to the right
		{
			middle = middle->next;
		}
	}
	
	
}
