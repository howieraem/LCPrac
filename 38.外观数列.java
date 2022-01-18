/*
 * @lc app=leetcode.cn id=38 lang=java
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
    public String countAndSay(int n) {
        if (n == 1)  return "1";
        StringBuilder sb = new StringBuilder();
        String str = countAndSay(n - 1);
        int len = str.length(), start = 0;
        for (int i = 1; i < len + 1; ++i) {
            if (i == len) {
                sb.append(i - start).append(str.charAt(start));
            } else if (str.charAt(i) != str.charAt(start)) {
                sb.append(i - start).append(str.charAt(start));
                start = i;
            }
        }
        return sb.toString();
    }
}
// @lc code=end

