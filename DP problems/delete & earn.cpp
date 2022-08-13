You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.
Example 1:
Input: nums = [3,4,2]   Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = []. so 4+2=6
//---------------------Solution
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      int n=100001;
        vector<int> freq(n,0);
        vector<int> dp(n,0);
        for(int i: nums) freq[i]++;
        dp[1]=freq[1];
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-2]+i*freq[i],dp[i-1]);
        
        return dp[n-1];
    }
};
Time complexity : O(n)
Space complexity : O(n) dp array