/*
 * @lc app=leetcode.cn id=345 lang=java
 *
 * [345] 反转字符串中的元音字母
 */
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

// @lc code=start
class Solution {
    private static final Set<Character> VOWELS = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

    public String reverseVowels(String s) {
        char[] cs = s.toCharArray();
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (!VOWELS.contains(cs[i]) && i < j)  ++i;
            while (!VOWELS.contains(cs[j]) && i < j)  --j;
            if (i < j) {
                swap(cs, i++, j--);
            }
        }

        return new String(cs);
    }

    private void swap(char[] cs, int i, int j) {
        char tmp = cs[i];
        cs[i] = cs[j];
        cs[j] = tmp;
    }
}
// @lc code=end

