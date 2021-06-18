/*
 * @lc app=leetcode.cn id=65 lang=java
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0)  return false;
        boolean numSeen = false, dotSeen = false, eSeen = false;
        char[] arr = s.trim().toCharArray();
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] >= '0' && arr[i] <= '9') {
                numSeen = true;
            } else if (arr[i] == '.') {
                if (dotSeen || eSeen)  return false;
                dotSeen = true;
            } else if (arr[i] == 'E' || arr[i] == 'e') {
                if (eSeen || !numSeen)  return false;
                eSeen = true;
                numSeen = false;
            } else if (arr[i] == '+' || arr[i] == '-') {
                if (i != 0 && arr[i-1] != 'e' && arr[i-1] != 'E')  return false;
            } else  return false;
        }
        return numSeen;
    }
}
// @lc code=end
