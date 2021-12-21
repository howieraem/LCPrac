/*
 * @lc app=leetcode.cn id=1081 lang=java
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
    public String smallestSubsequence(String s) {
        boolean[] visited = new boolean[26];
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }

        StringBuilder sb = new StringBuilder(); // acts like a stack
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (!visited[c - 'a']) {
                // Ensure lexicographical order
                while (sb.length() > 0 && sb.charAt(sb.length() - 1) > c) {
                    if (cnt[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                        // Undo the last visit if any appearances of the current character c 
                        // have not been visited.
                        visited[sb.charAt(sb.length() - 1) - 'a'] = false;
                        sb.deleteCharAt(sb.length() - 1);
                    } else {
                        break;
                    }
                }
                visited[c - 'a'] = true;
                sb.append(c);
            }
            --cnt[c - 'a'];
        }
        return sb.toString();
    }
}
// @lc code=end

