import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=401 lang=java
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> res = new ArrayList<>();

        // iterate from 0:00 -> 12:00 and check the count of digit 1s
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (countOnes(i) + countOnes(j) == turnedOn) {
                    res.add(
                        Integer.toString(i) + ":" + 
                        (j < 10 ? "0" + Integer.toString(j) : Integer.toString(j))
                    );
                }
            }
        }
        return res;
    }

    private int countOnes(int num) {
        int ans = 0;
        while (num != 0) {
            num = (num & (num - 1));
            ++ans;
        }
        return ans;
    }
}
// @lc code=end

