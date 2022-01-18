/*
 * @lc app=leetcode id=1570 lang=java
 *
 * [1570] Dot Product of Two Sparse Vectors
 */
import java.util.*;

// @lc code=start
class SparseVector {
    Map<Integer, Integer> idxMap;
    int n;
    
    SparseVector(int[] nums) {
        idxMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                idxMap.put(i, nums[i]);
            }
        }
        n = idxMap.size();
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        if (n == 0 || vec.n == 0)  return 0;
        // Swap vectors so that `this.n` is always less than `vec.n`,
        // which reduces iterations but yields same result.
        if (n > vec.n)  return vec.dotProduct(this);

        int ans = 0;
        for (Map.Entry<Integer, Integer> e : idxMap.entrySet()) {
            Integer i = e.getKey();
            if (vec.idxMap.containsKey(i)) {
                ans += e.getValue() * vec.idxMap.get(i);
            }
        }
        return ans;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end

