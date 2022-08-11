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

