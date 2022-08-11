class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]]++;
        }
            for(int j=0;j<ransomNote.size();j++){
                //find the element in ransomNote string in maganzine string hashmap
                //if its not there or the hashmap index value of that element is 0 return false
                if(!mp.count(ransomNote[j]) || mp[ransomNote[j]]==0 ){
                    return false;
                }
                else 
                    //if its there then decrement its occurance by 1 so that the repeated elements are also considered
                    --mp[ransomNote[j]];
            }
        return true; //by default true is returned even if the repeated elements in R string is presnt in the M string for R to be constructed  from M
    }
};
//therefore the tc will be O(n) and n is the size of ransomNote string
//and space comp will be O(1) as hashmap takeup constant place

2. vector approach

vector<int> arr(26,0);
for( char x: maganzine)
 arr[x-'a']++;
for(char x : ransomNote)
arr[x-'a']--;
for(char x : ransomNote)
  if(arr[x-'a']<0)
  return false;
return true;


//t(n)=O(n) n=size of ransomnote string
//s(n)=O(1)