#include "myStack.h"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
using namespace std;

myStack::myStack()
{
	size = 0;
}

myStack::~myStack()
{
	while(size>0)
	{
		pop();
	}
}

void myStack::push(int node_val)
{
	size++;
	Node* temp_node = new Node;
    	temp_node->value = node_val;
    	temp_node->next = head;
    	head = temp_node;
}

int myStack::pop()
{
	if (size == 0)
	{
		cout << "Error";
		exit(1);
	}
	else
	{
		size--;
		Node* temp_node = head;
		head = head->next;
		int nodes_value = temp_node->value;
		delete temp_node;
		return nodes_value;
	}
}

