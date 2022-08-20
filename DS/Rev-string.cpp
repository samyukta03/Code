Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. 
Do not include any extra spaces.
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
//--------------------Stack solution----------------
class Solution {
public:
    //space comp = O(n) time comp=O(n)
    string reverseWords(string s) {
        stack<string>st; //declare a stack of string data type 
        string p=""; //result string 
        for(int i=0;i<s.size();i++){ //thorughout the string 
            string word=""; //a string to store every word, a word is when u encounter a ' '
            if(s[i]==' ') continue; //so if u encounter a white space move to next char 
            while(s[i]!=' ' && i < s.size()) {word+=s[i]; i++; } //while there's no ' ' next, store each char to word
            st.push(word); //finally store the word into the stack 
        }
        while(!st.empty()){ //after storing all the words, attach the top string to result string 
            p+=st.top();
            st.pop(); //pop the top string 
           if(!st.empty()) p+=' '; // if u popped a string and there are more strings in the stack add a ' ' 
        }
        return p; //return the result string 
    }
};
/---------------------two pointer approach------------
class Solution {
public:
    string reverseWords(string s) {
        //space comp = O(1) time comp=O(n)
       int i=0,j; int n = s.size();
        string ans="";
        while(i<n){
        while(i<n && s[i]==' ') i++; //move i till u find a white space
        if(i>=n) break; //if i reached the end of string break the loop;
        j=i; //if u find  a white space, then assign i to j, as i will now point to new word beg
        while(j<n && s[j]!=' ') j++; //move j till the new words end
        string p=s.substr(i,j-i); //store the word to a string named p using substr function that has a syntax like substr(starting_index,length-of-substr) 
        if(ans.size()==0) ans=p;
        else ans = p + ' ' + ans; //attach the word to the front of answer string with a space, if there exist words in the res string
        i=j+1; //now point i to next white space
        }
        return ans;
    }
};