Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

class Solution {
public:
    //time complexity is O(n x m) where n is the no of words and m is the no of char totally
    //space complexity O(1)
    string lcp(string& a,string& b){
        //this is the recursive key fn thats going to compare the two strings thatll be passed and return either common prefix char or null string 
        string ans="";
        int n = min(a.size(),b.size()); //chose the smallest string bcz the commn cont char is what we're tryn to find
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) ans+=a[i];
            else break;
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans= strs[0]; //keep the 0th word as the ref string and pass it with subsequent strings
        //on the 1st itr, cmn prefix with 0&1st words are returned then that and 2nd words recursively
        for(int i=0;i<strs.size();i++){
            ans = lcp(ans,strs[i]);
        }
        return ans;
    }
};
