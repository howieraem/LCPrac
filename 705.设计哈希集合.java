/*
 * @lc app=leetcode.cn id=705 lang=java
 *
 * [705] 设计哈希集合
 */

// @lc code=start
// T: O(1) on avg
// S: O(max), max := the maximum possible key
class MyHashSet {
    private int[] buckets;

    /** Initialize your data structure here. */
    // quick note: n % (2 ^ t) = n & ((1 << t) - 1)
    public MyHashSet() {
        // max key = 1e6
        // 1e6 / 32 = 31250
        buckets = new int[31251];
    }
    
    public void add(int key) {
        // setVal(key / 32, key % 32, true);
        setVal(key >> 5, key & ((1 << 5) - 1), true);
    }
    
    public void remove(int key) {
        // setVal(key / 32, key % 32, false);
        setVal(key >> 5, key & ((1 << 5) - 1), false);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        // return getVal(key / 32, key % 32);
        return getVal(key >> 5, key & ((1 << 5) - 1));
    }

    private void setVal(int bucketIdx, int bitIdx, boolean val) {
        if (val) {
            buckets[bucketIdx] |= (1 << bitIdx);
        } else {
            buckets[bucketIdx] &= ~(1 << bitIdx);
        }
    }

    private boolean getVal(int bucketIdx, int bitIdx) {
        return ((buckets[bucketIdx] >> bitIdx) & 0b1) == 1;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
// @lc code=end

