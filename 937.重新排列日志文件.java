import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=937 lang=java
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] s1 = log1.split(" ", 2), s2 = log2.split(" ", 2);
            boolean isDigit1 = Character.isDigit(s1[1].charAt(0)),
                    isDigit2 = Character.isDigit(s2[1].charAt(0));
            if (isDigit1 || isDigit2) {
                // isDigit1 && isDigit2 => log1 = log2 => log1, log2 (order unchanged)
                // isDigit1 && !isDigit2 => log1 > log2 => log2, log1
                // !isDigit1 && isDigit2 => log1 < log2 => log1, log2
                return isDigit1 ? (isDigit2 ? 0 : 1) : -1;
            }
            // Compare contents first and then identifiers
            int cmp = s1[1].compareTo(s2[1]);
            if (cmp != 0)  return cmp;
            return s1[0].compareTo(s2[0]);
        });
        return logs;
    }
}
// @lc code=end

