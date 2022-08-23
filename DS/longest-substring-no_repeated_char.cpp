/*
Given a string s, find the length of the longest substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<char>s;
    string str="";
    cin>>str;
    int count=0;
    int n = str.size();
    int p1=0,p2=0; //two ptrs where one moves throughout the string for every char of str while former moves only when it enocuters a duplicate of the char its pointing to
    while(p1<n && p2<n){
          if(s.find(str[p2])==s.end()){ //if the char is not present in the set, insert it and increment the second pointer 
            s.insert(str[p2]);
            p2++;
            count = max(count,p2-p1); //cal the count as max of prev obtained and current length of substr with no repeated char 
          }
          else {
            s.erase(str[p1]); //if theres a repeated char then remove its og copy from set and move the first ptr so the substr will have no repeated chars 
            p1++;
          }

    }
    cout<<count<<endl;
}