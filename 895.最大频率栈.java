/*
 * @lc app=leetcode.cn id=895 lang=java
 *
 * [895] 最大频率栈
 */
import java.util.*;

// @lc code=start
class FreqStack {
    /* Solution below is O(NlogN) */
    // int pushIdx;
    // Map<Integer, Integer> cnts;
    // PriorityQueue<int[]> pq;

    // public FreqStack() {
    //     pushIdx = 0;
    //     cnts = new HashMap<>();

    //     // Compare by count and then by index, descendingly
    //     pq = new PriorityQueue<>((a1, a2) -> 
    //             a1[1] == a2[1] ? a2[2] - a1[2] : a2[1] - a1[1]);
    // }
    
    // public void push(int val) {
    //     int cnt = cnts.getOrDefault(val, 0) + 1;
    //     cnts.put(val, cnt);
    //     pq.offer(new int[]{val, cnt, pushIdx++});
    // }
    
    // public int pop() {
    //     // DON'T decrement pushIdx here
    //     int[] info = pq.poll();
    //     cnts.put(info[0], info[1] - 1);
    //     return info[0];
    // }

    /* Solution below is O(N) */
    int maxCnt;
    Map<Integer, Integer> cnts;
    Map<Integer, Stack<Integer>> cnt2Nums;

    public FreqStack() {
        maxCnt = 0;
        cnts = new HashMap<>();
        cnt2Nums = new HashMap<>();
    }

    public void push(int val) {
        int cnt = cnts.getOrDefault(val, 0) + 1;
        cnts.put(val, cnt);
        maxCnt = Math.max(maxCnt, cnt);
        // Note that the same val might present in multiple stacks 
        // as its count increments
        cnt2Nums.computeIfAbsent(cnt, k -> new Stack<>()).push(val);
    }

    public int pop() {
        int num = cnt2Nums.get(maxCnt).pop();
        cnts.put(num, maxCnt - 1);
        if (cnt2Nums.get(maxCnt).size() == 0) --maxCnt;
        return num;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
// @lc code=end

