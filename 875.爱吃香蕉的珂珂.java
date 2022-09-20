import java.util.Arrays;
/*
 * @lc app=leetcode.cn id=875 lang=java
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int l = 1, r = getMax(piles) + 1;   // min and max speed

        // find left bound (min speed)
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (canFinish(piles, m, H)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    
    private boolean canFinish(int[] piles, int speed, int H) {
        int time = 0;
        for (int n : piles) {
            time += getDuration(n, speed);
        }
        return time <= H;
    }

    /** Returns how long it takes to consume n bananas at given speed. */
    private int getDuration(int n, int speed) {
        // return Math.ceil((double) n / speed);
        // return (n / speed) + ((n % speed > 0) ? 1 : 0);
        return (n + speed - 1) / speed;  
    }

    private int getMax(int[] arr) {
        // int ans = Integer.MIN_VALUE;
        // for (int n : arr) {
        //     ans = Math.max(ans, n);
        // }
        // return ans;
        return Arrays.stream(arr).max().getAsInt();
    }
}
// @lc code=end

