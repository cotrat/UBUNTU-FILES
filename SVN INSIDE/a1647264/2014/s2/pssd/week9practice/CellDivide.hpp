#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <queue>
using namespace std;


class CellDivide
{
  public:
	


	int remainingCells(vector<int> parent, int remove)
	{
		vector<vector<int> > adj;
		int zygote;
		for(int xx = 0; xx < parent.size(); xx++)
		{
			vector<int> a;
			adj.push_back(a);
		}
		for(int i = 0; i < parent.size(); i++)
		{
			if(parent[i] == -1)
			{
				zygote = i;
			}
			else
			{
				//cout << i << " adjacent to " << parent[i] << endl;
				adj[i].push_back(parent[i]);
				adj[parent[i]].push_back(i);
				
			}
		}
	
		if(remove == zygote) return 0;
		queue<int> Q;
		int done[50] = {0};
		done[remove] = 1;
		done[zygote] = 1;
		Q.push(zygote);
		vector<int> poss;
		while(!Q.empty())
		{
			int t = Q.front();
			//cout << " do on " << t << endl;
			poss.push_back(t);
			Q.pop();
			for(int z = 0; z < adj[t].size(); z++)
			{
				if(done[adj[t][z]] == 0)
				{
					
					Q.push(adj[t][z]);
					done[adj[t][z]] = 1;
				}
			}

		}

		int visited = 0;
		for(int ii = 0; ii < poss.size(); ii++)
		{
			bool ok = 1;
			//cout << poss[ii] << "---";
			for(int jj = 0; jj < parent.size(); jj++)
			{
				if(poss[ii] == parent[jj]) ok = 0;
			}
			//cout << endl;
			if(ok) visited++;
		}

		
		return visited;
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	CellRemoval a;
	int l;
	int complearr[] =   	{32, 24, 5, 30, 16, 19, 19, 9, -1, 12, 31, 21, 14, 24, 4, 35, 8, 27, 8, 30, 21, 34, 35, 31, 18, 17, 9, 4, 17, 18, 12, 14, 16, 32, 5, 27, 34};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	l = a.cellsLeft(comple,0);
	//cout << l;

	
}*/
