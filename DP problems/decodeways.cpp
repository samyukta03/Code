A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' - "1" 'B' - "2" ... 'Z' - "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters
using the reverse of the mapping above (there may be multiple ways). For example,
"11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6) "KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" 
is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
The answer is guaranteed to fit in a 32-bit integer.
Example 1:
Input: s = "12" Output: 2 Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

class Solution {
public:

    int numDecodings(string s) {
        //tc = O(n) sc = O(n)
        if(s.size()==0 || s[0] == '0') return 0; //base case 
        int n = s.size();
        vector<int> dp(s.size()+1);
        dp[0]=1;
        dp[1]=1; //corresponds to the first number in the string, if its non-zero dp[1]=1
        for(int i=2;i<=n;i++){ //start from i=2 in dp 
            if(s[i-1]>='1' && s[i-1]<='9') dp[i]=dp[i-1]; //bascillay check the second char in the string and checks if its 1-9 values, if yes add the prev obtained val, ie) rep it as 1-2-3 
            if(s[i-2]=='1') dp[i]+=dp[i-2]; //check for the first char + second char is of the range 10-19, and increments
            if(s[i-2]=='2' && s[i-1]>=48 && s[i-1]<=54) dp[i]+=dp[i-2];//check the secd and first char is in the range 20-26 and increments it
        }
        return dp[n]; 
    }
};

/*
Recursive approach : Time limit exceeded
  long totways(string s,long n){
        if(n>=s.size()) return 1;
        if(s[n]=='0') return 0;
        if(n==s.size()-1) return 1;
        if(s[n]=='1' || s[n]=='2' && s[n+1]>=48 && s[n+1]<=54)
            return totways(s,n+1)+totways(s,n+2);
        else return totways(s,n+1);
    }
    int numDecodings(string s) {
        if(s.size()==0 || s.size()==1 && s[0] == '0') return 0;
        // long n = s.size();
        return totways(s,0);
    }
*/
/*
Recursive + DP: top-bottom
int totways(string s,long n,vector<int>&dp){
        if(n>=s.size()) return 1;
        if(s[n]=='0') return 0;
        if(n==s.size()-1) return 1;
        if(dp[n]!=-1) return dp[n];
        if(s[n]=='1' || s[n]=='2' && s[n+1]>=48 && s[n+1]<=54)
            return dp[n]=totways(s,n+1,dp)+totways(s,n+2,dp);
        else return dp[n]=totways(s,n+1,dp);
    }
    int numDecodings(string s) {
        if(s.size()==0 || s.size()==1 && s[0] == '0') return 0;
        // long n = s.size();
        vector<int> dp(s.size(),-1);
        return totways(s,0,dp);
    }
*/
