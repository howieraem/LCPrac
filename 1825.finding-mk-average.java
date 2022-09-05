/*
 * @lc app=leetcode id=1825 lang=java
 *
 * [1825] Finding MK Average
 */
import java.util.*;

// @lc code=start
class MKAverage {
    private int m, k, sz;
    private Queue<Integer> q;
    private long sum;
    private TreeMap<Integer, Integer> left, mid, right;
    private int leftSz, midSz, rightSz;

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
        sz = m - (k << 1);
        q = new ArrayDeque<>();
        left = new TreeMap<>();
        mid = new TreeMap<>();
        right = new TreeMap<>();
    }
    
    // T: O(log(m))
    public void addElement(int num) {
        if (q.size() == m) {
            remove(q.poll());
        }
        add(num);
        q.offer(num);
    }
    
    // T: O(1)
    public int calculateMKAverage() {
        return q.size() == m ? (int)(sum / sz) : -1;
    }

    private void add(int x) {
        left.put(x, left.getOrDefault(x, 0) + 1);
        ++leftSz;
        if (leftSz > k) {
            int leftMax = left.lastKey();
            addToMap(mid, leftMax);
            ++midSz;
            sum += leftMax;
            removeFromMap(left, leftMax);
            --leftSz;
        }
        if (midSz > sz) {
            int midMax = mid.lastKey();
            addToMap(right, midMax);
            ++rightSz;
            sum -= midMax;
            removeFromMap(mid, midMax);
            --midSz;
        }
    }

    private void remove(int x) {
        if (left.containsKey(x)) {
            removeFromMap(left, x);
            --leftSz;
        } else if (mid.containsKey(x)) {
            sum -= x;
            removeFromMap(mid, x);
            --midSz;
        } else {
            removeFromMap(right, x);
            --rightSz;
        }

        if (leftSz < k) {
            int midMin = mid.firstKey();
            addToMap(left, midMin);
            ++leftSz;
            sum -= midMin;
            removeFromMap(mid, midMin);
            --midSz;
        }
        if (midSz < sz) {
            int rightMin = right.firstKey();
            addToMap(mid, rightMin);
            ++midSz;
            sum += rightMin;
            removeFromMap(right, rightMin);
            --rightSz;
        }
    }

    private static void addToMap(TreeMap<Integer, Integer> mp, int x) {
        mp.put(x, mp.getOrDefault(x, 0) + 1);
    }

    private static void removeFromMap(TreeMap<Integer, Integer> mp, int x) {
        mp.put(x, mp.get(x) - 1);
        if (mp.get(x) == 0) {
            mp.remove(x);
        }
    }
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage obj = new MKAverage(m, k);
 * obj.addElement(num);
 * int param_2 = obj.calculateMKAverage();
 */
// @lc code=end

