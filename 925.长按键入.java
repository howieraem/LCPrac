/*
 * @lc app=leetcode.cn id=925 lang=java
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        char[] a1 = name.toCharArray(), a2 = typed.toCharArray();
        int n1 = a1.length, n2 = a2.length;
        if (n1 > n2)  return false;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (a1[i] == a2[j]) {
                ++i;
                ++j;
            } else if (j > 0 && a2[j] == a2[j - 1]) {
                ++j;
            } else {
                return false;
            }
        }
        // Handle any unmatching suffix in `typed`
        while (j < n2) {
            if (a2[j] != a2[j - 1])  return false;
            ++j;
        }
        return i == n1;
    }
}
// @lc code=end

