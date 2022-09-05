/* ******************* JUMP GAME 1 *****************     */

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Return true if possible to reach the last index and false if not possible.
EG I/P: 2-3-1-1-4 O/P: true(because from 2 to 3 and then from 3-4)

class Solution {
public:
    // =====================Linear approach==============
    //-----------------------time comp = O(n) SC:O(1)------------------
    bool canJump(vector<int>& nums) {
        //we start by calculating the  max reach from that index i which is i + no.of jumps from i
        //we store it in a variable called maxsofar and compare and update it at ecery index if that index has max reach than previous
        int maxsofar=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+i > maxsofar)
                maxsofar = nums[i]+i;
            //if we reach at a index where maxreach == i which can mean we break when we are stuck at some index i or we've reached the last index
            if(maxsofar==i) 
                break;
        }
        return maxsofar >=nums.size()-1; //check if  the maxsofar is either reached the last index or passed it and return true, else if stuck somewhere we return false
    }
};
//=====================Recursivw approach=================
class Solution {
    public:
    bool canJump(vector<int>& nums) {
              return solve(0,nums);  //pass the initial postion
    }
    bool solve(int i,vector<int> nums){
        
        if(i==nums.size()-1) return true; //if the start == end return true because u are in the dest
        int reachable=i+nums[i];  //same as cal the max dist reachable from that index
        
        for(int k=i+1;k<=reachable;k++){
                  if(solve(k,nums)){   //from the second index cal the max reachable and id its less tje
                return true;
            }      
        }
        return false;
    }
};

/* ***************** JUMP GAME 2 ***************     */

Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index , return the number of min steps to reach.
Eg) 2,3,1,1,4 Ans: 2 steps ie)2-3 one step and then 3-4 one step

class Solution {
    public int jump(int[] nums) {
     int lastReach = 0;
	int reach = 0;
	int step = 0;
 
	for (int i = 0; i <= reach && i < nums.length; i++) {
		//when last jump can not read current i, increase the step by 1
		if (i > lastReach) {
			step++;
			lastReach = reach;
		}
		//update the maximal jump 
		reach = Math.max(reach, nums[i] + i);
	}
 
	if (reach < nums.length - 1)
		return 0;
 
	return step;
    }
};
