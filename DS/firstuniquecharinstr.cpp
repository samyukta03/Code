// 1. using unordered hashmap approach

// tc= O(n) for traversing throughout the array to find the unique element
// sc= O(n) constant space for hashmap

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        int n = s.size();
        int res = -1; // stores the index of first occurance
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++; // store all the elements in hash map and increment their occurances
        }
        for (int i = 0; i < n; i++)
        {
            // if theres a unique element decrement its count and store it in res variable and exit loop

            if (mp[s[i]] == 1)
            {
                --mp[s[i]];
                res = i;
                break;
            }
        }
        return res;
    }
};

/* ------------------------------------------------------------------------- */

// 2. Vector
//   array of size 26 and use each index of the array as the (ASCII of that character) starting from 97 of a
//  TC : O(N)
//  SC : O(26)

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int a[26] = {0}; // vector of alphabets
        for (char &x : s)
            a[x - 'a']++; // basically the count of that part element in the array of 26 alphabets
        /*and here we do the 's[i]'-'a' because the index is so eg) s[i]='b'
        then 'b'=98 and 'a'=97 so b will in the index 1 ie)the second index */
        for (int i = 0; i < s.size(); i++)
            if (a[s[i] - 'a'] == 1) //and here we check the element which has the count=1 ie) is unique
                return i;
        return -1;
    }
};