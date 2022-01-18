import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=412 lang=java
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> res = new ArrayList<>();

        for (int i = 1; i <= n; ++i) {
            StringBuilder ans = new StringBuilder();

            if (i % 3 == 0) {
                ans.append("Fizz");
            }
            if (i % 5 == 0) {
                ans.append("Buzz");
            }

            if (ans.length() == 0) {
                res.add(Integer.toString(i));
            } else {
                res.add(ans.toString());
            }
        }
        return res;
    }
}
// @lc code=end

