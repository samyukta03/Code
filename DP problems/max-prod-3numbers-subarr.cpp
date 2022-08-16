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
    return max(min1*min2*max1,max1,max2,max3);
}
int main(){
    vector<int> nums = {1,2,3,4};
    cout << maxprod3numbers(nums)<<endl;
    return 0;
}

Time complexity : O(n) 
Space complexity ; O(1)