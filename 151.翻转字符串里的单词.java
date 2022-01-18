/*
 * @lc app=leetcode.cn id=151 lang=java
 *
 * [151] 翻转字符串里的单词
 */
// import java.util.*;

// @lc code=start
class Solution {
    /* // API-based solution
    public String reverseWords(String s) {
        // 除去开头和末尾的空白字符
        s = s.trim();
        // 正则匹配连续的空白字符作为分隔符分割
        List<String> wordList = Arrays.asList(s.split("\\s+"));
        Collections.reverse(wordList);
        return String.join(" ", wordList);
    }
    */

    /* // Solution with Deque (still extra space used).
    public String reverseWords(String s) {
        int left = 0, right = s.length() - 1;
        // remove leading spaces
        while (left <= right && s.charAt(left) == ' ') {
            ++left;
        }
        // remove trailing spaces
        while (left <= right && s.charAt(right) == ' ') {
            --right;
        }

        Deque<String> dq = new ArrayDeque<>();
        StringBuilder wordBuilder = new StringBuilder();
        while (left <= right) {
            char c = s.charAt(left);
            if ((wordBuilder.length() != 0) && (c == ' ')) {
                dq.offerFirst(wordBuilder.toString());
                wordBuilder.setLength(0);
            } else if (c != ' ') {
                wordBuilder.append(c);
            }
            ++left;
        }
        dq.offerFirst(wordBuilder.toString());     // don't forget the last one
        return String.join(" ", dq);
    }
    */

    /** Try to solve with O(1) space but not strictly possible in Java as strings are immutable. */
    public String reverseWords(String s) {
        if (s == null) return null;
    
        char[] arr = s.toCharArray();
        int n = arr.length;
    
        // step 1. reverse the whole string
        reverse(arr, 0, n - 1);
        // step 2. reverse each word
        reverseWords(arr, n);
        // step 3. clean up spaces
        return cleanSpaces(arr, n);
    }
    
    void reverseWords(char[] arr, int n) {
        int i = 0, j = 0;
        while (i < n) {
            while (i < j || i < n && arr[i] == ' ')  ++i;  // skip spaces
            while (j < i || j < n && arr[j] != ' ')  ++j;  // skip non spaces
            reverse(arr, i, j - 1);   // reverse the word
        }
    }
    
    // trim leading, trailing and multiple spaces
    String cleanSpaces(char[] arr, int n) {
        int i = 0, j = 0;
    
        while (j < n) {
            while (j < n && arr[j] == ' ')  ++j;                  // skip spaces
            while (j < n && arr[j] != ' ')  arr[i++] = arr[j++];  // keep non spaces
            while (j < n && arr[j] == ' ')  ++j;                  // skip spaces
            if (j < n)  arr[i++] = ' ';   // keep only one space
        }
    
        return new String(arr).substring(0, i);
    }
    
    // reverse arr[] from index i to index j
    private void reverse(char[] a, int i, int j) {
        while (i < j) {
            char tmp = a[i];
            a[i++] = a[j];
            a[j--] = tmp;
        }
    }

}
// @lc code=end

