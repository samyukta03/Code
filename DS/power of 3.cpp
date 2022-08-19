Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.
Example 1:
Input: n = 27 / Output: true
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false; //obv neagative
   while(n!=1){ //after 1, check the consectuive remainders and if its not div by 3 return false
       if(n%3!=0) return false;
       n/=3;
   }
        return true;
    }
};

//using log
 public boolean isPowerOfThree(int n) {
       return (Math.log10(n) / Math.log10(3)) % 1 == 0;
   }