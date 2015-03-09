#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <map>
#include <sstream>
#include <queue>
using namespace std;


class ErdosNumber
{
  public:


	vector<string> calculateNumbers(vector<string> publications)
	{
		map<string,vector<string> > people;
		map<string,vector<string> >::iterator x;
		map<string,int> dist;
		for(int i = 0; i < publications.size(); i++)
		{
			
			string s = publications[i];
			istringstream iss(s);
			vector<string> adj;
			string sub;
			while(iss>>sub)
			{
				adj.push_back(sub);		
			} 	
			
			for( int j = 0; j < adj.size(); j++)
			{
				for(int k = 0; k < adj.size(); k++)
				{
					dist[adj[j]] = 0;
					people[adj[j]].push_back(adj[k]);
				}
			}
		}

	
		//for (map< string, vector<string> >::const_iterator iter = people.begin(); iter != people.end(); ++iter )
		//{
			map<string,int> done;
			
			bool ok = 0;
			queue<string> Q;
			Q.push("ERDOS");
			done["ERDOS"] = 1;
			dist["ERDOS"] = 0;

			while(!Q.empty())
			{	
				string t = Q.front();
				Q.pop();
				
				for(int y = 0; y < people[t].size(); y++)
				{
					string u = people[t][y];
					if(done[u]==0)
					{
						dist[u] = dist[t]+1;
						done[u] = 1;
						Q.push(u);
					}
				}

			}
			
		//}
		vector<string> answer;
		for(map< string, int>::const_iterator iter2 = dist.begin(); iter2!=dist.end(); ++iter2)
		{
			//cout << iter2->first << " DISTANCE OF " << iter2->second << endl;
			if(iter2->second == 0 && iter2->first!="ERDOS")
			{
				answer.push_back(iter2->first);
			}
			else
			{
				  ostringstream ss;
				  ss << iter2->second;
				  string pp = ss.str();
				answer.push_back(iter2->first+" "+pp);
			}
		}
		sort(answer.begin(),answer.end());
		for(int q = 0; q < answer.size(); q++)
		{
			cout << answer[q] << endl;
		}
		return answer;
		
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	ErdosNumber a;
	int l;
	string complearr[] =  	{"ERDOS B", "A B C", "B A E", "D F"};	
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	l = a.calculateNumbers(comple);
	cout << l;

	
}*/
