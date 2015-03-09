#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <utility>
#include <queue>
#include <climits>
using namespace std;


class BlockEnemy
{
	int connections[50][50];
	int weights[50][50];
	public:
	int minEffort(int N, vector<string> roads, vector<int> enemies)
	{
		for(int o = 0; o < N; o++)
		{
			for(int p = 0; p < N; p++)
			{
				connections[o][p] = 0;			
				weights[o][p] = 0;
	
			}
		}
		
		for(int j = 0; j < roads.size(); j++)
		{
			string s = roads[j];
			istringstream iss(s);
			string sub;
			vector<string> town_info;
			while(iss >> sub)
			{
				town_info.push_back(sub);
			}

			int from = atoi(town_info[0].c_str());
			int to = atoi(town_info[1].c_str());
			int weight = atoi(town_info[2].c_str());
			
			connections[from][to] = 1;
			connections[to][from] = 1;
			
			weights[from][to] = weight;
			weights[to][from] = weight;
			
			
		}
			
		/*for(int x = 0; x < N; x++)
		{
			cout << "Node " << x << " is connected to ";
			for(int y = 0; y < N; y++)
			{
				if(connections[x][y] == 1)
				{
					cout << y << "(" << weights[x][y] << "),";
				}
			}	
			cout << endl;
		}*/
			
		int ans = 0;
		for(int u = 0; u < enemies.size(); u++)
		{
			for(int v = 0; v < enemies.size(); v++)
			{
				if(enemies[u]==enemies[v]) continue;
				ans += bfs(enemies[u],enemies[v],N);
			}
		}

      		//cout <<"          " <<ans;
		return ans;
	}

	int bfs(int begin, int dest, int N)
	{
		vector<int> parents(50,-1);
		int done[50] = {0};
		queue<int> Q;
		Q.push(begin);
		done[begin] = 1;
		bool canReach = 0;
		while(!Q.empty())
		{
			int node = Q.front();
			Q.pop();
			//cout << "the current node is " << node;
			//cout << endl;
			if(node == dest)	// we can reach it
			{
				canReach = 1;
				break;
			}
			for(int out = 0; out < N; out++)
			{

				if(connections[node][out] == 1 and !done[out])
				{
					done[out] = 1;
					Q.push(out);
					parents[out] = node;
				}

			}
		}
		int mini = INT_MAX;
		int delRow;
		int delCol;
		if(canReach)
		{
			do
			{  
				int temp = parents[dest];
				if(weights[temp][dest] < mini)
				{
					mini = weights[temp][dest];
					delRow = temp;
					delCol = dest;
				}    
				//cout << temp << "->" << dest << " " << weights[temp][dest] << endl;
				dest = parents[dest];
			
			}
			while(dest!=begin);
			//cout << "delete link " << delRow << " " << delCol;
			connections[delRow][delCol] = 0;
			connections[delCol][delRow] = 0;
			return mini;
		}
		else
		{
			//cout << "cant get there";
			return 0;
		}
		
	}


};

/*int main()
{
	BlockEnemy a;
	string complearr[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2", "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	vector<int> enemy; enemy.push_back(1); enemy.push_back(2); enemy.push_back(6); enemy.push_back(8);
	int v = a.minEffort(12, comple,enemy);


}*/



