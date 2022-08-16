You are given an integer array values where values[i] represents the value of the 
ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: 
the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.
Example 1:
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
//------------------Brute force approach
Time complexity : O(n^2) Space complexity : O(1) 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int maxscore = INT_MIN;
        while(i<arr.size()){
        while(i<j){
            maxscore = max(maxscore,arr[i]+arr[j]+i-j);
            j--;
        }
        i++;
        j=arr.size()-1;
        }
        return maxscore;
    }
};
// Optimized approach : 
Time complexity : O(n) Space complexity : O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        // the score EQ can be rearranged as arr[i]+i + arr[j]-j. So we've to maximise both parts, but i<j is the condition
       int n=arr.size();
        int maxscore = INT_MIN; //stores the max score
        int aiplusi = arr[0]+0; //store the first ele + index as a[i]+i bcx j starts frm a[1]
        for(int j=1;j<n;j++){
            maxscore = max(maxscore,aiplusi + arr[j]-j); 
            aiplusi = max(aiplusi,arr[j]+j ); // since i and j are same we update a[i]+i to be the max of a[i+1]+(i+1) or the prev val stored
        }
        return maxscore;
    }
};
/*
eg)     8,1,5,2,6 
     ind[0 1 2 3 4]
a[i]+i(only store the max from prev indices) :
        8 8 8 8 10
        x \ \ \ \
a[j]-j  x 0 3 -1 2
Totscore x 8 11 11>7 11>10 hence return 11
*/