Given an integer n, count the total number of digit 1 appearing in all non-negative integers
less than or equal to n.
Example 1:
Input: n = 13   Output: 6
Example 2:
Input: n = 0    Output: 0
Constraints:
0 <= n <= 109
//Naive approach 
class Solution {
public:
    int countDigitOne(int n) {
        int ones=0; //decalre count of 1's
        for(int i=n;i>=0;i--){
            int temp=i;
            while(temp){if(temp%10==1) ones++; temp/=10;}
            //ones+=count;
        }
        return ones;
    }
};