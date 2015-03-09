
public class ShellSortTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int vec [] = { 1, 3, 5, 7, 9, 8, 6, 4, 2};
		
		System.out.println ("Contents of vec before sorting:");
		for (int i = 0; i < vec.length; i++) {
			System.out.print (" " + vec[i]);
		}
		System.out.println();
		shellSort (vec);
		
		System.out.println ("Contents of vec after sorting:");
		for (int i = 0; i < vec.length; i++) {
			System.out.print (" " + vec[i]);
		}
		System.out.println();
		}
	public static void shellSort (int vec [])  {
		  
	    /* Outer loop considers different step sizes */
	    for (int k = vec.length/2; k >= 1; k = k/2)  {
	    
	      /* Inner loops provide an insertion sort with the given step size */
	      for (int j = 1;  j < vec.length;  j++)  {
	        for  (int i = j-k;  i >= 0;  i = i-k)  {
	        /*comment*/
	          /* Swap elements which are out of order */
	          if (vec[i] > vec[i+k])  {
	            int tmp = vec[i];
	            vec[i] = vec[i+k];
	            vec[i+k] = tmp;
	          }
	        }
	      }
	    }  
	  }
	}


