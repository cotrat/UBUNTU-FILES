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
	int connections[51][51];
	int weights[51][51];
	public:
	int minEffort(int N, vector<string> roads, vector<int> enemies)
	{
		for(int o = 0; o < N+1; o++)
		{
			for(int p = 0; p < N+1; p++)
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
		/*for(int u = 0; u < enemies.size(); u++)
		{
			for(int v = 0; v < enemies.size(); v++)
			{
				if(enemies[u]==enemies[v]) continue;
				ans += bfs(enemies[u],enemies[v],N);
			}
		}*/
		bfs(19,16,N);
      		cout <<"          " <<ans;
		return 1;
	}

	int bfs(int begin, int dest, int N)
	{
		vector<int> parents(N+1,-1);
		int done[51] = {0};
		queue<int> Q;
		Q.push(begin);
		done[begin] = 1;
		bool canReach = 0;
		while(!Q.empty())
		{
			int node = Q.front();
			Q.pop();
			cout << "the current node is " << node;
			cout << endl;
			if(node == dest)	// we can reach it
			{
				canReach = 1;
				break;
			}
			for(int out = 0; out < N+1; out++)
			{

				if(connections[node][out] == 1 and !done[out])
				{
					done[out] = 1;
					Q.push(out);
					parents[out] = node;
				}

			}
		}
		int mini = 9999;
		int delRow;
		int delCol;
		if(canReach)
		{
			while(dest!=begin)
			{  
				int temp = parents[dest];
				if(weights[temp][dest] < mini)
				{
					mini = weights[temp][dest];
					delRow = temp;
					delCol = dest;
				}    
				cout << temp << "->" << dest << " " << weights[temp][dest] << endl;
				dest = parents[dest];
			
			}
			
			cout << "delete link " << delRow << " " << delCol;
			//connections[delRow][delCol] = 0;
			//connections[delCol][delRow] = 0;
			return mini;
		}
		else
		{
			//cout << "cant get there";
			return 0;
		}
		return 0;
	}


};

int main()
{
	BlockEnemy a;
	string complearr[] = {"9 16 642152", "38 4 526895", "26 47 122864", "12 47 435089", "25 43 388980", "11 1 347321", "42 34 149000", "3 20 408042", "0 18 426675", "24 13 95731", "18 29 324527", "41 8 243532", "38 26 308612", "24 11 972006", "13 46 178149", "47 1 771006", "36 12 513183", "48 29 236604", "22 0 803151", "12 10 327015", "25 40 907423", "20 1 972346", "33 17 247076", "39 23 381399", "27 7 470948", "25 41 553138", "8 19 368011", "8 44 528097", "24 40 394752", "3 45 782847", "13 42 453484", "15 36 161464", "29 31 701536", "6 0 46259", "18 5 863933", "16 14 19817", "12 17 796420", "18 30 659928", "7 19 910264", "29 44 473572", "46 9 914691", "30 21 74924", "21 49 550394", "37 34 306052", "24 28 583560", "39 4 975826", "25 2 274664", "19 35 785252", "5 32 800761"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	vector<int> enemy; enemy.push_back(19); enemy.push_back(16); enemy.push_back(42); enemy.push_back(13);
	int v = a.minEffort(50, comple,enemy);


}



