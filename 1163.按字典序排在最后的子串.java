/*
 * @lc app=leetcode.cn id=1163 lang=java
 *
 * [1163] 按字典序排在最后的子串
 */

// @lc code=start
class Solution {
    public String lastSubstring(String s) {
        char[] str = s.toCharArray();
        int index = str.length - 1;
        int max = 0;

        for (int i = str.length - 1; i >= 0; --i) {
            if (str[i] - 'a' > max) {
                index = i;
                max = str[i] - 'a';
            } else if (str[i] - 'a' == max) {
                if (i >= 1 && str[i] == str[i-1])  continue;    // if the character at the front is the same, skip the substring comparison below
                int tmp = index;
                index = i;
                max = str[i] - 'a';
                for (int j = i, k = tmp; j < str.length && k < str.length; ++j, ++k) {
                    // do substring comparisons behind the char locations with equal ASCII values
                    if (str[k] == str[j])  continue;
                    if (str[k] > str[j]) {
                        index = tmp;
                        max = str[index] - 'a';
                        break;
                    } else if (str[k] < str[j]) {
                        break;
                    }
                }
            }
        }
        return s.substring(index);
    }
}
// @lc code=end

