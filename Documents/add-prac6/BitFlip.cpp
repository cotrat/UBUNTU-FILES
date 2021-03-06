#include "binaryNode.h"
#include "BitFlip.h"
#include "Individual.h"
#include <string>

using namespace std;

BitFlip::BitFlip(string the_bin) : Individual(the_bin) 
{
	
}

void BitFlip::execute(int k)
{

	if( k > this->getLength() )
	{
		k = k % this->getLength();
	}

	unsigned int ctr = 0;

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
			if(ctr == k )
			{
				if(temp->data == 0)
				{
					temp->data = 1; 
				}
				else if(temp->data == 1)
				{
					temp->data = 0; 
				}
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
}
