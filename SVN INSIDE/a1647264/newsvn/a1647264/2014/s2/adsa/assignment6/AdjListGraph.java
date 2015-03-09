import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Stack;

class Edge{
	
	int weight;
	int connect;
	/**
	 * 
	 * @param u - what the edge will connect to
	 * @param w - weight of the edge
	 */
	public Edge(int u, int w)
	{
		this.weight = w;
		this.connect = u;
	}
	/**
	 * 
	 * @param w -  the new weight
	 */
	public void setWeight(int w)
	{
		this.weight = w;
	}
	/**
	 * 
	 * @return - what this edge connects to
	 */
	public int getConnect()
	{
		return connect;
	}
	/**
	 * 
	 * @return - the weight of the edge
	 */
	public int getWeight()
	{
		return weight;
	}
}

class Node{
	
	//int name; THIS IS HERE FOR INCOMING EDGE METHOD
	private LinkedList<Edge> outgoingEdges;
	// private LinkedList<Edge> incomingEdges; THIS IS HERE FOR INCOMING EDGE METHOD
	
	public Node() {
		//name = n; THIS IS HERE FOR INCOMING EDGE METHOD
		outgoingEdges = new LinkedList<Edge>();
		// incomingEdges = new LinkedList<Edge>(); THIS IS HERE FOR INCOMING EDGE METHOD
	}
	
	/**
	 * 
	 * @param u - the node the edge will connect to
	 * @param w - the weight of the edge
	 */
	
	public void addEdge(int u, int w){ 
		outgoingEdges.add(new Edge(u,w));
	}
	/**
	 * 
	 * @param u - the node that this edge connects to
	 */
	public void removeEdge(int u) 
	{
		for(Edge E : outgoingEdges)
		{
			if(E.getConnect() == u)				// we have found the edge
			{
				outgoingEdges.remove(E);		// remove the edge
				return;
			}
		}
		
		System.out.println("EDGE DOES NOT EXIST CANNOT DELETE");
		//throw new Exception("EDGE DOES NOT EXIST CANNOT DELETE");
	}
	/**
	 * 
	 * @param u - the node to check for
	 * @return - 1 if exists 0 if not
	 */
	public boolean exists(int u)
	{
		for(Edge E : outgoingEdges)
		{
			if(E.getConnect() == u)				// we have found the edge
			{
				return true;
			}
		}
		return false;
	}
	
	public LinkedList<Edge> getEdgeList()
	{
		return outgoingEdges;
	}
}


public class AdjListGraph {

	private static Node[] nodes;						// The Array of nodes
	int size;
	/**
	 * 
	 * @param sz - amount of nodes
	 */
	public AdjListGraph(int sz)
	{
		nodes = new Node[sz+1];
		this.size = sz+1;
		for(int i = 0; i < size; i++)				// Populate the array with blank nodes
		{
			nodes[i] = new Node();
		}
	}
	
	public void generateDigraph()
	{
		this.size = 16;
		nodes = new Node[size];
		Random generator = new Random(1194898);
		
		for(int i = 1; i < size; i++)				// Populate the array with blank nodes
		{
			nodes[i] = new Node();
			for(int j = 1; j < size; j++)
			{
				if(i==j) continue;
				if(generator.nextInt(2) == 0)
				{
					addEdge(i,j,0);
				}
				
			}
		}
		
	}
	
	public void generateDigraphDij()
	{
		this.size = 16;
		nodes = new Node[size];
		
		Random generator = new Random(1194898);		// 1194898
		int range100 = 100 - 1 + 1;
		int range10 = 10 - 1 + 1;
		for(int i = 1; i < size; i++)				// Populate the array with blank nodes
		{
			nodes[i] = new Node();
			for(int j = 1; j < size; j++)
			{
				if(i==j) continue;
				if((generator.nextInt(range100) + 1) <= 25)
				{
					addEdge(i,j,(generator.nextInt(range10) + 1));
				}
				
			}
		}
	}
	
	public void makeGraphNeg()
	{
		Random generator = new Random(1194898);
		for(int i  = 1; i < size; i++)
		{
			for(Edge E : nodes[i].getEdgeList())
			{
				if(generator.nextInt(2) == 0)
				{
					E.setWeight(-E.getWeight());
				}
			}
		}
	}
	
	public void generateNetwork()
	{
		this.size = 21;
		nodes = new Node[21];
		Random generator = new Random(1194898);
		
		for(int i = 1; i < size; i++)				// Populate the array with blank nodes
		{
			nodes[i] = new Node();			
		}
		
		for(int j = 1; j < size; j++)				// Populate the array with blank nodes
		{
			
			if(j == 1) continue; // First node doesnt link to anything
			if(j == 2)
			{
				addEdge(j,1,0);
				addEdge(1,j,0);
			}
			else
			{
				int rand = generator.nextInt(j-1)+1;
				addEdge(j,rand,0);
				addEdge(rand,j,0);
			}
				
			
		}
	}
	/**
	 * 
	 * @param u - the FROM node
	 * @param v - the TO node
	 * @param w - the WEIGHT of the edge
	 */
	public void addEdge(int u, int v, int w)
	{
		if(u < size && v < size)
		{
			nodes[u].addEdge(v,w);
		}
		else
		{
			System.out.println("Not possible to add this edge as you have specified non existent nodes");
		}
	}
	
	/**
	 * 
	 * @param u - the FROM node
	 * @param v - the TO node
	 */
	public void removeEdge(int u, int v)
	{
		if(u < size && v < size)
		{
			nodes[u].removeEdge(v);
		}
		
		System.out.println("Not possible to remove this edge as you have specified non existent nodes");
	}
	/**
	 * 
	 * @param u - the FROM node
	 * @param v - the TO node
	 */
	public void edgeExists(int u, int v)
	{
		if(u < size && v < size)
		{
			if(nodes[u].exists(v))
			{
				System.out.println("There exists an edge connecting Nodes " + u + " and " + v);
			}
			else
			{
				System.out.println("There does not exist an edge connecting Nodes " + u + " and " + v);
			}
		}
		else
		{
			System.out.println("Not possible to determine existence of this edge as you have specified non existent nodes");
		}
	}
	
	public void print()
	{
		System.out.println("All the nodes ");
		for(int i = 1; i < size; i++)
		{
			int countOut = 0;
			int countIn = 0;
			LinkedList<Edge> the_list = nodes[i].getEdgeList();
			String out = "";
			String in = "";
			for(Edge E : the_list)
			{
				//System.out.print(E.getConnect() + ",");
				out += E.getConnect();
				out += "(";
				out += E.getWeight();
				out += ")";
				out += " ";
				countOut++;
			}
		
			for(int j = 1; j < size; j++)
			{
				if(i==j) continue;
				the_list = nodes[j].getEdgeList();
				int ctr = 0;
				for(Edge E : the_list)
				{
					
					if(E.getConnect() == i)				// we have found the edge
					{
						in += j;
						in += "(";
						in += E.getWeight();
						in += ")";
						in += " ";
						countIn++;
					}
				}
				
				
			}
			System.out.printf("%-4s %-2d %-1s %-10s %-2d %-5s %-50s %-10s %-2d %-5s %-50s %-8s %-2d" , "NODE", i, ":", " OUTGOING (", countOut,") | ", out,  " INCOMING (", countIn,") | ", in, "TOTAL - ", countOut+countIn );
			System.out.println();
		}
		
		
		
	}
	/**
	 * 
	 * @param u - the node to begin with
	 * @return - the longest time to transfer a msg
	 */
	public static int BFS(int u)
	{
		Queue<Integer> q = new LinkedList<Integer>();
		Boolean[] done = new Boolean[21];
		int[] dist = new int[21];
		dist[u] = 0;
		Arrays.fill(done, false);
		done[u] = true;
		q.add(u);
		int maxDist = 0;

		while(q.peek() != null) // while not empty
		{
			
			int currentNode = q.remove();
			if(dist[currentNode]>maxDist)
			{
				maxDist = dist[currentNode];
			}
		
			for(Edge E : nodes[currentNode].getEdgeList())
			{
				int neighbour = E.getConnect();
				if(done[neighbour]==false)
				{
					dist[neighbour] = dist[currentNode]+1;
					done[neighbour] = true;
					q.add(neighbour);
					
				}
			}
			
		}
		
		return maxDist;
	}
	
	
	public void dij(int src, int targ)
	{
		int[] dist = new int[16];
		LinkedList<Integer> q = new LinkedList<Integer>();
		int[] parent = new int[16];
		for(int o = 1; o < 16; o++)
		{
			dist[o] = 9999;			// Initialize all to suitably large number
			parent[o] = -1;
			q.add(o);
		}
		
		parent[src] = src;
		dist[src] = 0;
		String order = "";
		while(q.peek() != null)
		{
			int mini = 999;
			int pos = 0;
			for(int i = 0; i < q.size(); i++) // Find the minimum element in the queue
			{
				int elem = q.get(i);
				if(dist[elem] < mini)
				{
					mini = dist[elem];
					pos = i;							
				}
			}
			
			int u = q.get(pos);
			q.remove(pos);
			order+=u;
			order+=" ";
			for(Edge E : nodes[u].getEdgeList())
			{
				int alt = dist[u] + E.getWeight();
				int v = E.getConnect();
				if (alt < dist[v])
				{
					dist[v] = alt;
					parent[v] = u;
				}
			}
		}
		
		
		/** Following code is just to print out (using a stack to reverse the paths) **/
		System.out.println("The shortest paths from 1 are as follows using DIJKSTRAS");
		System.out.println("The nodes were traveresed in the following order " + order + "\n\n");
		Stack<Integer> s = new Stack<Integer>();
		for(int k = 1; k < 16; k++)
		{
			String ans = "";
			boolean ok = true;
			targ = k;
			while(targ!=src)
			{
				if(targ == -1) 
				{
						ok = false;
						break;
				}
				s.push(targ);
				targ = parent[targ];
				
			}
			s.push(src);
			if(ok)
			{
				do
				{
					ans+=s.pop();
					ans+=" ";
				}
				while(!s.empty());
				System.out.printf("%-10s %-2d %-7s %-10s %-15s %-2d \n", "Path to ", k, "is | ", ans, "of weight - ", dist[k] );
			}
			if(!ok)
			{
				System.out.println("No path connecting 1 and " + k);
			}
		}	
		
		
		
	}
	
	public void bellFord()
	{
		int[] dist = new int[16];
		int[] parent = new int[16];
		for(int o = 1; o < 16; o++)
		{
			dist[o] = 9999;			// Initialize all to suitably large number
			parent[o] = -1;
		}
		dist[1] = 0;
		parent[1] = 1;
		for(int i = 1; i < 15; i++)
		{
			for(int j = 1; j < 16; j++)				// While this may appear O(n^2) it is O(mn) because this nested for loop is just getting every edge
			{
				for(Edge E : nodes[j].getEdgeList())
				{
					if(dist[j]+E.getWeight() <= dist[E.getConnect()])
					{
						dist[E.getConnect()] = dist[j]+E.getWeight();
						parent[E.getConnect()] = j;
					}
				}
			}
			
		}
		
		for(int j = 1; j < 16; j++)
		{
			for(Edge E : nodes[j].getEdgeList())
			{
				if(dist[j] + E.getWeight() < dist[E.getConnect()])
				{
					System.out.println("NEGATIVE CYCLES AT NODE " + j);
					return;
				}
			}
		}
		
		/** Following code is just to print out (using a stack to reverse the paths) **/
		
		System.out.println("\n\nThe shortest paths from 1 are as follows using BELLMAN FORD\n\n");
		Stack<Integer> s = new Stack<Integer>();
		int targ;
		int src = 1;
		for(int k = 1; k < 16; k++)
		{
			String ans = "";
			boolean ok = true;
			targ = k;
			while(targ!=src)
			{
				if(targ == -1) 
				{
						ok = false;
						break;
				}
				s.push(targ);
				targ = parent[targ];
				
			}
			s.push(src);		
			if(ok)
			{
				do
				{
					ans+=s.pop();
					ans+=" ";
				}
				while(!s.empty());
				System.out.printf("%-10s %-2d %-7s %-10s %-15s %-2d \n", "Path to ", k, "is | ", ans, "of weight - ", dist[k] );
			}
			if(!ok)
			{
				System.out.println("No path connecting 1 and " + k);
			}
		}	
		
	}
	
	public void findBestNodes()
	{
		int min = 9999;

		int[] longest = new int[size];
		for(int i = 1; i < size; i++)
		{
			int curr = BFS(i);
			longest[i] = curr;
			if(curr < min) min = curr;
		}
		System.out.print("The best nodes are ");
		for(int j = 1; j < size; j++)
		{
			if(longest[j] == min) System.out.print(j + " ");
		}
		System.out.print(" With a distance of " + min);
	}
	
	public static void main(String[] args) {
		AdjListGraph foo = new AdjListGraph(0);
	
		
		foo.generateDigraphDij();
		foo.print();
		System.out.println();
		System.out.println();
		foo.dij(1, 0);
		foo.bellFord();
		foo.makeGraphNeg();
		System.out.println("\nThe graph with negative weights");
		foo.print();
		foo.bellFord();
	
				
		
		
	}

}
