/*
*		Written by Mitchell Anderson - a1647264
*		Adelaide University
*
*		For PROBLEM SOLVING AND SOFTWARE DEVELOPMENT
*		Assignment 1 - fixBinomia, Semester 2 2014
*		
*
*/

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
	* 			- vector[5] = 	[1] = number of towns
	*					[2] = number of roads
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
		vector<string> data;
		while(getline(fileReader,line))				// Read through each line in the text file
		{
			if(lineNum == 1)						// Store the amount of towns
			{
				istringstream iss(line);
				string amt;
				getline(iss, amt, ':');
				getline(iss, amt);
				data.push_back(amt);
			}
			if(lineNum == 2)						// Store the amount of roads
			{
				istringstream iss(line);
				string amt;
				getline(iss, amt, ':');
				getline(iss, amt);
				data.push_back(amt);
			}
			if(line == "Towns:") 					// Change to town parsing mode and skip the line "Towns:"
			{
				mode = "T";
				continue;
			}
			else if(line == "Roads:") 				// Change to road parsing mode and skip the line "Roads:"
			{
				mode = "R";
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
				toVec.push_back(to);
				fromVec.push_back(from);
			}
			lineNum++;								// Increment the current lineNum
		}

		returns.push_back(nodeVec);					// Push back all vectors
		returns.push_back(xVec);
		returns.push_back(yVec);
		returns.push_back(toVec);
		returns.push_back(fromVec);
		returns.push_back(data);
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
	*			- vector[5] = 	[1] = number of towns
	*							[2] = number of roads
	*	@return	- vector containing all the created nodes
	*
	**/
	public:
		vector<Node> generateGraph(vector<vector<string> > parsed)
		{
			vector<Node> ret;

			/**
			*	Create a node taking input from name vector, 
			*	x vector, y vector and then push back into Node
			*	vector.
			**/
			for(int i = 0; i < parsed[0].size(); i++)
			{
				Node n;
				n.name = parsed[0][i];						
				n.x = atof(parsed[1][i].c_str());
				n.y = atof(parsed[2][i].c_str());
				ret.push_back(n);
				sToIndex[parsed[0][i]] = i;													// The purpose of these maps is to convert from an integer index into the node array
				indexToS[i] = parsed[0][i];													// to a town name "string" as they are given from the input (this is essentially a very
			}																				// naive hash function to serve a simple conversion process)

			for(int j = 0; j < parsed[3].size(); j++)
			{
				int to = sToIndex[parsed[3][j]];
				int from = sToIndex[parsed[4][j]];
				ret[sToIndex[parsed[3][j]]].adj.push_back(ret[sToIndex[parsed[4][j]]]);
			}

			return ret;
		}
};

class UntangleGraph
{
	public:
		/**
		*		The following algorithm is a Forced-Based Straight Line Graph drawing algorithm
		*		based on the principles of Coulomb's and Hook's law (Springs and Electrostatic forces)
		*		,more information can be found in the algorithm PDF that is attached to this code.
		*		
		*
		*		The general concept is that all Node pairs repel eachother while each edge drags together
		*		its connecting nodes (acting as a 'Spring')
		*
		**/


		/**
		*	@param	- vector[0] = names of nodes
		*			- vector[1] = X co-ord
		*			- vector[2] = Y co-ord
		*			- vector[3] = Link.to
		*			- vector[4] = Link.from
		*			- vector[5] = 	[1] = number of towns
		*							[2] = number of roads

		*	@return	- vector containing all the nodes with minimized crossings
		*
		**/
		vector<Node> FB(vector<Node> allNodes, int towns, int roads)
		{
			if(towns < 1000) 																	// If the number of towns is small, we can afford to do more iterations
			{
				towns *= 2;
			}
			for(int o = 0; o < towns; o++)
			{
				for(int i = 0; i < allNodes.size(); i++) 										// Iterate through all Nodes
				{
					Node* v = &allNodes[i];														// Ptr to the current node
					Node* u;																	// Ptr to the node to match to
					v->net_force.first = 0;
					v->net_force.second = 0;

					// Apply repulison force based on Coulombs law
					for(int j = 0; j < allNodes.size(); j++)					
					{
						if(i==j) continue;														// Dont apply self-forces
						u = &allNodes[j];
						double dX = v->x - u->x;												// Calculate deltaX, deltaY and the Squared distance between the node pairs
						double dY = v->y - u->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);
						v->net_force.first += (roads*2)*dX/sqdist; // works reasonably well with 1
						v->net_force.second += (roads*2)*dY/sqdist;
						//cout << (roads*2)*dX/sqdist << endl;
					}

					// Apply attraction forces based on Hook's law
					for(int l = 0; l < v->adj.size(); l++)
					{
						u = &allNodes[sToIndex[v->adj[l].name]];
						double dX = u->x - v->x;
						double dY = u->y - v->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);
						v->net_force.first += (u->x - v->x) * 0.50;
						v->net_force.second += (u->y - v->y) * 0.50;
						//cout << "HOOKS " <<(u->y - v->y) * 0.10 << endl;

					}
					
					v->velocity.first =  v->net_force.first;// * 0.85;		// Dampen the forces as to not create enormous graphs
					v->velocity.second = v->net_force.second;// * 0.85;

					v->x += v->velocity.first;													// Move each Node to its new position
					v->y += v->velocity.second;

				
				}
			}
			return allNodes;
		}

		vector<Node> FR(vector<Node> allNodes, int towns, int roads, double W, double L)
		{
			int k = sqrt((W*L)/towns);
			double t = W/10;
			for(int o = 0; o < towns; o++)
			{
				for(int i = 0; i < allNodes.size(); i++) 										// Iterate through all Nodes
				{
					Node* v = &allNodes[i];														// Ptr to the current node
					Node* u;																	// Ptr to the node to match to
					v->net_force.first = 0;
					v->net_force.second = 0;

					// Apply repulison force based on Coulombs law
					for(int j = 0; j < allNodes.size(); j++)					
					{
						if(i==j) continue;														// Dont apply self-forces
						u = &allNodes[j];
						double dX = v->x - u->x;												// Calculate deltaX, deltaY and the Squared distance between the node pairs
						double dY = v->y - u->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);
						if(dist!=0)
						{
							double d = (pow(k,2) / dist) / dist;
							u->net_force.first += dX * d;
							u->net_force.second += dY * d;
						}
				
					}

					// Apply attraction forces based on Hook's law
					for(int l = 0; l < v->adj.size(); l++)
					{
						u = &allNodes[sToIndex[v->adj[l].name]];
						double dX = u->x - v->x;
						double dY = u->y - v->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);

						if(dist!=0)
						{
							double d = (pow(dist,2)/k) / dist;
							double ddx = dX*d;
							double ddy = dY*d;

							u->net_force.first += ddx;
							u->net_force.second += ddy;

							v->net_force.first -= ddx;
							v->net_force.second -= ddy;

						}
					

					}
								
				}

				for(int j = 0; j < allNodes.size(); j++)
				{
					double z = 0;
					Node* v = &allNodes[j];	
					double dX = v->net_force.first;
					double dY = v->net_force.second;
					double dist = sqrt(dX*dX + dY*dY);

					if(dist!=0)
					{
						double d = min(dist,t)/dist;
						double x = v->x + dX * d;
						double y = v->y + dY * d;
						x = min(W,max(z,x)) - W/2;
						y = min(L,max(z,y)) - L/2;

						v->x = min(sqrt(W*W/4-y*y),max(-sqrt(W*W/4-y*y),x)) + W/2;
						v->x = min(sqrt(L*L/4-y*y),max(-sqrt(L*L/4-y*y),x)) + L/2;
					}
				}
				t = t/(o+1);
			}
			return allNodes;


		}

		vector<Node> FB2(vector<Node> allNodes, int towns, int roads)
		{
			if(towns < 1000) 																	// If the number of towns is small, we can afford to do more iterations
			{
				towns *= 2;
			}
			for(int o = 0; o < towns; o++)
			{
				double energy = 0;
				for(int i = 0; i < allNodes.size(); i++) 										// Iterate through all Nodes
				{	
					
					Node* v = &allNodes[i];														// Ptr to the current node
					Node* u;																	// Ptr to the node to match to
					v->net_force.first = 0;
					v->net_force.second = 0;

					// Apply repulison force based on Coulombs law
					for(int j = 0; j < allNodes.size(); j++)					
					{
						if(i==j) continue;														// Dont apply self-forces
						u = &allNodes[j];
						double dX = v->x - u->x;												// Calculate deltaX, deltaY and the Squared distance between the node pairs
						double dY = v->y - u->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);
						v->net_force.first += 1/sqdist;
						v->net_force.second += 1/sqdist;
						//energy += 2*(1/sqdist);
				
					}

					// Apply attraction forces based on Hook's law
					for(int l = 0; l < v->adj.size(); l++)
					{
						u = &allNodes[sToIndex[v->adj[l].name]];
						double dX = u->x - v->x;
						double dY = u->y - v->y;
						double sqdist = ( (dX)*(dX) + (dY)*(dY) );
						double dist = sqrt(sqdist);
						v->net_force.first += (u->x - v->x) * 0.5;
						v->net_force.second += (u->y - v->y) * 0.5;
						//energy += (u->x - v->x);
						//energy += (u->y - v->y);
					

					}
					
					v->velocity.first =  v->net_force.first;		// Dampen the forces as to not create enormous graphs
					v->velocity.second = v->net_force.second;
					v->x += v->velocity.first;													// Move each Node to its new position
					v->y += v->velocity.second;

				
				}
			}
			return allNodes;
		}	
		
};

class OutPut
{
  public:
  	void writeToFile(string filename, vector<Node> finalPos, vector<string> from, vector<string> to, int roads, int towns)
  	{
  		ofstream fileWriter(filename.c_str());	
  		int lineNum = 0;

 		string mode = "G";										// Initially in "general" printing mode
  		while(true)
  		{
  			if(lineNum == 0)
  			{
  				fileWriter << "Map\n";
  			}
  			if(lineNum == 1)
  			{
  				fileWriter << "NumTowns: " << towns << "\n";
  			}
  			if(lineNum == 2)
  			{
  				fileWriter << "NumRoads: " << roads << "\n";
  				mode = "T";
  			}
  			if(mode == "R")
  			{
  				fileWriter << "Roads:" << "\n";
  				for(int i = 0; i < from.size(); i++)
  				{
  					fileWriter << from[i] << "-->" << to[i] << "\n";
  				}
  				fileWriter << "End\n";
  				break;
  			}
  			if(mode == "T")
  			{
  				fileWriter << "Towns:" << "\n";
  				for(int i = 0; i < finalPos.size(); i++)
  				{
  					fileWriter << finalPos[i].name << "(" << finalPos[i].x << "," << finalPos[i].y << ")\n";
  				}

  				mode = "R";
  			}

  			lineNum++;
  		}

  	}
};
int main(int argc, const char* argv[])
{
	Parse a;
	vector<vector<string> > ans;
	ans = a.parseInp(argv[1]);
	
	

	int towns = atoi(ans[5][0].c_str());
	int roads = atoi(ans[5][1].c_str());

	CreateGraph b;
	vector<Node> allNodes;
	allNodes = b.generateGraph(ans);

	UntangleGraph c;
	allNodes = c.FB(allNodes,towns,roads);
	//allNodes = c.FR(allNodes,towns,roads,1000,1000);
	
	OutPut d;
	d.writeToFile(argv[1], allNodes, ans[3], ans[4], roads, towns);


}
