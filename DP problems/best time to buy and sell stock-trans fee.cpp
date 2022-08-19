class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int maxprofit = 0;
        int minsofar=prices[0];
        //basically we buy at min price, sell when the sp ie) prices[i] > minsofar(cp) + fee, cal the difference and add to maxprofit
        // so when we sell the min so far ie) cp becomes sp - fee  
        for(int i=1;i<n;i++){
            minsofar = min(minsofar,prices[i]);
           if(prices[i]>minsofar + fee ){
            maxprofit += prices[i]-(minsofar+fee);
             minsofar = prices[i]-fee; //sp - fee
           }
        }
        return maxprofit;
    }
};
/*
EG) at itr 1, cp = 1(buy), sp: 3 > 1+2 no. 
Itr 2, cp=1, sp: 2>1+2 no.
Itr 3, cp=1 sp:8>1+2,(sold) yes so profit = 8-1-2=5 and cp = 8-2=6. 
Itr 4, cp = min(6,4)=4(buy), sp: 4 > 4+2 no. 
Itr 5, cp = 4, sp: 9 >4+2(sold) yes, profit = 5+(9-4-2)=5+3=8 and cp = 9-2=7
*/