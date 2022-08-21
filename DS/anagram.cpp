//1. sorting 
//space comp O(1)
//tc O(nlogn)+O(nlogn) 
bool isAnagram(string s,string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) return true;
    else return false;
}

//-------------------2. using vectors--------------------------
//time complexity  = O(n) n is the total length of the input, i.e. s.length() + t.length().
//space complexity = O(1)
        int arr1[26]={0};//to store the freq of char in s
        int arr2[26]={0}; //to store the freq of char in t
         for (char &x : s)
            arr1[x - 'a']++;  
        for (char &x : t)
            arr2[x-'a']++;
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])
                return false;
        }
        return true;
//-------------------3) Using HashMap---------------------------
	class Solution {
	public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,int>mp;

        for(auto x:s)
            mp[x]++;

        for(auto x:t)
		{
            if(!mp.count(x) || mp[x]==0) 
				return false;//if that char is not there in frist string return false
            else mp[x]--; 
/*if its there and if there'll be multiple occurances so we decrement its count as we encounter
that char everytime in the 2nd string*/
        }
        return true;
    }
};
