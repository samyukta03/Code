Given a non-empty array of integers nums, every element appears twice except for one.
 Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,1]   Output: 1
// -----------------MAPS  Time complexity : O(n) Space complexity : O(n) 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
     unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(auto itr :mp) if(itr.second==1) return itr.first;
        return 0;
    }
};
//------------USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )
To use this approach you first need to understand about Bitwise XOR operator.
According to this gate , the output is true , only if both the inputs are of opposite kind .
We apply the extended version of this gate in our bitwise XOR operator.
If we do "a^b" , 
it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion 
( on each of the corresponding bits of the numbers).

A^A=0
A^B^A=B
(A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesnt matter.
Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a

We apply the above observations :
Traverse the array and take the Bitwise XOR of each element.
Return the value.
the elements with frequency=2 will result in 0. 
And then the only element with frequency=1 will generate the answer.

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};
TC: O(N)
SC: O(1)