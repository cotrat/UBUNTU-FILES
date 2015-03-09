#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3};
    size_t n_elem = sizeof(arr)/sizeof(*arr);

    unsigned int n_sets = (1 << n_elem);
    for (int i=1; i<n_sets; ++i) // note: start at 0 to include empty-set
    {
        //std::cout << '{';
        for (unsigned int j=0; j<n_elem; ++j)
        {
		std::cout << (1<<j) << "K" << endl;
            /*if (i & (1 << j)) // emit element if bit is lit
                std::cout << arr[j];*/
        }
        //std::cout << "}\n";
	
    }
}
