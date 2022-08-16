You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force approach
        //tc: O(n^2) sc:O(1)
        int mincost=prices[0]; int day;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mincost){
                mincost=prices[i];
                day=i;
            }
        }
        int maxcost=prices[day];
        for(int i=day;i<prices.size();i++){
            if(prices[i]>maxcost)
                maxcost=prices[i];
        }
        return maxcost-mincost;
    }
};
class Solution{
    public:
    int maxProfit(vector<int>& prices){
        //kadanes algo optimized approach 
        //tc:O(n) sc:O(1)
        int minsofar=INT_MAX;
        int maxsofar=0;
        //traverse throughout the array and find the min element till the element you've arrived ar
        for(int i=0;i<prices.size();i++){
            minsofar=min(minsofar,prices[i]);
            //parallely calculate thr max profit and store it to compare it with every iterations of prices[i]-minsofar
            maxsofar=max(maxsofar,prices[i]-minsofar);
        }
        return maxsofar; //return the max profit
    }
}