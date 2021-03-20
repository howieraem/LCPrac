import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=313 lang=java
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] cnts = new int[primes.length];
        List<Integer> uglyNums = new ArrayList<>();
        uglyNums.add(1);
        for (int i = 1; i < n; ++i) {
            int ugly = Integer.MAX_VALUE;
            for (int j = 0; j < primes.length; ++j) {
                ugly = Math.min(ugly, uglyNums.get(cnts[j]) * primes[j]);
            }
            uglyNums.add(ugly);

            for (int j = 0; j < primes.length; ++j) {
                if (ugly == uglyNums.get(cnts[j]) * primes[j]) {
                    ++cnts[j];
                }
            }
        }
        return uglyNums.get(uglyNums.size() - 1);
    }
}
// @lc code=end

