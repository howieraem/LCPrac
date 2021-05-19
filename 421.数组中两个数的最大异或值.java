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
        TrieNode[] ns = new TrieNode[2];
        // one for bit 0, another for bit 1
    }

    TrieNode root = new TrieNode();

    private void add(int x) {
        TrieNode p = root;
        for (int i = 31; i >= 0; --i) {
            int u = (x >> i) & 1;   // get bit at ith place
            if (p.ns[u] == null) {
                p.ns[u] = new TrieNode();
            }
            p = p.ns[u];
        }
    }

    /** 
     * Returns the number already added to Trie whose XOR with x
     * is the maximum.
     */
    private int getVal(int x) {
        int ans = 0;
        TrieNode p = root;
        for (int i = 31; i >= 0; --i) {
            int a = (x >> i) & 1, b = 1 - a;
            if (p.ns[b] != null) {
                // Get a bit different from the current bit
                // `a` to result in 1 at this bit, as
                // 0 ^ 1 = 1 ^ 0 = 1.
                ans |= (b << i);
                p = p.ns[b];
            } else {
                ans |= (a << i);
                p = p.ns[a];
            }
        }
        return ans;
    }

    public int findMaximumXOR(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            add(num);
            ans = Math.max(ans, num ^ getVal(num));
        }
        return ans;
    }
}
// @lc code=end

