/*
 * @lc app=leetcode.cn id=1707 lang=java
 *
 * [1707] 与数组中元素的最大异或值
 */

// @lc code=start
/** Similar to Q421 but with limit. */
class Solution {
    private class TrieNode {
        TrieNode[] children = new TrieNode[2];  // one for bit 0, another for bit 1
        int min = Integer.MAX_VALUE;
    }

    TrieNode root = new TrieNode();

    private void insert(int x) {
        TrieNode p = root;
        p.min = Math.min(p.min, x);
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;   // get bit at the i-th place
            if (p.children[bit] == null) {
                p.children[bit] = new TrieNode();
            }
            p = p.children[bit];
            p.min = Math.min(p.min, x);
        }
    }

    /** 
     * Returns the number already added to Trie whose XOR with x
     * is the maximum.
     */
    private int getValWithLimit(int x, int lim) {
        TrieNode p = root;
        if (p.min > lim)  return -1;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int a = (x >> i) & 1, b = 1 - a;
            if (p.children[b] != null && p.children[b].min <= lim) {
                ans |= (1 << i);
                p = p.children[b];
            } else {
                p = p.children[a];
            }
        }
        return ans;
    }

    public int[] maximizeXor(int[] nums, int[][] queries) {
        for (int num : nums) {
            insert(num);
        }

        int nq = queries.length;
        int[] res = new int[nq];
        for (int i = 0; i < nq; ++i) {
            res[i] = getValWithLimit(queries[i][0], queries[i][1]);
        }
        return res;
    }
}
// @lc code=end

