import java.util.PriorityQueue;

/*
 * @lc app=leetcode.cn id=480 lang=java
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class MedianFinder {
    // Inspired by Q295
    private PriorityQueue<Integer> large;
    private PriorityQueue<Integer> small;
    private boolean isKOdd;

    MedianFinder(int k) {
        isKOdd = ((k & 1) == 1);

        // min heap to store the larger half of the sliding window
        // large = new PriorityQueue<>((n1, n2) -> n1.compareTo(n2));
        large = new PriorityQueue<>();  // min heap by default in Java

        // max heap to store the smaller half of the sliding window
        small = new PriorityQueue<>((n1, n2) -> n2.compareTo(n1));
    }

    public void insert(int num) {
        small.offer(num);
        large.offer(small.poll());
        reBalance();
    }

    public void remove(int num) {
        if (num >= large.peek()) {
            large.remove(num);
        } else {
            small.remove(num);
        }
        reBalance();
    }

    private void reBalance() {
        while (large.size() > small.size())  small.offer(large.poll());
        while (small.size() > large.size() + 1)  large.offer(small.poll());
    }

    public double getMedian() {
        // be aware of overflow in (large + small) / 2.
        return isKOdd ? (double) small.peek() : (large.peek() / 2. + small.peek() / 2.);
    }
}

class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        MedianFinder mf = new MedianFinder(k);
        for (int i = 0; i < k; ++i) {
            mf.insert(nums[i]);
        }

        int n = nums.length;
        double[] res = new double[n - k + 1];
        res[0] = mf.getMedian();
        for (int i = k; i < n; ++i) {
            mf.insert(nums[i]);
            mf.remove(nums[i - k]);
            res[i - k + 1] = mf.getMedian();
        }
        return res;
    }
}
// @lc code=end

