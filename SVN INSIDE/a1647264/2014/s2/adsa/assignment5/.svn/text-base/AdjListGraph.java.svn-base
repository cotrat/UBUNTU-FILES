import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

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
				out += " ";
				countOut++;
			}
		
			for(int j = 1; j < size; j++)
			{
				if(i==j) continue;
				if(nodes[j].exists(i))
				{
					in += j;
					in += " ";
					countIn++;
				}
				
				
			}
			System.out.printf("%-4s %-2d %-1s %-10s %-2d %-5s %-30s %-10s %-2d %-5s %-30s %-8s %-2d" , "NODE", i, ":", " OUTGOING (", countOut,") | ", out,  " OUTGOING (", countIn,") | ", in, "TOTAL - ", countOut+countIn );
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
		//foo.addEdge(1, 2, 0);
		//foo.edgeExists(1, 2);
		//foo.edgeExists(1, 2);
		System.out.println("Generate and print a Digraph by calling generateDigraph then print");
		foo.generateDigraph();
		foo.print();
		System.out.println();
		System.out.println("Check if edges (1,5) (15,5) (3,7) (7,7) (10,1) (8,7) exist");
		foo.edgeExists(1, 5);
		foo.edgeExists(15, 5);
		foo.edgeExists(3, 7);
		foo.edgeExists(7, 7);
		foo.edgeExists(10, 1);
		foo.edgeExists(8, 7);
		
		System.out.println();
		System.out.println("Generate and print a network by calling generateNetwork then print");
		foo.generateNetwork();
		foo.print();
		
		System.out.println();
		System.out.println("Find the best nodes (minimal distance) in this network");
		foo.findBestNodes();
		
		
		
	}

}

