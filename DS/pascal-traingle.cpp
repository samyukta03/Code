
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1
...

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> m(n);
        for(int i=0;i<n;i++){
            m[i].resize(i+1);
            m[i][0]=m[i][i]=1;
            for(int j=1;j<i;j++){
                 //traversing from 1st clm to 2nd last clm so avoid j=i+1 and j<=i because if its equal to i then it goes to 1st column so wrong
                   m[i][j]=m[i-1][j-1]+m[i-1][j];
            }
        }
        return m;
    }

/* ----------------- Pascal triangle 2 ----------*/
Given a row(0-nth), return the vector of that row. 
eg) ip: 3 op: 1 3 3 1
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
           vector <vector<int>> ans{{1}};

     for(int i=0;i<=rowIndex-1;i++){
          vector <int> temp;
          temp.push_back(1);
         for(int j=0;j<i;j++){
            temp.push_back(ans[i][j]+ans[i][j+1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans[rowIndex];
    }
};