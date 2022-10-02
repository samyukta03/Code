/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.
A word is uncommon if it appears exactly once in one of the sentences,and does not appear in the other sentence.
Given two sentences s1 and s2, return a list of all the uncommon words.
You may return the answer in any order.
Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
*/

class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> map = new HashMap();
        for (String word: A.split(" "))
            map.put(word, map.getOrDefault(word, 0) + 1);
        for (String word: B.split(" "))
            map.put(word, map.getOrDefault(word, 0) + 1);

        List<String> ans = new LinkedList();
        for (String word: map.keySet())
            if (map.get(word) == 1)
                ans.add(word);

        return ans.toArray(new String[ans.size()]);
    }
}