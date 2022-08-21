Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Input: nums = [1,1,0,1,1,1] Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
//time comp  = O(n) sc = O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones=0;
        int l=0; //a ptr that points to 0th index 
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
            l++; //if there are consecutive ones then increment the pointer'
// u store the no.of ones u counted before u encountered a zero in 'ones' and after encountered a zero in 'l' and cal the max of them 
            ones=max(ones,l); 
            }
            if(nums[i]==0) l=0; //if encounter a zero retrace the countr to 0
        }
    return ones;
    }
};