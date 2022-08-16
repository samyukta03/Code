Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:
Input: nums = [1,2,3,4]
Output: 24
// =====> Solution : Brute force: sort and find the 3 maximum ele and 2 min ele 
Time complexity : O(nlogn) 
Space complexity ; O(1)
#include<bits/stdc++.h>
using namespace std;
int maxprod3numbers(vector<int>&nums){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int min1=nums[0];
    int min2=nums[1];
    int max1=nums[n-1];
    int max2=nums[n-2];
    int max3=nums[n-3];
    return max(min1*min2*max1,max1*max2*max3);
}
int main(){
    vector<int> nums = {1,2,3,4};
    cout << maxprod3numbers(nums)<<endl;
    return 0;
}
//to reduce the tc to O(n), dont use sorting
Time complexity : O(n) Space complexity : O(1)
class Solution{
    public:
    int maximumProduct(vector<int>& nums){
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(auto n:nums){
        if(nums[i]>max1){
                max3=max2;
                max2=max1;
                max1=nums[i];
            } else if(nums[i]>max2){
                max3=max2;
                max2=nums[i];
            }else if(nums[i]>max3){
                max3=nums[i];
            }
             if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }else if(nums[i]<min2){
                min2=nums[i];
            }
        }
           return max(min1*min2*max1,max1*max2*max3);
}
};