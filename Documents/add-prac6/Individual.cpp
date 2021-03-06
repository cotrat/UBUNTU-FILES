#include "binaryNode.h"
#include "Individual.h"
#include <iostream>
#include <string>

using namespace std;

Individual::Individual(int length)
{
	head=NULL;
	for(unsigned int i = 0; i < length; i++)
	{
		if (head == NULL)
		{
			binaryNode *temp = new binaryNode;
			temp->data = 0;
			temp->next = NULL;
			head = temp;
		}
		else
		{
			binaryNode *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
		
			binaryNode *new_node = new binaryNode;
			new_node->data = 0;
			new_node->next = NULL;
			temp->next = new_node;
		}

	}

}

Individual::Individual(string bin_string)
{
	head = NULL;
	for(unsigned int i = 0; i < bin_string.length(); i++)
	{
		if (head == NULL)
		{
			binaryNode *temp = new binaryNode;
			if(bin_string[i] == '1')
			{
				temp->data = 1;
			}
			else if(bin_string[i] =='0')
			{
				temp->data = 0;
			}
			temp->next = NULL;
			head = temp;
		}
		else
		{
			binaryNode *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
		
			binaryNode *new_node = new binaryNode;
			if(bin_string[i] == '1')
			{
				new_node->data = 1;
			}
			else if(bin_string[i] == '0')
			{
				new_node->data = 0;
			}
			new_node->next = NULL;
			temp->next = new_node;
		}
	
	}

}

Individual::~Individual()
{
	binaryNode* current = head;
	while( current != NULL ) 
	{
    		binaryNode* next = current->next;
    		delete current;
    		current = next;
	}
}

Individual::Individual(binaryNode *the_head)
{
	head=NULL;
	binaryNode *current;
	while(true)
	{
		
		if (head == NULL)
		{
			binaryNode *temp = new binaryNode;
			temp->data = the_head->data;
			temp->next = the_head->next;
			head = temp;
			current = temp;
		}
		else if(current->next!=NULL)
		{
			binaryNode *temp = head;
			binaryNode *new_node = new binaryNode;
			new_node->data = current->next->data;
			new_node->next = current->next->next;
			temp->next = new_node;
			current = new_node;

		}
		else if(current->next==NULL)
		{
			break;
		}
	}
}

void Individual::execute(int k)
{

}

void Individual::setFirstBit(binaryNode* newHead)
{

	if (head!=NULL)
	{
		binaryNode *temp = head;
		head = newHead;
		head->next = temp;
		

	}
}


int Individual::getLength()
{
	unsigned int the_length = 0;
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		binaryNode *temp = head;
		while(true)
		{
			the_length++;
			if (temp->next==NULL)
			{
				return the_length;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	
	
}

int Individual::getMaxOnes()
{
	unsigned int current_max_ones = 0;
	int largest_max_ones = -1;
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		binaryNode *temp = head;
		while(true)
		{
			if(temp->data == 1)
			{
				current_max_ones++;
			}
			
			if(temp->data == 0)
			{
				largest_max_ones = current_max_ones;
				current_max_ones = 0;
			}

			if (temp->next==NULL)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	
	largest_max_ones = current_max_ones;
	return largest_max_ones;
	
	
}

string Individual::getString()
{
	string return_string = "";
	if (head == NULL)
	{
		return "";
	}
	else
	{
		
		binaryNode *temp = head;
		while(true)
		{
			if(temp->data == 0)
			{
				return_string.append("0");
			}
			else if(temp->data == 1)
			{
				return_string.append("1");
			}

			if (temp->next==NULL)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	return return_string;
}
