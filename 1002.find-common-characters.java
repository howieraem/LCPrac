/*
 * @lc app=leetcode id=1002 lang=java
 *
 * [1002] Find Common Characters
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // Hash Map
    // T: O(n * l)
    // S: O(alpha_sz)
    public List<String> commonChars(String[] words) {
        final int ALPHA_SZ = 26;
        int[] allCharCnts = new int[ALPHA_SZ];
        Arrays.fill(allCharCnts, Integer.MAX_VALUE);
        for (String w : words) {
            int[] charCnts = new int[ALPHA_SZ];
            for (char c : w.toCharArray()) {
                ++charCnts[c - 'a'];
            }

            for (int i = 0; i < ALPHA_SZ; ++i) {
                allCharCnts[i] = Math.min(allCharCnts[i], charCnts[i]);
            }
        }

        List<String> res = new ArrayList<>();
        for (int i = 0; i < ALPHA_SZ; ++i) {
            for (int cnt = allCharCnts[i]; cnt > 0; --cnt) {
                res.add(String.valueOf((char) (i + 'a')));
            }
        }
        return res;
    }
}
// @lc code=end

