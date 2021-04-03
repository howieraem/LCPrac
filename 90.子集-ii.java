/*
 * @lc app=leetcode.cn id=90 lang=java
 *
 * [90] 子集 II
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

// @lc code=start
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(new Stack<>(), nums, nums.length, res);
        return res;
    }

    private void backtrack(Stack<Integer> path, int[] nums, int n, List<List<Integer>> res) {
        if (path.size() <= n) {
            res.add(new ArrayList<>(path));
            for (int i = 0; i < nums.length; ++i) {
                int num = nums[i];
                if (i > 0 && nums[i - 1] == num) {
                    continue;
                }
                path.push(num);
                backtrack(path, Arrays.copyOfRange(nums, i + 1, nums.length), n, res);
                path.pop();
            }
        }
    }
}
// @lc code=end

