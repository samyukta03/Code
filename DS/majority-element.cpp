Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
//---hashmap  Tc = Sc = O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        for(auto x:mp) if(x.second > nums.size()/2) return x.first;
        return 0;
    }
};

//---APPROACH 2 = Moore Voting algorithm    Tc = O(N)   Sc = O(1)

int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int candidate = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(count  == 0)
                candidate = nums[i];
            
            if(candidate == nums[i])
                count++;
            else
                count--;
        }
        return candidate;
        
    }