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
using namespace std;


class BlockEnemy
{
	struct Edge{
		int to;
		int weight;
	};
	public:
	int minEffort(int N, vector<string> roads, vector<int> enemies)
	{
		vector<vector<Edge> > adj;
		for(int i = 0; i < N; i++)                      // initialize the adjacency list
		{
			vector<Edge> l;
			adj.push_back(l);
		}
		int ans = 0;
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
			Edge e;

			e.to = to;
			e.weight = weight;
			adj[from].push_back(e);

			e.to = from;
			adj[to].push_back(e);
		}
			for(int x = 0; x < N; x++)
			{
			cout << "Node : " << x << " | ";
			for(int y = 0; y < adj[x].size(); y++)
			{
				cout << adj[x][y].to << "(" << adj[x][y].weight << ")  ";
			}
			cout << endl;
			}  
				adj[0][1].to = 50;
				adj[2][1].to = 50;
				bool canReach = 0;
				//if(enemies[pp] == enemies[qq]) continue;
				//if(enemies[qq] < enemies[pp]) continue;
				//if(enemies[pp] < enemies[qq]) continue;
				int begin = 2;
				vector<int> parents(50,-1);
				queue<int> Q;
				int done[51] = {0};
				done[begin] = 1;
				done[50] = 1;
				Q.push(begin);
				pair<int,int> edgeDel;
				int dest = 6;

				while(!Q.empty())
				{
					int node = Q.front();
					Q.pop();
					cout << "the current node is " << node;
					cout << endl;
					if(node == dest)
					{
						canReach = 1;
						break;
					}
					for(int out = 0; out < adj[node].size(); out++)
					{

						if(!done[adj[node][out].to])
						{
							cout << adj[node][out].to << "'s parent is " << node << " with weright of " << adj[node][out].weight                                            << endl;
							done[adj[node][out].to] = 1;
							Q.push(adj[node][out].to);
							parents[adj[node][out].to] = node;
						}

					}


				}

				if(!canReach) 
				{
					cout << "you cant get there";
				}
			

		

      
		return 1;
	}



};

int main()
{
	BlockEnemy a;
	string complearr[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2", "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	vector<int> enemy; enemy.push_back(1); enemy.push_back(2); enemy.push_back(6); enemy.push_back(8);
	int v = a.minEffort(12, comple,enemy);


}


