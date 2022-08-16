class Solution {
public:
  //Kadanes algo, but we perform twice one from the start to end, other from end to start       If the count is even, then obviously we would want to include all of them(in fact the whole array) to maximise the product. As multiplying an even number of -ve numbers would make the result +ve.If the count is odd, then we would want to exclude one -ve number from our product, so that the product gets maximised.So we cal from the rear and return the max. 
    int maxProduct(vector<int>& nums) {
 int prodmax=INT_MIN;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            prodmax=max(prod,prodmax);
            if(prod==0) prod=1; //this basically performs the work of dividing the arr to left/right of 0, if theres 0 in our array
        }
         prod = 1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            prodmax=max(prod,prodmax);
            if(prod==0) prod=1;
        }
        
        return prodmax;
    }
};

Time complexity : O(n^2)
Space complexity : O(1)