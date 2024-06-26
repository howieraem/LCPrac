/*
 * @lc app=leetcode.cn id=547 lang=java
 *
 * [547] 朋友圈
 */

// @lc code=start
/** 
 * Union Find (UF) Helper Class. 
 * 
 * Properties of UF:
 * 1. Node p is connected to itself;
 * 2. If p -> q, then q -> p.
 * 3. If p -> q and q -> r, then p -> r.
 */
class UF {
    // No. of connected components (if none connected this equals the number of nodes)
    private int count;

    private int[] parent;
    private int[] size;

    /**
     * Constructor.
     * 
     * @param n Number of graph nodes.
     */
    public UF(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // a node's parent is itself initially
            size[i] = 1;
        }
    }
    
    /**
     * Connects node p and node q.
     * 
     * @param p An integer less than the graph capacity n.
     * @param q An integer less than the graph capacity n.
     */
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)  return;  // already connected

        // Re-balance height by connecting the smaller graph to the larger graph,
        // to avoid building a linked list
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        --count;
    }

    /**
     * Determines whether two nodes in graph are connected.
     * 
     * @param p An integer less than the graph capacity n.
     * @param q An integer less than the graph capacity n.
     * @return true if p and q are connected.
     */
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    /**
     * Finds the root node of a node.
     * 
     * @param x An integer less than the graph capacity n.
     * @return An integer representing the root node value.
     */
    private int find(int x) {
        while (parent[x] != x) {
            // path compression
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    /**
     * @return The number of connected components in graph.
     */
    public int count() {
        return count;
    }
}


class Solution {
    public int findCircleNum(int[][] M) {
        int n = M.length;
        UF uf = new UF(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (M[i][j] == 1)
                    uf.union(i, j);
            }
        }
        return uf.count();
    }
}
// @lc code=end

