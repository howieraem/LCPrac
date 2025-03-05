/*
 * @lc app=leetcode id=1910 lang=java
 *
 * [1910] Remove All Occurrences of a Substring
 */
import java.util.*;

// @lc code=start
class Solution {
    // Modified KMP + stack + two pointers
    // T: O(m + n)
    // S: O(m + n)
    public String removeOccurrences(String s, String part) {
        final int m = s.length();
        final int n = part.length();

        // Obtain LPS array
        int[] f = new int[n];
        int i = 1;
        int j = 0;
        while (i < n) {
            if (part.charAt(i) == part.charAt(j)) {
                f[i++] = ++j;
            } else if (j > 0) {
                j = f[j - 1];
            } else {
                ++i;
            }
        }

        Stack<Character> st = new Stack<>();

        // Store `part`'s index `j` so that after deletion we can resume
        int[] idxs = new int[m + 1];

        i = 0;
        j = 0;
        while (i < m) {
            char c = s.charAt(i);
            st.push(c);

            if (c == part.charAt(j)) {
                idxs[st.size()] = ++j;

                if (j == n) {
                    // Do deletion
                    int len = n;
                    while (len != 0) {
                        st.pop();
                        --len;
                    }
                    
                    // Restore j for next pattern
                    j = st.empty() ? 0 : idxs[st.size()];
                }
            } else {
                if (j > 0) {
                    --i;
                    j = f[j - 1];
                    st.pop();
                } else {
                    // if the current stack is not empty and j == 0, 
                    // need to correct the previously stored j
                    idxs[st.size()] = 0;
                }
            }

            ++i;
        }

        StringBuilder sb = new StringBuilder();
        while (!st.empty()) {
            sb.append(st.pop());
        }
        return sb.reverse().toString();
    }
}
// @lc code=end

