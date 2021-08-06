/*
 * @lc app=leetcode.cn id=1381 lang=java
 *
 * [1381] 设计一个支持增量操作的栈
 */

// @lc code=start
class CustomStack {
    private int[] data;
    private int sz;

    public CustomStack(int maxSize) {
        data = new int[maxSize];
        sz = 0;
    }
    
    public void push(int x) {
        if (sz < data.length) {
            data[sz++] = x;
        }
    }
    
    public int pop() {
        return sz > 0 ? data[--sz] : -1;
    }
    
    public void increment(int k, int val) {
        for (int i = 0; i < k && i < sz; ++i) {
            data[i] += val;
        } 
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
// @lc code=end

