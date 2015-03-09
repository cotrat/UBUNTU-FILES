#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"
#include <vector>


class QuickSort: public Sort
{
public:
	QuickSort();
	~QuickSort() {};
	void qSort(std::vector<int> &toSort, int, int);
	
private:
	int Split(std::vector<int> &toSort, int, int, int);
	
};

#endif
