import java.util.Deque;
import java.util.ArrayDeque;

/*
 * @lc app=leetcode.cn id=239 lang=java
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MonoQueue {
    // Order in q is from max to min
    Deque<Integer> q;

    public MonoQueue() {
        q = new ArrayDeque<>();
    }

    public void push(int n) {
        while (!q.isEmpty() && q.getLast() < n) {
            q.pollLast();
        }
        q.addLast(n);
    }

    public int max() {
        return q.getFirst();
    }

    public void pop(int x) {
        if (x == q.getFirst()) {
            q.pollFirst();
        }
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        MonoQueue window = new MonoQueue();
        int[] res = new int[nums.length - k + 1];   // total number of windows is n-k+1 when stride is 1
        int j = 0;
        for (int i = 0; i < nums.length; ++i) {
            window.push(nums[i]);
            if (i < k - 1) {
                // fill the first k-1 elements in window
                continue;
            }
            res[j] = window.max();
            window.pop(nums[i - k + 1]);    // remove the left most number
            ++j;
        }
        return res;
    }
}
// @lc code=end

