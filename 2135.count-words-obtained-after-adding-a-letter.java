/*
 * @lc app=leetcode id=2135 lang=java
 *
 * [2135] Count Words Obtained After Adding a Letter
 */
import java.util.*;

// @lc code=start
class Solution {
    // Since there are only lowercase chars in the start and target words,
    // can use bitmasks to represent them. Because of the "rearrange" 
    // operation, we don't care about the character orders. We can thus 
    // use bitmasks to check the existence of a kind of character.
    // T: O((m + n) * l), m := len(startWords), n := len(targetWords), l := word length
    // S: O(m * l)
    public int wordCount(String[] startWords, String[] targetWords) {
        Set<Integer> vis = new HashSet<>();
        for (String w : startWords) {
            int mask = 0;
            for (char c : w.toCharArray()) {
                mask ^= (1 << (c - 'a'));
            }
            vis.add(mask);
        }

        int ans = 0;
        for (String w : targetWords) {
            int mask = 0;
            char[] wc = w.toCharArray();
            for (char c : wc) {
                mask ^= (1 << (c - 'a'));
            }

            // Try to remove each character in the target word,
            // and check if it is found in `vis` 
            for (char c : wc) {
                if (vis.contains(mask ^ (1 << (c - 'a')))) {
                    ans += 1;
                    break;  // need only one candidate from startWords for each target
                }
            }
        }
        return ans;
    }
}
// @lc code=end

