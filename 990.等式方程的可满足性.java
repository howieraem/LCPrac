/*
 * @lc app=leetcode.cn id=990 lang=java
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
/** 
 * Union Find (UF) Helper Class. 
 * 
 * Properties of UF:
 * 1. Node p is connected to itself;
 * 2. If p is connected to q, then q is connected to p.
 * 3. If p -> q and q -> r, then p -> r.
 */
class UF {
    // 连通分量个数（如无任何连接时等于节点数）
    private int count;
    // 存储一棵树
    private int[] parent;
    // 记录树的“重量”，用于平衡树高，降低复杂度至logN，防止产生链表
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
        if (rootP == rootQ)
            return;  // already connected
        
        // 小树接到大树下面，使时间复杂度为O(logN)
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
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    /**
     * Finds the root node of a node.
     * 
     * @param x An integer less than the graph capacity n.
     * @return An integer representing the root node value.
     */
    private int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩，进一步降低find()和union()复杂度至O(1)，
            // 动态调整使树高不超过3
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
    public boolean equationsPossible(String[] equations) {
        UF uf = new UF(26);

        // Add all equal relationships to UF
        for (String eq : equations) {
            if (eq.charAt(1) == '=') {
                char x = eq.charAt(0), y = eq.charAt(3);
                uf.union(x - 'a', y - 'a');
            }
        }

        // Check if any inequalities violate exiting relationships
        for (String eq : equations) {
            if (eq.charAt(1) == '!') {
                char x = eq.charAt(0), y = eq.charAt(3);
                if (uf.connected(x - 'a', y - 'a'))  return false;
            }
        }
        return true;
    }
}
// @lc code=end

