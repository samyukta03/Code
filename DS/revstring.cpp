Given an array of char as string, reverse it. 
Eg) ip:  s = {"h","e","l","l","o"}
op : {"o","l","l","e","h"}
class Solution {
public:
    //Recursive approach : 
    void revstr(vector<char>& s,int i,int j){
      if(i>=j) return ;  // Base Condition
            swap(s[i++],s[j--]); //A relation or a formula that can divide a big problem into small subproblem of same type
            revstr(s,i,j);
    }
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        revstr(s,i,j);
    }
};

/* Without recursion approach : Two pointer approach
time comp = O(n) sc O(1)
void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
        swap(s[i],s[j]);
        i++; j--;
        }
    }
*/