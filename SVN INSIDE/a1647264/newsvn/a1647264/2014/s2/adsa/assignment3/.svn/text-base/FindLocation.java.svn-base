/*
 * Mitchell Anderson 	- a1647264
 * Konrad Janica	- a1194898
 * ADSA Assignment 3 	- Question 3
 * 			- 28/08/2014
 */
public class FindLocation {
	/*
	 * @param - 2D Array Representing the matrix to be searched
	 * @param - integer representing the number to search for
	 * 
	 * return - integer array containing the location of the number
	 */
	public static int[] getLocation(int[][] mat,int num)
	{
		  int[] ret = new int[2];				// Return array
		  int row = mat.length; 				// Amount of rows
		  int col = mat[0].length;				// Amount of columns
		  
		  int rowloc = 0;					// Start at top right
		  int colloc = col - 1;
		  
		  while(rowloc < row && colloc >= 0)
		  {
			  if(mat[rowloc][colloc]==num)			// Found the number
			  {
				  ret[0] = rowloc;
				  ret[1] = colloc;
				  return ret;				
			  }
			  if(mat[rowloc][colloc]>num)			// If the value is greater than key we move left down the row
			  {
				  colloc--;
			  }
			  else						// Else move down a row
			  {
				  rowloc++;		
			  }
		  }
		  return ret;
	}
}

