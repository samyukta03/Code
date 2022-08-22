Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], 
then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Example 1:
Input: x = -123  Output: -321
class Solution {
public:
    int reverse(int x) {
        int rem = 0,sum=0;
        while(x){
            rem=x%10;
            //here we add a overflow check condition bcz the int_max and int_min are the ranges of integer bit
//and here we dont check by sum*10> or < because we're still multy which lead to overflow so we do int_max/10 and check the range 
            if(sum > INT_MAX/10 || sum < INT_MIN/10 ) return 0; 
            //if its within the range, then proceed the usual 
            else
            {
            sum=(sum*10)+rem;
            x/=10;
            }
        }
        return sum;
    }
};