/*
Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/
class Solution {
public:
    //time comp = O(n^2) sc: O(1)
    string ans="";
   int maxlen = INT_MIN;
    void ispalindrome(int i,int j,string s){
        while(i>=0 && j<=s.size()-1 && s[i]==s[j]){
                if(j-i+1>maxlen){
                    maxlen = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
             i--; j++;
    }
    }
    string longestPalindrome(string s) {
        int n=s.size();
       // string ans="";
        for(int i=0;i<n;i++){
            ispalindrome(i,i,s); //odd length
            ispalindrome(i,i+1,s); //even length
        }
        return ans;
    }
};