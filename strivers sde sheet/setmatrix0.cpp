// given a matrix of nxm
// wherever the m[i][j]=0 the entire ith row and j th column elements should be 0

//time complexity 
//space complexity 
class Solution{
    public:
    void setmatrix0(vector<vector<int>>&m){
        unordered_map<int,int>m1; //to store the row of element that is 0
        unordered_map<int,int>m2; //to store the column of element that is 0
        int rows=m.size();
        int clms=m[0].size();
        for(int i=0;i<rows;i++){
            for(j=0;j<clms;j++){
                if(m[i][j]==0){
                    m1[i]++;
                    m2[j]++;
                }
            }
        }
        //for every row val stored in map1 its respective columns are set to 0
        for(auto itr:m1){
            for(int j=0;j<clms;j++){
                m[m1.first][j]=0;
            }
        }
         //for every clmn val stored in map1 its respective columns are set to 0
        for(auto itr1:mp2){
            for(int i=0;i<rows;i++){
                m[i][itr1]=0;
            }
        }
        
    }
}