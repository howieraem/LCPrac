import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=46 lang=java
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    List<List<Integer>> res;

    public List<List<Integer>> permute(int[] nums) {
        res = new ArrayList<>();
        Stack<Integer> track = new Stack<>();
        backtrack(nums, track);
        return res;
    }

    private void backtrack(int[] nums, Stack<Integer> track) {
        if (track.size() == nums.length) {
            res.add(new ArrayList<Integer>(track));
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (track.contains(nums[i]))  continue;
            track.add(nums[i]);
            backtrack(nums, track);
            track.pop();
        }
    }
}
// @lc code=end

