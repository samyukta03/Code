class Solution {
public:
    int rob(vector<int>& nums) {
      int i;
      int n=nums.size();
      int tot,tot2;
        for(i=0;i<n;i+=2){
           tot+=nums[i];
        }
      for(i=1;i<n;i+=2){
           tot2+=nums[i];
        }
        return max(tot,tot2);
    }
};