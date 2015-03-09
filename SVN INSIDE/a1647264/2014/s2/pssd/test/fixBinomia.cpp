#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

map<string,int> sToIndex;
map<int,string> indexToS;

struct Node
{
	string name;
	double x;
	double y;
	pair<int,int> velocity;
	pair<int,int> net_force;
	vector<Node> adj;
};

class Parse
{
  public:
	/**
	*	@param	- name of the file
	*	@return	- vector containing vectors
	*			- vector[0] = names of nodes
	*			- vector[1] = X co-ord
	*			- vector[2] = Y co-ord
	*			- vector[3] = Link.to
	*			- vector[4] = Link.from
	**/
	vector<vector<string> > parseInp(string filename)
	{
		ifstream fileReader(filename.c_str());		// Input stream			
		string line;								// String to containe each line

		int lineNum = 0;							// Store which line we are at
		string mode = "G";

		vector<vector<string> > returns;
		vector<string> nodeVec;
		vector<string> xVec;
		vector<string> yVec;
		vector<string> toVec;
		vector<string> fromVec;
		while(getline(fileReader,line))				// Read through each line in the text file
		{
			if(line == "Towns:") 					// Change to town parsing mode and skip the line "Towns:"
			{
				mode = "T";
				//cout << "BELOW ARE THE TOWNS" << endl;
				continue;
			}
			else if(line == "Roads:") 				// Change to road parsing mode and skip the line "Roads:"
			{
				mode = "R";
				//cout << "BELOW ARE THE ROADS" << endl;
				continue;
			}
			else if(line == "End")
			{
				mode = "G";
			}

			if(mode == "T")							// Begin Parsing towns
			{
				istringstream iss(line);
				string name;
				string x;
				string y;
				getline(iss, name, '(');
				getline(iss, x, ',');
				getline(iss, y, ')');
				//cout << "Create a node called " << name << "(" << x << "," << y << ")" << endl; 
				nodeVec.push_back(name);
				xVec.push_back(x);
				yVec.push_back(y);
			}
			if(mode == "R")							// Begin Parsing roads
			{
				istringstream iss(line);
				string to;
				string from;
				getline(iss, to, '-');
				getline(iss, from, '>');
				getline(iss, from);
				//cout << "Create a link " << to << "->" << from << endl;
				toVec.push_back(to);
				fromVec.push_back(from);
			}
			lineNum++;								// Increment the current lineNum
		}

		returns.push_back(nodeVec);
		returns.push_back(xVec);
		returns.push_back(yVec);
		returns.push_back(toVec);
		returns.push_back(fromVec);
		return returns;
	}
  
};

class CreateGraph
{
	/**
	*	@param	- vector[0] = names of nodes
	*			- vector[1] = X co-ord
	*			- vector[2] = Y co-ord
	*			- vector[3] = Link.to
	*			- vector[4] = Link.from
	*	@return	- vector containing all the created nodes
	*
	**/
	public:
		vector<Node> generateGraph(vector<vector<string> > parsed)
		{
			vector<Node> ret;

			for(int i = 0; i < parsed[0].size(); i++)
			{
				Node n;
				n.name = parsed[0][i];
				n.x = atof(parsed[1][i].c_str());
				n.y = atof(parsed[2][i].c_str());
				ret.push_back(n);
				sToIndex[parsed[0][i]] = i;
				indexToS[i] = parsed[0][i];
			}

			for(int j = 0; j < parsed[3].size(); j++)
			{
				int to = sToIndex[parsed[3][j]];
				int from = sToIndex[parsed[4][j]];
				//ret[from].adj.push_back(ret[to]);
				//cout << "Create a link " << parsed[3][j] << "->" << parsed[4][j] << endl;
				//cout << sToIndex[parsed[3][j]] << "---" << sToIndex[parsed[4][j]]<<endl;
				ret[sToIndex[parsed[3][j]]].adj.push_back(ret[sToIndex[parsed[4][j]]]);
			}	
			return ret;
		}
};

class UntangleGraph
{
	public:
		vector<Node> FR(vector<Node> allNodes)
		{

			double spring = 200;
			for(int o = 0; o < 5; o++)
			{
				for(int i = 0; i < allNodes.size(); i++) // Iterate through all vertices
				{
					Node* v = &allNodes[i];	// Current working node
					Node* u;			// Other nodes
					v->net_force.first = 0;
					v->net_force.second = 0;
					for(int j = 0; j < allNodes.size(); j++)
					{
						if(i==j) continue;	// Dont apply self-forces
						u = &allNodes[j];
						double dX = abs(v->x - u->x);
						double dY = abs(v->y - u->y);
						double dist = sqrt(pow(dX,2)+pow(dY,2));

						//cout << "force " << v->net_force.first << " " << v->net_force.second << endl;
						v->net_force.first += -(dX/dist) * (pow(150,2)/dist);
						v->net_force.first += -(dY/dist) * (pow(150,2)/dist);

					}

					for(int l = 0; l < v->adj.size(); l++)
					{
						u = &allNodes[sToIndex[v->adj[l].name]];
						double dX = abs(v->x - u->x);
						double dY = abs(v->y - u->y);
						double dist = sqrt(pow(dX,2)+pow(dY,2));
						
						v->net_force.first += -(dX/dist) * (pow(dist,2)/150);
						v->net_force.second += -(dY/dist) * (pow(dist,2)/150);

						u->net_force.first += (dX/dist) * (pow(dist,2)/150);
						u->net_force.second += (dY/dist) * (pow(dist,2)/150);
						//cout << "force " << v->net_force.first << " " << v->net_force.second << endl;
					}
					
				}

				for(int j = 0; j < allNodes.size(); j++)
				{
					Node* v = &allNodes[j];
					//cout << "force " << v->net_force.first << " " << v->net_force.second << endl;
					v->x += v->net_force.first;
					v->y += v->net_force.second;
				}

			}
			return allNodes;
		}

		/*vector<Node> FR_2(vector<Node> allNodes)
		{
			int area = 10000;
			int k = sqrt((area)/allNodes.size());
			for(int o =0; o < 1000; o++)
			{
				for(int i = 0; i < allNodes.size(); i++)
				{
					Node* v = &allNodes[i];	// Current working node
					Node* u;
					v->net_force.first = 0;
					v->net_force.second = 0;
					for(int j = 0; j < allNodes.size(); j++)
					{
							if(i==j) continue;
							u = &allNodes[j];
							double dist = ( (v->x - u->x)*(v->x - u->x) + (v->y - u->y)*(v->y-u->y) );
							dist = sqrt(dist);
							v->net_force.first += (dist/abs(dist)) * (pow(-k,2)/abs(dist));
							v->net_force.second += (dist/abs(dist)) * (pow(-k,2)/abs(dist));

					}

					for(int l = 0; l < v->adj.size(); l++)
					{
						u = &allNodes[sToIndex[v->adj[l].name]];
						double dist = ( (v->x - u->x)*(v->x - u->x) + (v->y - u->y)*(v->y-u->y) );
						dist = sqrt(dist);
						v->net_force.first -= (dist/abs(dist)) * (pow(abs(dist),2)/k);
						v->net_force.second += (dist/abs(dist)) * (pow(abs(dist),2)/k);
					}

					for(int k = 0; k < allNodes.size(); k++)
					{
							u = &allNodes[k];
							u->x = min(100/2,max(-100/2,u->x));
							u->y = min(100/2,max(-100/2,u->y));

					}
				}
			}
		}*/
};

int main()
{
	Parse a;
	vector<vector<string> > ans;
	ans = a.parseInp("run1in.txt");
	
	CreateGraph b;
	vector<Node> allNodes;
	allNodes = b.generateGraph(ans);

	UntangleGraph c;
	allNodes = c.FR(allNodes);
	
	
	
	for(int k = 0; k < allNodes.size(); k++)
	{
		cout << allNodes[k].name << "(" <<allNodes[k].x << "," << allNodes[k].y << ")";

		for(int l = 0; l < allNodes[k].adj.size(); l++)
		{
			//cout  << allNodes[k].adj[l].name << " ";
		}
		cout << endl;
	}
	cout << allNodes.size();
	


}
