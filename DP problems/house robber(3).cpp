/*--------------------------------HOUSE ROBBER 1 --------------------------------------------*/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
class Solution {
public:
//time comp = O(n) & space comp = O(n)
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
       vector<int>loot(n);//dp array to store the values
     loot[0] = nums[0]; //the first house loot
     loot[1] = max(nums[0],nums[1]); //the second house loot = max of first and secnd
  /*from the second house we cal the loot thats max
    ie) max of the current house loot+(i-2)th house 
                        &
                            */
        for(int i=2;i<n;i++)
        loot[i]=max(loot[i-1],loot[i-2]+nums[i]);
     return loot[n-1];
    }
};
/*--------------------------------HOUSE ROBBER 2 --------------------------------------------*/
Same sum with one difference, Each house has a certain amount of money stashed. All houses at this place are arranged in a ---circle---. That means the first house is the neighbor of the last one. 
Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

/*The approach of this is same as the prev but the thing is since 1st and last are connected we seprate the 
array into two parts 
eg) 1-2-3-4-5-----1
so here we seprate 1-2-3-4 as an arrya and 2-3-4-5 as an array so the first and last dont encounter at same time. After seprating into 2 arrays we cal the max loot of each and compare both and return the max among them
*/
class Solution {
public:
    int solve(vector<int>arr){
        
        if(arr.size()==0) return 0;
        if(arr.size()==1) return arr[0];
        
        int dp[arr.size()+1];
        
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<arr.size();i++)
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        
        return dp[arr.size()-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> v1(nums.begin(), nums.end()-1); //from the start to second last node
        vector<int> v2(nums.begin()+1, nums.end()); //from second to last node
           return max(solve(v1),solve(v2)); 
    }
};