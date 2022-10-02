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