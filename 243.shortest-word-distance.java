/*
 * @lc app=leetcode id=243 lang=java
 *
 * [243] Shortest Word Distance
 */

// @lc code=start
class Solution {
    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        int i1 = -1, i2 = -1, ans = Integer.MAX_VALUE;
        for (int i = 0; i < wordsDict.length; ++i) {
            String w = wordsDict[i];
            if (w.equals(word1)) {
                i1 = i;
                if (i1 != -1 && i2 != -1) {
                    ans = Math.min(ans, Math.abs(i1 - i2));
                }
            }
            if (w.equals(word2)) {
                i2 = i;
                if (i1 != -1 && i2 != -1) {
                    ans = Math.min(ans, Math.abs(i1 - i2));
                }
            }
        }
        return ans;
    }
}
// @lc code=end

