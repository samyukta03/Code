class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane algo 
        
// time complexity O(n)
// space complexity O(1)

        int largest=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<=0){
                largest=max(largest,sum);
                sum=0;
                
            }
            if(sum>0){
                if(sum>largest)
                    largest=sum;
            }
        }
        return largest;
    }
};
//same algo but in a better coded way
for(int i:nums){
    sum+=nums[i];
    largest=max(sum,largest);
    if(sum<0) sum=0;
}
return largest;

// DP approach Time comp = Space comp = O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);    
 //At each index, we update dp[i] as max between either only choosing current element - nums[i] or extending from previous subarray and choosing current element as well - dp[i-1] + nums[i]   
        return *max_element(begin(dp), end(dp));
    }
};