import java.io.*;
import java.util.*;

class Solution {

  public ArrayList<Integer> spiralOrder(int[][] matrix) {
    int n = matrix.length;
    int rs = 0, cs = 0, re = n - 1, ce = n - 1;
    ArrayList<Integer> ans = new ArrayList<>();
    while (rs >= 0 && re <= n - 1 && cs >= 0 && ce <= n - 1) {
      for (int i = cs; i <= ce; i++) ans.add(matrix[rs][i]);
      rs++;
      for (int i = rs; i <= re; i++) ans.add(matrix[i][ce]);
      ce--;
      if (rs < 0 || re > n - 1 || cs < 0 || cs > n - 1) break;
      for (int i = ce; i >= cs; i--) ans.add(matrix[re][i]);
      re--;
      for (int i = re; i >= rs; i--) ans.add(matrix[i][cs]);
      cs++;
    }

    return ans;
  }
}

public class spiralmatrix {

  public static void main(String[] args) {
    Solution sol = new Solution();
    Scanner inst = new Scanner(System.in);
    int n;
    System.out.println("Enter n : ");
    n = inst.nextInt();
    int[][] matrix = new int[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) matrix[i][j] = inst.nextInt();
    ArrayList<Integer> ans = new ArrayList<>();
    ans = sol.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++) 
    System.out.print(ans.get(i) + " "); 
  }
}
/*
Ip: n = 4
elements = 1-16
op: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 (visualise in spiral form of the matrix starting from left top end and ending in the middle )

*/