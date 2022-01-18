/*
 * @lc app=leetcode.cn id=636 lang=java
 *
 * [636] 函数的独占时间
 */
import java.util.List;
import java.util.Stack;

// @lc code=start
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        int pre = -1;
        for (String log : logs) {
            String[] frags = log.split(":");
            int id = Integer.parseInt(frags[0]);
            int time = Integer.parseInt(frags[2]);
            if (frags[1].equals("start")) {
                if (!stack.isEmpty()) {
                    res[stack.peek()] += time - pre;
                }
                stack.push(id);
            } else {
                // Be careful of the end timestamps
                ++time;
                res[stack.pop()] += time - pre;
            }
            pre = time;
        }
        return res;
    }
}
// @lc code=end

