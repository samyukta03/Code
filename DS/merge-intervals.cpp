Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the intervals array first
sort(intervals.begin(), intervals.end());
//taking the size of intervals
int n = intervals.size();

    //new vector to store ans
    vector<vector<int>> ans;
       
    //taking start and end from the given intervals vector
    int start = intervals [0][0];
    int end = intervals[0][1];
    
    //now linearly traversing the intervals vector 
    for(int i=0; i<n; i++)
    {
        // sf and ef are starting and ending values of the 1st pair (0 based indexing)
        int sf = intervals[i][0];
        int ef = intervals[i][1];
        if(sf>end)
        {
            ans.push_back({start,end});
            start = sf;
            end = ef;
        }
        
        else
        {
            //updating only end if sf<end
            end = max(ef,end);
        }
    }
    ans.push_back({start,end});
    return ans;
    }
};