import java.util.*;
import java.io.*;
import java.awt.geom.Point2D;
import java.awt.geom.Line2D;

// program that counts the crossings in a graph... 
// read in the graph edges
// for each edge
//  for each other edge 
//    if intersection
//      add to crossing count
//    endif
//  end for
// end for

public class CountCrossings{

    // set up frame for viewing and structures to hold the roads
    // and the names of the towns of binomia
    BasicFrame myFrame = new BasicFrame();
    ArrayList<MyLine> roads =  new ArrayList<MyLine>();
    HashMap<String,MyPoint> towns = new HashMap<String,MyPoint>();


    // count crossings reads a file.. it is very fussy about the format
    // it will throw an exception if there is a problem
    public CountCrossings(String inFile) throws IOException{

        // parse the input file and initialise an array of edges.
	// set up a scanner and read the number of towns and number
        // of roads
	Scanner scan  = new Scanner(new File(inFile),"UTF-8");
	scan.nextLine();
	int numTowns = getNumber(scan.nextLine());
	int numRoads = getNumber(scan.nextLine());
	// skip a header line
	String tmp=scan.nextLine();
	// read in all the towns (and their location)
	for(int i=0;i<numTowns;i++){
	    tmp=scan.nextLine();
	    addTown(tmp);
	}
	// skip another header line
	tmp=scan.nextLine();

	// read in all the roads
	for(int i=0;i<numRoads;i++){
	    // read in four values.
	    tmp=scan.nextLine();
	    addRoad(tmp);
	}
	
	// now setup a frame for displaying intersecting roads
	myFrame.setSize(500,500);
	myFrame.setVisible(true);

    }


    // read in a town and store values in a hashmap.
    private void addTown(String town){
	// add an entry to a hashmap from a scanner
	Scanner scan = new Scanner(town);
	scan.useDelimiter(",|\\(|\\)");
        String key=scan.next();
	double x=scan.nextDouble();
	double y=scan.nextDouble();
	//System.out.println(" name " + key + " " + x + " " + y );
	MyPoint loc = new MyPoint(x,y,key);
	towns.put(key,loc);
	
    }


    // read in a road and store values in a list.    
    private void addRoad(String road){
	// add an entry to the array list of roads
	Scanner scan = new Scanner(road);
	scan.useDelimiter("-->");
	String from=scan.next();
	//System.out.println(from);
	String to=scan.next();
	//System.out.println("from to" + from + " " + to);
	MyPoint start = towns.get(from);
	MyPoint end = towns.get(to);
	roads.add(new MyLine(start,end));
	
    }

    // read in a number field (assumes number follows a colon followed
    // by a space - this is really fussy but ok.
    private int getNumber(String fields){

	// reads in an integer after first colon in fields.
	int res =0;
	Scanner scan = new Scanner(fields);
	System.out.println(fields);
	scan.useDelimiter(": ");
	scan.next();
	String roadNum = scan.next();
	res = new Integer(roadNum).intValue();
	return res;
    }
	    
    // return a count of crossings in the graph.
    // you will want to minimise this number.
    public int crossings(){
	// iterate through a list of edges and return a count of crossings
	int res=0;
	// for each edge
	for(MyLine a: roads){
	    for(MyLine b: roads){
		if (sharedNode(a,b)) continue;
	      
		if(Line2D.linesIntersect(a.from.x,a.from.y,a.to.x,a.to.y,
					 b.from.x,b.from.y,b.to.x,b.to.y)){
		    /* System.out.println("testing lines " + (int)a.from.x +
				       "," + (int)a.from.y + "," + (int)a.to.x +
				       "," + (int)a.to.y + ",  " + (int)b.from.x + 
				       "," + (int)b.from.y + "," +(int) b.to.x + 
				       "," + (int)b.to.y); */
		    myFrame.addLine(a);
		    myFrame.addLine(b);
		    res++;
		}
	    }
	}

        // because roads are two ways there are eight separate ways to 
        // count the same crossing... so divide by 8.
	return res/8;
    }
    
    // check to see if two roads share a town
    // if they do they cannot intersect in the countryside
    private boolean sharedNode(MyLine a, MyLine b){
	ArrayList<String> names = new ArrayList<String>();
	names.add(a.from.name);
	names.add(a.to.name);
	names.add(b.from.name);
	names.add(b.to.name);
	for(int i=0;i<names.size();i++){
	    for(int j=0;j<names.size();j++){
		if(j!=i){
		    if(names.get(i).equals(names.get(j))){
			return true;
		    }
		}
	    }
	}
	return false;
    }
	
	
	

    // driver file for counting crossings.
    public static void main(String[] args) throws IOException {
	String inFileName=args[0];
	CountCrossings c = new CountCrossings(inFileName);
	System.out.println("Number of crossings in " + inFileName +
			   " is " + c.crossings());
    }
}

