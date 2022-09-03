Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

/*Brute force: 
three loops where i from 0, j from i+1, k=j+1 and if a[i]+a[j]+a[k]==0 then a[i]a[j],a[k] is stores in a set
time comp = O(n^3log m) where n^3 fro three loops, log n for insert into set 
space comp = O(m), varying no of unique triplets in set 
*/

/*Better sol:
Hashmap, store the occurances of all ele in arr, 
iterate vals of a, for(i=0 to n-1) and remove mp[a[i]]--;
iterate vals of b, for(j=i+1 to n-1) and remove mp[a[j]]--;
to find c, -(a+b) if exist in hashmap then set of (a,b,-(a+b)) exsit in triplet, else mp[a[i]]++ and mp[a[j]]++;
time comp=O(n^2 log m) 
space comp = O(m) + O(n)    */

/*OPTIMIZED: 
two pointer: 
Sort the array first, 
two pointers where one pointer will constantly point to a number a, and u have to find if b+c=-a which narrows down to two sum problem
1. so ptr1 points to first ele, and lo ptr points to i+1 and high points to n-1 
2. and lo+hi=-a?,
2.i) if no and lo+hi < a, then move lo ptr as the summation increases until lo+hi=-a
2.ii) if no and lo+hi > a then move high ptr as the summ decreases till lo+hi = -a
2.iii) once u found a triplet, move lo and hi, but to avoid duplicates we have to move lo&hi till its not equal to prev obtained lo value of lo and hi 
-->3) now a should not be the same val as before so move a till its not equal to prev value of a and repeat the same steps
tc: O(n) sc:O(1)
*/
class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        
        Arrays.sort(num);
        
        List<List<Integer>> res = new LinkedList<>(); 
        
        for (int i = 0; i < num.length-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = num.length-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        res.add(Arrays.asList(num[i], num[lo], num[hi]));
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    
                    else hi--;
               }
            }
        }
        return res;
    }
}