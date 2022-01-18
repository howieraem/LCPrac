/*
 * @lc app=leetcode.cn id=421 lang=java
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
/**
 * Idea: convert a number into 32-bit binary "word", add it to
 * a Trie and do bit reconstruction to get the maximum.
 */
class Solution {
    private class TrieNode {
        TrieNode[] children = new TrieNode[2];
        // one for bit 0, another for bit 1
    }

    TrieNode root = new TrieNode();

    private void insert(int x) {
        TrieNode p = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;   // get bit at the i-th place
            if (p.children[bit] == null) {
                p.children[bit] = new TrieNode();
            }
            p = p.children[bit];
        }
    }

    /** 
     * Returns the number already added to Trie whose XOR with x
     * is the maximum.
     */
    private int getVal(int x) {
        TrieNode p = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int a = (x >> i) & 1, b = 1 - a;
            if (p.children[b] != null) {
                // Get a bit different from the current bit
                // `a` to result in 1 at this bit, as
                // 0 ^ 1 = 1 ^ 0 = 1.
                ans |= (b << i);
                p = p.children[b];
            } else {
                ans |= (a << i);
                p = p.children[a];
            }
        }
        return ans;
    }

    public int findMaximumXOR(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            insert(num);
            ans = Math.max(ans, num ^ getVal(num));
        }
        return ans;
    }
}
// @lc code=end

