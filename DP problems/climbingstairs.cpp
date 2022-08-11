// tc is  O(n) and sc O(n)

class Solution {
public:
    int climbingstairs(int n) {
        if(n<=3){
         return n;
        }
    int totstairs[n+2];
    int i;
    totstairs[0]=0; totstairs[1]=1;
       for(i=4;i<=n;i++){
            totstairs[i]=totstairs[i-1]+totstairs[i-2];
        }
        return totstairs[n];
    }
};
//the total distinct ways of climbing n stairs from the 1st stair and constraint is 1<=n<=45
//eg) if n=2, op=2 ie)1,1 or 2 steps at once
//eg) if n=3, op=3 ie)1,1,1 or 1,2 or 2,1



