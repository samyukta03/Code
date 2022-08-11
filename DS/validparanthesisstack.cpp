#include<bits/stdc++.h>
#include<stack>
class Solution
{
public:
   Time complexity : O(n)
   Space complexity : O(n) i.e length of string
    bool isValid(string s)
    {
        int len = s.length();
        stack<char> s1;
        char top;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                s1.push(s[i]);
            }
             else
             {
                if(s1.empty()) return false;
                top = s1.top();
                if(s[i]==']'&& top=='[' || s[i]==')' && top=='(' || s[i]=='}' && top=='{' )
                {
                    s1.pop();
                    continue; // means it goes back to check the else condition 
                }
                    else break; //means it goes back to first if cond
              }
        }
    }
        if (s1.empty())
            return true;
        else
            return false;
    }
};