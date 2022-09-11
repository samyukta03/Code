import java.io.*;
import java.util.*;
class Solutionsm2 {
    public int[][] generateMatrix(int n) {
          int[][] ans = new int[n][n];
            int rs=0,cs=0,re=n-1,ce=n-1,k=1;
        while(rs>=0 && cs>=0 && ce<=n-1 && ce <=n-1 && k<=n*n){
            
                for(int i=cs;i<=ce;i++)
                    ans[rs][i]=k++;
                rs++;
                for(int i=rs;i<=re;i++)
                    ans[i][ce]=k++;
                ce--;
            if(cs > ce || rs> re) break;            
               for(int i = ce;i>=cs;i--)
                ans[re][i]=k++;
               re--;
            for(int i=re;i>=rs;i--)
                ans[i][cs]=k++;
            cs++;
        }
        return ans;
    }
}
public class spiralmatrix2 {
    public static void main(String[] args) {
        Scanner inst = new Scanner(System.in);
        Solutionsm2 sol = new Solutionsm2();
        int n = inst.nextInt();
        int[][] arr = new int[n][n];
        arr = sol.generateMatrix(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                System.out.print(" "+arr[i][j]+" ");
            System.out.println();
      } 
}
