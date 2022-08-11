//Brute force sol
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m=2,i,k;
        vector<int> res(m,0);
        int n=nums.size();
        for(i=0;i<n;i++){
            for(k=i+1;k<n;k++){
                if(nums[i]+nums[k]==target)
              {
                    res.push_back(i);
                   res.push_back(k);
              }
            }
        }
        return res;
    }
};

time complexity : O(n^2) //two loops so n^2
space complexity : O(1) //method creates at most a single 
//array of 2 elements (in additional to the 2 primitives used for the indices of the loops

/*------------------------------------------------------------------------------------------------*/

//optimized sol
class Solution {
public:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> prevelemap;
        for(int i=0;i<nums.size();i++){
            int x= target-nums[i];
            if(prevelemap.count(x)){
            //if the difference is present in the map key values 
                ans.push_back(i); //push the nums[i]'s index i
                ans.push_back(prevelemap[x]); //push the index of the difference in map
                return ans;
            }
            prevelemap[nums[i]]=i; // number is added in map later to avoid same index twice in ans
        }
        return ans;
    }
};

time complexity : O(n)
space complexity : O(n) //adding the input array elements to hash map so O(n) space reqd

//hashmap approach

   vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(target-nums[i])){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
            }
            else
             mp[nums[i]]=i;
        }
        return ans;

        time compl = O(n)
        space comp = O(1)