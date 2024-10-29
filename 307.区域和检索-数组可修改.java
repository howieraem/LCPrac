/*
 * @lc app=leetcode.cn id=307 lang=java
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
/** Solution based on . */
class NumArray {
    private int[] tree;
    private int n;

    public NumArray(int[] nums) {
        if (nums.length > 0) {
            n = nums.length;
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    private void buildTree(int[] nums) {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            tree[i] = nums[j];  // original nums are stored at leaf nodes
        }
        for (int i = n - 1; i > 0; --i) {
            // value of root = value of left child + value of right child
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    public void update(int index, int val) {
        index += n;
        tree[index] = val;

        // update roots (sums of intervals that are affected)
        while (index > 0) {
            int left = index, right = index;
            if (index % 2 == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }
            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }
    
    public int sumRange(int left, int right) {
        left += n;
        right += n;

        int ans = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                ans += tree[left];
                ++left;
            }
            if (right % 2 == 0) {
                ans += tree[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return ans;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
// @lc code=end

