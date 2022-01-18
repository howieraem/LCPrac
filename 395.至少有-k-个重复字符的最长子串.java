/*
 * @lc app=leetcode.cn id=395 lang=java
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
    private static final int N_CH_TYPES = 26;

    // public int longestSubstring(String s, int k) {
    //     int ans = 0, n = s.length();
    //
    //     for (int nt = 1; nt <= N_CH_TYPES; ++nt) {
    //         int l = 0, r = 0;
    //         int[] cnt = new int[N_CH_TYPES];
    //         int tot = 0, less = 0;
    //
    //         // expand window
    //         while (r < n) {
    //             ++cnt[s.charAt(r) - 'a'];
    //             if (cnt[s.charAt(r) - 'a'] == 1) {
    //                 ++tot;
    //                 ++less;
    //             }
    //             if (cnt[s.charAt(r) - 'a'] == k) {
    //                 --less;
    //             }
    //
    //             // shrink window to ensure the current answer is limited to 
    //             // only `nt` kinds of characters
    //             while (tot > nt) {
    //                 --cnt[s.charAt(l) - 'a'];
    //                 if (cnt[s.charAt(l) - 'a'] == k - 1) {
    //                     ++less;
    //                 }
    //                 if (cnt[s.charAt(l) - 'a'] == 0) {
    //                     --tot;
    //                     --less;
    //                 }
    //                 ++l;
    //             }
    //
    //             if (less == 0) {
    //                 // if the number of types of character with character count < k is 0
    //                 ans = Math.max(ans, r - l + 1);
    //             }
    //             ++r;
    //         }
    //     }
    //     return ans;
    // }

    /**
     * 对于字符串 s，如果存在某个字符 c，它的出现次数大于 0 且小于 k，
     * 则任何包含 c 的子串都不可能满足要求。也就是说，我们将字符串关于
     * c 切分成若干段，则满足要求的最长子串一定出现在某个被切分的段内，
     * 而不能跨越一个或多个段。因此，可分治求解本题。
     */
    public int longestSubstring(String s, int k) {
        return dfs(s, 0, s.length() - 1, k);
    }

    private int dfs(String s, int l, int r, int k) {
        int[] cnt = new int[N_CH_TYPES];
        for (int i = l; i <= r; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }

        char split = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = (char) (i + 'a');
                break;
            }
        }
        if (split == 0) {
            // All character types in substring s[l:r]
            // have more than k characters
            return r - l + 1;
        }

        int i = l, ans = 0;
        while (i <= r) {
            // 当前字符始终是分割字符，分段长度为 0
            while (i <= r && s.charAt(i) == split) { 
                ++i; 
            }
            if (i > r) {
                break;
            }
            
            // 新的分段
            int start = i;
            while (i <= r && s.charAt(i) != split) {
                ++i;
            }

            // 递归地对子串求解
            ans = Math.max(ans, dfs(s, start, i - 1, k));
        }
        return ans;
    }
}
// @lc code=end

