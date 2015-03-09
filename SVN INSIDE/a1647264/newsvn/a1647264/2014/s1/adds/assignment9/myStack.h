#ifndef MYSTACK_H
#define MYSTACK_H

struct Node
{
	int value;
  	Node* next; 
};

class myStack
{
public:
	myStack();
	~myStack();
	void push(int);
	int pop();
	int size;
	

private:
	Node* head;
	
};

#endif
