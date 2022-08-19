class Solution {
public:
    //time comp = O(n) sc = O(1)
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) //at each maxima we sell the stock 
                profit+=prices[i]-prices[i-1]; //and cal the profit from the prev minima
     }
        return profit;
    }
};
/* Basically, we're using greedy algo here. Everytime we buy a stock at min price we 
sell it at max prices, so we traverse through the arrray & in spite of tracking every
 minima and maxima to calculate the maximum profit, we can directly add those values to
  our profit for which we found a positive slope that is prices[i]>prices[i-1]. */