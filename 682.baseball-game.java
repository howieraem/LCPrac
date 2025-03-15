/*
 * @lc app=leetcode id=682 lang=java
 *
 * [682] Baseball Game
 */
import java.util.*;

// @lc code=start
class Solution {
    // Stack
    // T: O(n)
    // S: O(n)
    public int calPoints(String[] operations) {
        Stack<Integer> st = new Stack<>();
        for (String s : operations) {
            if (s.equals("+")) {
                int top = st.empty() ? 0 : st.pop();
                int newTop = top + (st.empty() ? 0 : st.peek());
                st.push(top);
                st.push(newTop);
            } else if (s.equals("C")) {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s.equals("D")) {
                st.push(st.empty() ? 0 : (st.peek() << 1));
            } else {
                try {
                    st.push(Integer.parseInt(s));
                } catch (NumberFormatException e) {
                    
                }
            }
        }

        int ans = 0;
        for (int x : st) {
            ans += x;
        }
        return ans;
    }
}
// @lc code=end

