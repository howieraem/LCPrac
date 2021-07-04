/*
 * @lc app=leetcode.cn id=1328 lang=java
 *
 * [1328] 破坏回文串
 */

// @lc code=start
class Solution {
    public String breakPalindrome(String palindrome) {
        // Since a character is a palindrome, it is impossible to get an answer.
        if (palindrome.length() <= 1)  return "";

        int n = palindrome.length();
        // Char array seems faster than substring concatenation
        char[] arr = palindrome.toCharArray();
        for (int i = 0; i < n / 2; ++i) {
            if (arr[i] != 'a') {
                arr[i] = 'a';
                return String.valueOf(arr);
            }
        }
        arr[n - 1] = 'b';
        return String.valueOf(arr);
    }
}
// @lc code=end

