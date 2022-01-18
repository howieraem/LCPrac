import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=409 lang=java
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[58];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'A'];
        }

        int ans = 0;
        for (int n : cnt) {
            // 每个字符最多用偶数次
            ans += n - (n & 1);
        }
        // 如果最终的长度小于原字符串的长度，说明里面某个字符出现了奇数次，
        // 那么那个字符可以放在回文串的中间，所以额外再加一。
        return ans < s.length() ? ans + 1 : ans;
    }
}
// @lc code=end

