//2 pointer approach 
//time comp = O(n) = space compl
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0; //the ptr that will point to recently changed element's index
        for(int j=1;i<nums.size();j++){
           if(nums[i]!=nums[j]){ //if the recently changed element is not a duplicate 
                  ++i; //change the recently changed index to next and swap that value with the new value
            nums[i]=nums[j];
           }
         }
         //i stores the number of non-duplicate values so we return i+1 as i is the index 
        return i+1;
    }
};