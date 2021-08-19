import java.util.*;
/*
 * @lc app=leetcode.cn id=39 lang=java
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(new ArrayList<>(), candidates, target, res);
        return res;
    }

    private static void backtrack(List<Integer> path, int[] candidates, int remain, List<List<Integer>> res) {
        if (remain == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int num : candidates) {
            if (num > remain)  break;
            // Skips permutations and ensures elements in each answer are sorted 
            if (!path.isEmpty() && num < path.get(path.size() - 1))  continue;
            path.add(num);
            backtrack(path, candidates, remain - num, res);
            path.remove(path.size() - 1);
        }
    }
}
// @lc code=end

