import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=767 lang=java
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
    static class Char {
        char c;
        int cnt;

        Char(char c, int cnt) {
            this.c = c;
            this.cnt = cnt;
        }
    }

    public String reorganizeString(String s) {
        Char[] chars = new Char[26];
        for (int i = 0; i < 26; ++i) {
            chars[i] = new Char((char) (i + 'a'), 0);
        }
        int n = s.length();
        int maxCnt = 0;
        for (int i = 0; i < n; ++i) {
            int cIdx = (int) (s.charAt(i) - 'a');
            ++chars[cIdx].cnt;
            maxCnt = Math.max(maxCnt, chars[cIdx].cnt);
        }
        
        if (maxCnt > (s.length() + 1) / 2)  return "";

        // Sort characters by count
        Arrays.sort(chars, (c1, c2) -> c2.cnt - c1.cnt);
        char[] ans = new char[n];

        // Insert the most counted characters at odd places (even indices) first,
        // then insert other characters at even places (odd indices)
        int idx = 0;    
        for (int i = 0; i < 26; ++i) {
            while (chars[i].cnt-- > 0) {
                ans[idx] = chars[i].c;
                idx += 2;
                if (idx >= n)  idx = 1;
            }
        }
        return String.valueOf(ans);
    }
}
// @lc code=end

