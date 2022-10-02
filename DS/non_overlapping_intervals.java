/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the 
rest of the intervals non-overlapping.
Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

class Solution {
    public int eraseOverlapIntervals(int[][] iv) {
        int n = iv.length;
        Arrays.sort(iv, (a,b)->(a[0]-b[0]));
        //start with first intervals ending val
        int end = iv[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            //if the starting int end value is lesser than cons interval's strt value like (1,2) (3,4) = (1,,4) then end val of first int is updated meaning there no overlap 
            if(iv[i][0]>=end){
                end = iv[i][1];
            }
            else{
//if theres a overlap we delete the one with larger value and inc count like (1,4) and 1,3 means we can dir give 1,4 bcz 4>1
                cnt++;
              end = Math.min(iv[i][1],end);
            }
        }
        return cnt;
    } 
}