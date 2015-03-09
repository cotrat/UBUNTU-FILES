#ifndef LinkedList_H
#define LinkedList_H

struct Node
{
	int value;
  	Node* next; 
};

class LinkedList
{
public:
	LinkedList() {};
	~LinkedList();
	void addNode(int);
	void removeNode();
	void getMiddle();
	int getLength();
	Node* getHead();
	

private:
	int length;
	Node* head;
	Node* tail;
	Node* middle;
};

#endif
