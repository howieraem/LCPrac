/*
 * @lc app=leetcode id=900 lang=java
 *
 * [900] RLE Iterator
 */

// @lc code=start
// S: O(n)
class RLEIterator {
    private int[] arr;
    private int cnt_idx;

    // T: O(1)
    public RLEIterator(int[] A) {
        arr = A;
        cnt_idx = 0;
    }

    // T: O(n) worst
    public int next(int n) {
        // skip a value if the current n is greater than its count
        while (cnt_idx < arr.length && n > arr[cnt_idx]) {
            n -= arr[cnt_idx];
            cnt_idx += 2;
        }
        
        // no element left to exhaust
        if (cnt_idx >= arr.length) {
            return -1;
        }

        // update the count of value
        arr[cnt_idx] -= n;
        return arr[cnt_idx + 1];
    }
}
// @lc code=end

