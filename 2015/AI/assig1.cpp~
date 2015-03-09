#include <iostream>
#include <vector>
#include <pair>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void printHelp()
{
	cout << "The format this program takes is ./pathfinder.bin [map] [algorithm] [heuristic]\nwhere [map] is a file formatted to contain\n";
	cout << "FIRST LINE: Size of the map (rows by columns)\nSECOND LINE: Start position\nTHIRD LINE: Goal position\nFOLLOWING N LINES: The map itself (ASCII) [0-9] Elevation inclusive, 'X' for walls";
	cout << "\n[algorithm] is one of bfs, ucs, astar\n[heuristic] is one of euclidian and manhattan\n";
}

int main(int argc, char* argv[])
{
	int algoFlag = -1; // 0 = BFS, 1 = Uniform Cost Search, 2 = A* Search

	// Read in from command line
	for(int i = 0; i < argc; i++)
	{
		cout << "Argument # " << i << " is " << argv[i] << endl;
	}
	printHelp();

}
//vector<vector<pair<int, string> >
void parseInput(string filename)
{
	ifstream infile(filename);
	string line;
	
	while (getline(infile, line)
	{
		istringstream iss(line);
		string buffer;
		while( iss >> buffer )
		{
			cout << buffer <<"-";
		}
}
