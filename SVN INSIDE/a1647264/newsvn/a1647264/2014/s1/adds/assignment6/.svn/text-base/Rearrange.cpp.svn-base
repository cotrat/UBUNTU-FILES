#include "binaryNode.h"
#include "Rearrange.h"
#include "Individual.h"
#include <string>
#include <vector>

using namespace std;

Rearrange::Rearrange(string the_bin) : Individual(the_bin) 
{
	
}

void Rearrange::execute(int k)
{

	binaryNode *the_old_end = NULL;
	binaryNode *the_new_end = NULL;
	binaryNode *the_new_head = NULL;
	binaryNode *the_old_head = head;

	if( k > this->getLength() )
	{
		k = k % this->getLength(); // Using modulo to make sure k "rolls over"
	}

	int ctr = 0;

	if (head == NULL)
	{
		return;
	}
	else
	{
		binaryNode *temp = head;
		while(true)
		{
			ctr++;
			if(ctr == k-1)
			{
				the_new_end = temp;
			}
			if(ctr == k)
			{
				the_new_head = temp;
			}
			
			if (temp->next==NULL)
			{
				the_old_end = temp;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}

	the_old_end->next = the_old_head; 	// Variable names make this process self explanatory but the old final node now links to the old head
	the_new_end->next = NULL;		// The new end links to null, and the head becomes the new head
	head = the_new_head;
	


}
