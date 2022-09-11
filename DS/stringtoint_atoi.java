/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'.
Read this character in if it is either. 
This determines if the final result is negative or positive respectively.
 Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached.
 The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 
If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range.
Specifically, integers less than -231 should be clamped to -231, 
and integers greater than 231 - 1 should be clamped to 231 - 1. Return the integer as the final result.
 */
class Solution {
    public int myAtoi(String s) {
        int num=0;
        boolean negative = false;
        s=s.trim();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(i==0 && !Character.isDigit(ch)) {
                if(ch=='-')
                    negative=true;
                else if(ch=='+')
                    continue;
                else
                    break;
            }
            else if(Character.isDigit(ch)) {
                if((Integer.MAX_VALUE-(ch-48))/10<num) return (negative? Integer.MIN_VALUE: Integer.MAX_VALUE);
                num=num*10+(ch-48);
            }
            else
                break;
        }
        return (negative)?num*-1:num;
    }
}