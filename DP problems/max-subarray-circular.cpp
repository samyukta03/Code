Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
//Soln 1 
 // BF Approach ---------Kadane algo --------------------------                             Applying kadanes algo, take an index start and find the max sub array to the end index, next icnrement the start index to second, but the end index is incremented from arr[n] to arr[0], by index%N Hence the TC becomes O(n^2) in this case                                                 Optimized:   Two cases are possible : 1. No wrapped fashion, all elements are arranged.          2. Wrapping is present bw starting and ending elements                                          For Case1, do kadanes algo to find the max sum.                                                 For case  2 we convert wrapping to non wrapping by first store the tot array sum and then invert the sign of all ele in array and find the max sum of this using kadanes algo and add this max sum to tot array sum.                                                                               Return the max of sum obtained w/out inverting and after inverting
class Solution {
public:
 //-----> Time complexity : O(n) Space complexity : O(1)
      int kadanealgo(vector<int>&arr){
        int maxsum=arr[0];
        int sum=arr[0];
        for(int i=1;i<arr.size();i++){
          sum=max(sum+=arr[i],arr[i]); //basically if the curr ele is greater than the prev sum obtained + current ele, then that index is what the new sum starts from 
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
     int kadanesum = kadanealgo(nums); //case 1, normal max sub array sum
        if(kadanesum<0) return kadanesum; //when all elements are -ve
     int totarsum=0;
        for(int i=0;i<nums.size();i++){ //cal tot array sum and parallely invert the elements
            totarsum+=nums[i];
            nums[i]=-nums[i];//by inverting we are able to reuse the kadane's algo on it to find the maximum( but in reality minimum subarray) from the array .
        }
    int maxsumcirc = totarsum+kadanealgo(nums); //sum of given array + maximum subarray sum of inverted subarray
        return max(kadanesum,maxsumcirc); //return max of case 1 and 2
    }
};
