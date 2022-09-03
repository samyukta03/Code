Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the librarys sort function.
Example 1:
Input: nums = [2,0,2,1,1,0]         Output: [0,0,1,1,2,2]
// -------------------------------dutch national flag problem----------------------
     //   Time complexity : O(n) Space complexity : O(1)
class Solution {
     void swap(int[]arr, int a,int b){
        int temp = arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    public void sortColors(int[] nums) {

        int lo=0,hi=nums.length-1,mid=0;
         while(mid<=hi){
            if(nums[mid] == 0 && mid != lo){
                swap(nums, mid, lo);
                lo++;
                
            }else if(nums[mid] == 2 && mid != hi){
                swap(nums, mid, hi);
                hi--;
            }else{
                mid++;
            }
            
        }
    }
}