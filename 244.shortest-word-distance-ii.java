import java.util.*;
/*
 * @lc app=leetcode id=244 lang=java
 *
 * [244] Shortest Word Distance II
 */

// @lc code=start
class WordDistance {
    private Map<String, List<Integer>> wordIdxs;
    private Map<String, Integer> cache;     // useful when a pair is queried multiple times

    public WordDistance(String[] wordsDict) {
        wordIdxs = new HashMap<>();
        cache = new HashMap<>();

        // Note: computing minimum distances between all pairs of words here
        // is too time-consuming.

        for (int i = 0; i < wordsDict.length; ++i) {
            wordIdxs.computeIfAbsent(wordsDict[i], k -> new ArrayList<>()).add(i);
        }
    }
    
    public int shortest(String word1, String word2) {
        String key = word1 + '_' + word2;
        if (cache.containsKey(key))  return cache.get(key);
        List<Integer> l1 = wordIdxs.get(word1), l2 = wordIdxs.get(word2);
        
        // l1 and l2 are sorted
        int i = 0, j = 0, ans = Integer.MAX_VALUE;
        while (i < l1.size() && j < l2.size()) {
            int idx1 = l1.get(i), idx2 = l2.get(j);
            if (idx1 > idx2) {
                ans = Math.min(ans, idx1 - idx2);
                ++j;
            } else {
                ans = Math.min(ans, idx2 - idx1);
                ++i;
            }

            // Early break: cannot get smaller than 1
            if (ans == 1) {
                cache.put(key, 1);
                return 1;
            }
        }
        cache.put(key, ans);
        return ans;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.shortest(word1,word2);
 */
// @lc code=end

