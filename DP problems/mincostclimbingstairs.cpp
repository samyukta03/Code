/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
EG)
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //TC = O(n) SC: O(1)
        int n=cost.size();
        if(n==1) return cost[0]; //base case
         int dp[n];
         // initially to climb till 0-th or 1th stair
         dp[0]=cost[0];
         dp[1]=cost[1];
        //iterate over the array to find the cost at each stair by cal the cost at current step+ min of (accumulated cost of prev(i-1)and former to prev stait(i-2))
     for(int i=2;i<n;i++)
         dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        //return the minimum cost 
        return min(dp[n-1],dp[n-2]);
    }
};