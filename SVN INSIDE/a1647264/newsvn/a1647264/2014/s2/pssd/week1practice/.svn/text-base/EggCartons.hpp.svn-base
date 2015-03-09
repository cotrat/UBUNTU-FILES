#include <iostream>

using namespace std;


class EggCartons
{
	public:
	int minCartons(int n)
	{
		/*if(n<6)
		{
			return -1;
		}  
		if(n%2==1)
		{
			return -1;
		} */ 

		int totaleggs = 0;
		int p6 = 0;
		int p8 = 0;
		while(totaleggs!=n)
		{
			
			if (totaleggs + 8 <= n)
			{
				p8++;
			}
			else if(totaleggs + 6 <= n)
			{
				p6++;
			}
			else if(p8 > 0)
			{
				p8--;
				p6++;
			}
			else
			{
				return -1;
			}
			totaleggs = (p6 * 6) + (p8 * 8);
		}
		
		return p6+p8;
	}
};

/*int main()
{
	EggCartons a;
	cout << a.minCartons(20) << endl;
	cout << a.minCartons(24) << endl;
	cout << a.minCartons(15) << endl;
	cout << a.minCartons(4) << endl;
}*/
