/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
class Solution {
    
        HashMap<String,List<String>>mp = new HashMap<>();
    
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        for(int i=0;i<n;i++){
            String t = strs[i];
            //comvert this string to char array and sort and convert it to sorted string 
            char[] ch = t.toCharArray();
            Arrays.sort(ch);
            String s = String.valueOf(ch);
            //now for each sorted string, check the map key if its present 
            
            if(mp.containsKey(s)){
                //if the sorted string is already there then add its correspomding anagram 
                mp.get(s).add(t);
            }
            else{
                //add the sorted string as key and add its value
                mp.put(s,new ArrayList());
                mp.get(s).add(t);
            }
        }
        List<List<String>>ans = new ArrayList<>();
        for(String x: mp.keySet())
            ans.add(mp.get(x));
        return ans;
    }
}

//time comp = O(n+n)=O(2n)--(strings traversal and map traversal) 
// SC: O(n) where n is the number of ele in map