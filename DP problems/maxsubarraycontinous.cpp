Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]   Output: 6 {[4,-1,2,1] has the largest sum = 6}
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

// ----------------------------------KADANES ALGO--------------------------------------//
class Solution {
public:
    //Algo is kadanes algo 
    // declare a variable to store the sum of cons. elements in the array
    //if they add up to <0 then set the sum = 0 
    //else check if the sum obtained till now is larger than max sum obtained before that element and update it 
    //finally return the max_sum obtained so far
    //time comp = O(n) SC: O(1)
    int maxSubArray(vector<int>& nums) {
        int max_sumsofar= INT_MIN; 
        int sumsofar=0;
        for(int i=0;i<nums.size();i++){
            sumsofar+=nums[i];
            max_sumsofar=max(sumsofar,max_sumsofar); 
            if(sumsofar<0) sumsofar=0;           
        }
        return max_sumsofar;
    }
};


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