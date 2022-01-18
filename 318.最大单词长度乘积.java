/*
 * @lc app=leetcode.cn id=318 lang=java
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;

        int[] masks = new int[n], lengths = new int[n];
        for (int i = 0; i < n; ++i) {
            int mask = 0b0;
            String word = words[i];
            int l = word.length();
            lengths[i] = l;
            for (int j = 0; j < l; ++j) {
                // Each bit in mask denotes the existence of 
                // a type of character in current word
                mask |= 1 << (int) (word.charAt(j) - 'a');
            }
            masks[i] = mask;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    // no character in common
                    ans = Math.max(ans, lengths[i] * lengths[j]);
                }
            }
        }
        return ans;
    }

    // private boolean noCommonChar(String s1, String s2) {
    //     int mask1 = 0b0, mask2 = 0b0;
    //     for (int i = 0; i < s1.length(); ++i) {
    //         mask1 |= 1 << (int) (s1.charAt(i) - 'a');
    //     }
    //     for (int i = 0; i < s2.length(); ++i) {
    //         mask2 |= 1 << (int) (s2.charAt(i) - 'a');
    //     }
    //     return (mask1 & mask2) == 0;
    // }
}
// @lc code=end

