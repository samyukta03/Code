// pascal triangles 
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
in a 2d array the pascal triangle can be rep as 
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
the flwng can be observed 
1. the first and last element are by default 1
2. whereas the in between elements lets say matrix[i][j]=matrix[dir above row][dir abv clmn] + matrix[dir abv row][dir abv prev adj clm]
 i.e  matrix[i][j]=   matrix[i-1][j] + matrix[i-1][j-1] 
3. and every row i has i+1 elements so we've to resize the matrix for every row to contain i+1 elements
Time complexity : O(n*n) to print the values of triangle but O(n) to cal the val of middle element
Space complexity O(1)
class Solution{
    public:
 vector<vector<int>> pascaltriangle(int n){
    vector<vector<int>> m;
    for(int i=0;i<n;i++){
        m[i][0]=m[i][i]=1; //obs 1
        m[0].resize(i+1); 
        //obs 3, the syntax to resize a 2d vector is vecname[0].resize(n) where n is the new no of elements
    for(int j=1;j<i;j++){ 
 //traversing from 1st clm to 2nd last clm so avoid j=i+1 and j<=i because if its equal to i then it goes to
 // 1st column so wrong
        m[i][j]=m[i-1][j]+m[i-1][j-1];
    }    
    }
    return m;
 }
}

/*
Variations these questions can be asked:

Print first n rows of a pascal triangle.
Print the n th row of the pascal triangle.
Print the element at the rth row and cth column in pascal traingle.

Variation 1: TC: O(N.N) and SC: O( N.N) as we are storing the entire pascal triangle.
Variation 2: TC: O(N) and SC: O(N) as we are storing the entire row.
Variation 3: TC: O(N) and SC: O(1)
*/