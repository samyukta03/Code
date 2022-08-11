class Solution {
public:
    int fib(int n) {
        if(n<=1){
         return n;
        }
    int fib[n+2];
    int i;
    fib[0]=0; fib[1]=1;
       for(i=2;i<=n;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib[n];
    }
};

 /* tabulative approach better than recursive here 
 the time complex for recursive approach ie) if(n>1) return fib(n-1)+fib(n-2) is O(2^n)
 whereas for dp algo using array approach the tc is  O(n) and sc O(n)
 */