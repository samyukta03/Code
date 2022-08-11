#include<std/bitsc++.h>
using namespace std;
int i,j;
/*
Brute force solution, 
time complexity : O(n^2) because for every element we loop through consecutive elemens thorought
the array and check for duplicates 
space complexity is O(1)
 bool containsDuplicate(vector<int>& nums) {
        int i,j;
        int n=nums.size();
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    return true;
                 break;
                }     
            }
        }
        return false;
    }
*/
//optimal approach is to sort the array and then check the immediate adj element of one part element 
//if its  a duplicate return true else return false 
//hence the TC will be O(nlogn) and SC will be O(1)

void bubblesort(vector<int>&arr){
 int n=arr.size();
 for(i=0;i<n;i++){
 	for(j=0;j<n-i-1;j++){
 		if(arr[j]>arr[j+1])
 			swap(arr[j],arr[j+1]);
 	}
 }
}
 bool containsDuplicate(vector<int>& nums) {
    
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            return true;
        break;
        }
    }
    return false;
    }