import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=78 lang=java
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    List<List<Integer>> res;

    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        Stack<Integer> track = new Stack<>();
        backtrack(nums, 0, track);
        return res;
    }

    private void backtrack(int[] nums, int start, Stack<Integer> track) {
        res.add(new ArrayList<Integer>(track));
        for (int i = start; i < nums.length; ++i) {
            track.push(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop();
        }
    }
}
// @lc code=end

