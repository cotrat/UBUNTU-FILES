#include "binaryNode.h"
#include "Individual.h"
#include "BitFlip.h"
#include "Rearrange.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*Individual *myLink = new Individual(5);
	cout << myLink->getString();
	myLink->head->next->data = 1;
	myLink->head->next->next->data = 1;
	myLink->head->next->next->next->data = 1;
	myLink->head->next->next->next->next->data = 1;
	cout << endl;
	cout << myLink->getString();
	cout << endl;
	cout << myLink->getMaxOnes();
	cout << endl;
	cout << myLink->getLength();
	cout << "DONE";

	binaryNode *myNode = new binaryNode;
	myNode->data = 0;
	myNode->next = NULL;
	myLink->setFirstBit(myNode);

	Individual myLink2(myLink->head);
	cout << endl;
	cout << myLink->getString();


	Individual myLink3("111000");
	cout << endl;
	cout << myLink3.getString();

	delete myLink;
	
	Individual *myLink5 = new BitFlip("111111");
	myLink5->execute(7);
	cout << endl;
	cout << myLink5->getString();
	//Player * newLanche = new Avalanche();*/

	Individual *myLink6 = new Rearrange("0111");
	myLink6->execute(6);
	cout << endl;
	cout << myLink6->getString();
}
