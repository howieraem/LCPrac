/*
 * @lc app=leetcode id=245 lang=java
 *
 * [245] Shortest Word Distance III
 */

// @lc code=start
class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        boolean isSame = word1.equals(word2);
        int i1 = -1, i2 = -1, ans = Integer.MAX_VALUE;
        for (int i = 0; i < wordsDict.length; ++i) {
            String w = wordsDict[i];
            if (w.equals(word1)) {
                if (isSame && i1 != -1) {
                    i2 = i1;
                }
                i1 = i;
                if (i1 != -1 && i2 != -1) {
                    ans = Math.min(ans, Math.abs(i1 - i2));
                }
            }
            if (!isSame && w.equals(word2)) {
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

