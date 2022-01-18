import java.util.Stack;

/*
 * @lc app=leetcode.cn id=739 lang=java
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Stack<Integer> s = new Stack<>();   // stores indices
        for (int i = T.length - 1; i >= 0; --i) {
            while (!s.empty() && T[s.peek()] <= T[i]) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : (s.peek() - i);
            s.push(i);
        }
        return res;
    }
}
// @lc code=end

