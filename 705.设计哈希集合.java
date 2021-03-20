/*
 * @lc app=leetcode.cn id=705 lang=java
 *
 * [705] 设计哈希集合
 */

// @lc code=start
class MyHashSet {
    // private boolean[] exist;

    // /** Initialize your data structure here. */
    // public MyHashSet() {
    //     exist = new boolean[1000001];
    // }
    
    // public void add(int key) {
    //     exist[key] = true;
    // }
    
    // public void remove(int key) {
    //     exist[key] = false;
    // }
    
    // /** Returns true if this set contains the specified element */
    // public boolean contains(int key) {
    //     return exist[key];
    // }

    private int[] buckets;

    /** Initialize your data structure here. */
    public MyHashSet() {
        buckets = new int[40000];   // 40000*32 > 1000000
    }
    
    public void add(int key) {
        setVal(key / 32, key % 32, true);
    }
    
    public void remove(int key) {
        setVal(key / 32, key % 32, false);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return getVal(key / 32, key % 32);
    }

    private void setVal(int bucketIdx, int bitIdx, boolean val) {
        int bitMask;
        if (val) {
            bitMask = buckets[bucketIdx] | (1 << bitIdx);
        } else {
            bitMask = buckets[bucketIdx] & ~(1 << bitIdx);
        }
        buckets[bucketIdx] = bitMask;
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

