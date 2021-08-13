import java.util.*;
/*
 * @lc app=leetcode.cn id=842 lang=java
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution {
    public List<Integer> splitIntoFibonacci(String num) {
        List<Integer> res = new ArrayList<>();
        backtrack(num.toCharArray(), 0, res);
        return res;
    }

    private static boolean backtrack(char[] ds, int idx, List<Integer> res) {
        if (idx == ds.length && res.size() > 2)  return true;
        for (int i = idx; i < ds.length; ++i) {
            if (ds[idx] == '0' && i > idx)  break;
            long num = chars2num(ds, idx, i + 1);

            // As indicated by the required return type, num should not be greater than
            // 2^31 - 1, but a substring might represent a number greater than this
            if (num > Integer.MAX_VALUE)  break;
            int n = res.size();

            // As more digits are attached, `num` will be greater in future iterations, so 
            // break here if `num` is already greater than sum of the previous two numbers
            if (n > 1 && res.get(n - 2) + res.get(n - 1) < num)  break;

            if (n <= 1 || res.get(n - 2) + res.get(n - 1) == num) {
                res.add((int) num);
                if (backtrack(ds, i + 1, res))  return true;
                res.remove(res.size() - 1);   // undo change
            }
        }
        return false;
    }

    private static long chars2num(char[] ds, int start, int end) {
        long ans = 0;
        for (int i = start; i < end; ++i) {
            ans = 10 * ans + (ds[i] - '0');
        }
        return ans;
    }
}
// @lc code=end
