class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       if(nums2.size()>nums1.size())
           swap(nums1,nums2);
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            // m.insert({i,nums1[i]});
            m[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]>0){
                res.push_back(nums2[i]);
                --m[nums2[i]];
            }
        }
        return res;
    }
};
//step 1 check the sizes of  both arrays and swap if the 2nd array is larger than first 
//use hashmap, first store the first array elemetns in hash map and increment their count ie)it'll be positive
//now in the second array for each element, check if its there in the hashmap and if its there then 
//decrement the count of that element in hashmap by 1 and push that element into the result array 
//now return the result array that has the intersection values 

//time compl O(m+n) iterate through both arrays in seprate for loops
//space comp O(min(m,n)) -- because we store the contents of smaller array


class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        if(n2.size()>n1.size())
           swap(n1,n2);
        vector<int> ans;
        unordered_map<int,int>m1;
            for(auto x:n1) m1[x]++;
            for(auto x:n2) if(m1[x]>0 && find(ans.begin(),ans.end(),x)==ans.end()) {
                ans.push_back(x) ;
                m1[x]--;
            }
        //    for(auto x:m1) if(x.second==0) ans.push_back(x.first);
         sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};


// INTERSECTION OF MULTIPLE ARRAYS
/*
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers,
return the list of integers that are present in each array of nums sorted in ascending order.
Example 1:
Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of
 nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
*/
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            for(int i: it) {
                mp[i]+=1;
            }
        }
        int n = nums.size();
        vector<int>ans;
        for(auto x:mp){
            if(x.second % n == 0) ans.push_back(x.first);
        }
        return ans;
    }
};
