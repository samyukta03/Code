
class Solution {
public:
    int tribonacci(int n) {
        int trib[n+3];
        int i;
       if(n<=1)
        return n;
       if(n==2)
           return 1;
        trib[0]=0;
        trib[1]=trib[2]=1;
        for(i=3;i<=n;i++){
        trib[i]=trib[i-1]+trib[i-2]+trib[i-3];
        }
        return trib[n];
    }
};



/*
time cmp O(n) for dp approach
for recursive approach,
if(n==0)
return n;
if(n==1 || n==2)
return 1;
return  tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);

so the tc will be 3T(n-1)+2
which will be O(3^n)
*/