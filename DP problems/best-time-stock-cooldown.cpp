You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        if(n<1) return 0;
       int buy[n],sell[n],rest[n];
        buy[0]=0;
        sell[0]=-prices[0]; //profit initially 
        rest[0]=INT_MIN;
        for(int i=1;i<n;i++){
   buy[i]=max(buy[i-1],rest[i-1]); 
   sell[i]=max(sell[i-1],buy[i-1]-prices[i]);  //max of prev prof and current profit
   rest[i]= sell[i-1]+prices[i]; // profit till prev stock sold + current stock sold price
        }
        return max(buy[n-1],rest[n-1]);
    }
};
/*
 int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                maxprofit+=prices[i]-prices[i-1];
                i++;
            }
        }
        return maxprofit;
    }
*/