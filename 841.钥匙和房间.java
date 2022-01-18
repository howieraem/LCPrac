import java.util.*;
/*
 * @lc app=leetcode.cn id=841 lang=java
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] accessible = new boolean[n];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        accessible[0] = true;
        int sum = 1;

        while (!stack.empty()) {
            int sz = stack.size();
            for (int i = 0; i < sz; ++i) {
                int room = stack.pop();
                for (int key : rooms.get(room)) {
                    if (!accessible[key]) {
                        stack.push(key);
                        accessible[key] = true;
                        ++sum;
                    }
                }
            }
        }
        return sum == n;
    }
}
// @lc code=end

