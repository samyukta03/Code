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