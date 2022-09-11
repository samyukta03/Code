/* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
[1 2 3        [7 4 1
 4 5 6   --->  8 5 2
 7 8 9]        9 6 3]
 */
 // ---------------time comp = O(n*n) space comp=O(1)
import java.lang.*;
import java.util.*;
public class rotateimage{
    //take transpose and reverse each row of matrix 
    public static void rotate(int[][] matrix)
  {
        int n=matrix.length;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                //swapping the lower traingle results in transpose of the matrix 
               int temp =  matrix[i][j];
               matrix[i][j]  =matrix[j][i];
               matrix[j][i]=temp;
            }
        }
        //reverse the rows after taking transpose so we use swap fn in java (stl not applicable unless its list)
        for (int i = 0; i < n; i++) 
    {
        int start = 0;
        int end = n - 1;
        while (start < end) 
        {
            //swap the fns from both ends 
        int temp = matrix[i][end];
        matrix[i][end]= matrix[i][start];
        matrix[i][start]=temp;
            start++; 
            end--;
        }
    }
  }
  public static void main(String[] args){
      int a[][] = { {1, 2, 3, 4},
                  {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16} };
        rotate(a);
        int n=a.length;
        for(int i=0;i<n;i++){
            for(int j=0;<n;j++){
                    System.out.print(" "+a[i][j]+" ");
            }
            System.out.println();
        }
  }
}