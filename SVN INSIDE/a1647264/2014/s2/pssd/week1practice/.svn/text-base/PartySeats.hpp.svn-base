#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class PartySeats
{
	public:
	vector<string> seating(vector<string> attendees)
	{
		vector<string> boys;
		vector<string> girls;
		vector<string> plan;
		vector<string> blank;
		string name,gender;
		int j,k;
		int hostess = (attendees.size()+2)/2;

		if((hostess-1)%2==1)
		{
			return blank;
		}

		

		
		for( int i = 0; i < attendees.size(); i++)
		{
			istringstream iss(attendees[i]);
			iss >> name >> gender;
			if(gender == "boy")
			{
				boys.push_back(name);
			}
			else if(gender == "girl")
			{
				girls.push_back(name);
			}
		}
		
		if(boys.size() != girls.size()) // Not an equal amount
		{
			return blank;
		}

		sort(boys.begin(), boys.end());
		sort(girls.begin(), girls.end());
		int boyitr = 0;
		int girlitr = 0;

		for (int x = 0; x < attendees.size()+2; x++)
		{
			if(x==0)
			{
				plan.push_back("HOST");
				//cout << "SAT HOST " << endl;
			}
			else if(x==(attendees.size()+2)/2)
			{
				plan.push_back("HOSTESS");
				//cout << "SAT HOSTESS " << endl;
			}
			else if(x%2==0)
			{
				plan.push_back(boys[boyitr]);
				//cout << "SAT BOY " << boys[boyitr] <<endl;
				boyitr++;
			}
			else if(x%2 == 1)
			{
				plan.push_back(girls[girlitr]);
				//cout << "SAT GIRL " << girls[girlitr] <<endl;
				girlitr++;
			}
		}
		return plan;		
	}
	
};

/*int main()
{
	PartySeats a;
	vector<string> inp;
	inp.push_back("BOB boy");
	inp.push_back("SAM girl");
	inp.push_back("DAVE boy");
	inp.push_back("JO girl");
	int k;
	vector<string> l = a.seating(inp);
	for(k = 0; k < l.size(); k++ )
		{
			cout << l[k] << endl;
		}
	
}*/



