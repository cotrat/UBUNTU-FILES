#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <functional>

struct Point
{
	int row;
	int col;
	int cost;
	Point* parent;
};

using namespace std;

class ComparePoint {
public:
    bool operator()(Point* p1, Point* p2)
    {
       if (p1->cost < p2->cost) return false;
       return true;
    }
};

vector<vector<string> > parseInput();
void bfs(vector<vector<string> > inp);
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
	vector<vector<string> > ret = parseInput();
	for(int j = 0; j < ret.size(); j++)
	{
		for(int k = 0; k < ret[j].size(); k++)
		{
			cout << ret[j][k];
		}
		cout << endl;
	}

	priority_queue<Point*, vector<Point*>, ComparePoint> pq;
	Point a;
	a.row = 3;
	a.col = 5;
	a.cost = 100;
	
	Point b;
	b.row = 10;	
	b.col = 10;
	b.cost = 30;

	pq.push(&a);
	pq.push(&b);

	cout << pq.top()->row;


	/*Point a;
	a.row = 3;
	a.col = 5;
	
	Point b;
	b.row = 10;	
	b.col = 10;
	b.parent = &a;

	cout << b.parent->row;
	a.row = 10;
	cout << b.parent->row;

	queue<Point*> q;
	q.push(&a);
	Point* aa;
	aa = q.front();
	aa->row = 50;
	cout << b.parent->row;
	bfs(ret);*/
}

void bfs(vector<vector<string> > inp)
{
	// TODO read in what needs to be visited (start/end etc)
	int sz = 10;
	int visited[sz][sz];
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)
		{
			visited[i][j] = 0;
		}
	}

	/**
	*	Initialise the Queue and place 
	*	the first point in (mark as visited)
	**/

	queue<Point*> Q;
	Point* start = new Point;
	start->row = 0;
	start->col = 0;
	start->parent = NULL;
	visited[0][0] = 1;
	Q.push(start);

	Point* current;
	while(!Q.empty())
	{
		current = Q.front();
		Q.pop();
		int row = current->row;
		int col = current->col;
		cout << "now checking " << row << "," << col << endl;
		if(row == 9 && col == 9)
		{
			cout << "We hit the finish" << endl;
			break;
		}

		// UP (ROW SUBTRACT ONE)
		if(row-1 >= 0 && visited[row-1][col] == 0 && inp[row-1][col]!="X")
		{
			Point* next = new Point;
			next->row = row-1;
			next->col = col;
			next->parent = current;
			Q.push(next);
			visited[row-1][col] = 1;
			cout << "which adds in " << row-1 << "," << col << " Queue now has " << Q.size() << " elements "<< endl;
		}
		// DOWN (ROW ADD ONE)
		if(row+1 < sz && visited[row+1][col] == 0 && inp[row+1][col]!="X")
		{
			Point* next = new Point;
			next->row = row+1;
			next->col = col;
			next->parent = current;
			Q.push(next);
			visited[row+1][col] = 1;
			cout << "which adds in " << row+1 << "," << col << " Queue now has " << Q.size() << " elements "<< endl;
			//cout << Q.front()->row << "," << Q.front()->col << endl;
		}
		// LEFT (COL SUBTRACT ONE)
		if(col-1 >= 0 && visited[row][col-1] == 0 && inp[row][col-1]!="X")
		{
			Point* next = new Point;
			next->row = row;
			next->col = col-1;
			next->parent = current;
			Q.push(next);
			visited[row][col-1] = 1;
			cout << "which adds in " << row << "," << col-1 << " Queue now has " << Q.size() << " elements "<< endl;
		}
		// RIGHT (COL ADD ONE)
		if(col+1 < sz && visited[row][col+1] == 0 && inp[row][col+1]!="X")
		{
			Point* next = new Point;
			next->row = row;
			next->col = col+1;
			next->parent = current;
			Q.push(next);
			visited[row][col+1] = 1;
			cout << "which adds in " << row << "," << col+1 << " Queue now has " << Q.size() << " elements "<< endl;
			//cout << Q.front()->row << "," << Q.front()->col << endl;
		}
	}

	cout << "[" << current->row << "," << current->col << "] -> " << endl;
	cout << "[" << current->parent->row << "," << current->parent->col << "] -> " << endl;
	while(current!=NULL)
	{
		cout << "[" << current->row << "," << current->col << "] -> " << endl;
		inp[current->row][current->col] = "*";
		current = current->parent;
		

	}
	
	for(int j = 0; j < inp.size(); j++)
	{
		for(int k = 0; k < inp[j].size(); k++)
		{
			cout << inp[j][k];
		}
		cout << endl;
	}
	
}
//vector<vector<pair<int, string> >
vector<vector<string> > parseInput()
{
	ifstream infile("map_file");
	string line;
	int count = 0;
	vector<vector<string> > maze;
	vector<string> nextLine;
	maze.push_back(nextLine);
	while (getline(infile, line))
	{
		istringstream iss(line);
		string buffer;
		while( iss >> buffer )
		{
			maze[count].push_back(buffer);
			
		}
		vector<string> nextLine;
		maze.push_back(nextLine);
		count++;
	}
	return maze;
}
