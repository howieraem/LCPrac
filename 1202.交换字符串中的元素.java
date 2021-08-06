import java.util.*;
/*
 * @lc app=leetcode.cn id=1202 lang=java
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class UF {
    private int[] parent;
    private int[] size;

    public UF(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)  return;

        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    public int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
}


class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        if (pairs.size() == 0)  return s;
        int n = s.length();

        // Build a UF graph from index pairs
        UF uf = new UF(n);
        for (List<Integer> pair : pairs) {
            uf.union(pair.get(0), pair.get(1));
        }

        // Map roots in UF to their children in priority queue for lexicographical order.
        // Very efficient when there exist pairs with indices in common. 
        Map<Integer, PriorityQueue<Character>> map = new HashMap<>();
        int[] roots = new int[n];
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            roots[i] = root;
            map.computeIfAbsent(root, k -> new PriorityQueue<>()).offer(s.charAt(i));
        }

        // Reconstruct string
        StringBuilder sb = new StringBuilder();
        for (int root : roots) {
            sb.append(map.get(root).poll());
        }
        return sb.toString();
    }
}
// @lc code=end

