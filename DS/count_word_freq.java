/*
Given two string arrays words1 and words2, return the number of strings that appear exactly
once in each of the two arrays.
Example 1:
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
*/
class Solution {
    public int countWords(String[] w1, String[] w2) {
        int n = w1.length;
        int m = w2.length;
        int cnt=0;
       /* if(n<m) {
        String[] buffer = new String[m];
        for (int i = 0; i < m; i++) {
            buffer[i] = w2[i];
            w2[i] = w1[i];
            w1[i] = buffer[i];
        }
        }
    */
        HashMap<String,Integer> map=new HashMap<String,Integer>();
        for(String s : w1) {
       //  int count = map.get(s);
         if (map.get(s)==null)  map.put(s, 1);
         else map.put(s, map.get(s) + 1);
          }
        for(String t : w2){
            if(map.get(t)!=null && map.get(t)<=1){
             if(map.get(t)==1)   cnt++;
            else if(map.get(t)==0)  cnt--;
                map.put(t,map.get(t)-1);
            }
           else if(map.get(t)==null) continue;
        }
        return cnt;
    }
}