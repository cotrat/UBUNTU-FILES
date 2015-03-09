////////////////////////////////////////////
////	Konrad Janica		-a1194898	////
////	Mitchell Anderson	-a1647264	////
////////////////////////////////////////////

public class TreeCount {
	/*
	 * @param - number representing 1-N keys for each unique binary search tree
	 * 
	 * return - number of unique binary search trees that can be created
	 */
	private static long[] store = new long[300];
	
	public TreeCount(){		
		store[0] = 1;
		store[1] = 1;
	}

	public static long getCount(int n) {
	  
		long left = 0;
		long right = 0;
		long sum = 0;
	  
		for (int x = 1; x <= n; x++) {
			if (store[x-1] == 0) {
				left = getCount(x-1);
				store[x-1] = left;
			} else {
				left = store[x-1];
			}
			
			if (store[n-x] == 0) {
				right = getCount(n-x);
				store[n-x] = right;
			} else {
				right = store[n-x];
			}
			
			sum += left*right;
		}
	  
		return sum;
	
	}

}
