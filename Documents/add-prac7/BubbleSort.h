#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"
#include <vector>


class BubbleSort: public Sort
{
public:
	BubbleSort();
	~BubbleSort() {};
	void bSort(std::vector<int> &toSort);
	
private:
	
};

#endif
