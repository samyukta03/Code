Find next permutation:
Algorithm:
step 1: Linearly traverse given array from the end and find a number that is greater than its adjacent nums[i] > nums[i-1]. Store the index of smaller number in breakPoint variable. If there is no such element, reverse entire array and return.

step 2: Linearly traverse from the end and this time find a number larger than nums[breakPoint]. 
Lets call it nums[i].

step 3: Swap nums[i] and nums[breakPoint].

step 4: Reverse the array from index breakPoint + 1 to nums.size().

Example:
Consider nums[] = [1, 3, 5, 4, 2].
Traverse from back and find a breakpoint. Here, index breakPoint = 1 and nums[breakPoint] = 3
Traverse from back and find a number larger than this. Here this number is: nums[i] = 4
Swap nums[breakPoint] and nums[i]. Value after swapping: nums[] = [1, 4, 5, 3, 2].
Reverse array from breakPoint + 1 to nums.size() i.e. these elements: [1, 4, 5, 3, 2]
Final answer = [1, 4, 2, 3, 5].

//tc=O(n)
//sc=O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int index1=-1,index2=-1;
        
        //traverse from the right and find the index that has val greater than prev //index and store the index's as breakpoints
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
              index1=i-1;
                index2=i;
                break;
            }
        }
        //if no breakpoint is found just reverse the array as there is no more lexicorgraphical greater solution
        if(index1<0){
            reverse(nums.begin(),nums.end());
             return;
        }
        //if a breakpoint is found, traverse through the array from the right fing the index that has greater value than the break point and swap the both inndex and reverse from the next index to swapped position till end 
        //this is the next greater permuation
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index1]){
        swap(nums[index1],nums[i]);
        reverse(nums.begin()+index1+1,nums.end());
            break;
            }
        }
    }
};

//optimized approach
 /*Step and intituitions to be followed:
    
    Step 1: Find a break point from last where a single element is not in increasing order 
        i.e, ar[i] < ar[i+1] and keep that index such as ind1
    
    Step 2: Find again from last that which element is just greater than ind1 
        as to follow the dictionary order to place bigger element than ind1 and name ind2
        
    Step 3: Swap ar[ind1] and ar[ind2]
        
    Step 4: Reverse from the next element of ind1 i.e, ind1 + 1 to last of the array
        
    Edge Case: If the array is already increasing order from the last then just reverse it.
    
    Tc = O(n)
    SC = O(1)
     */

int n=nums.size();
int bp=-1,i;
//step1
for(bp=n-2;bp>=0;bp--){
    if(nums[bp]<nums[bp+1])
    break;
}
//edge case
if(bp<0){
    reverse(nums.begin(),nums.end());
    return ;
}
//step2
for(i=n-1;i<=0;i--){
    if(nums[i]>nums[bp]){
        break;
    }
}
swap(nums[bp],nums[i]);
reverse(nums.begin()+bp+1,nums.end());
