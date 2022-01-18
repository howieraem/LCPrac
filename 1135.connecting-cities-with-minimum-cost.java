import java.util.*;

/*
 * @lc app=leetcode id=1135 lang=java
 *
 * [1135] Connecting Cities With Minimum Cost
 */

// @lc code=start
class UF {
    int count;
    int[] parent;
    int[] size;
 
    public UF(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Returns true if p and q were not connected
    public boolean union(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ)  return false;

        // Balance size: connect the smaller group to the larger group.
        // This avoids producing a linked list.
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = parent[rootP];
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = parent[rootQ];
            size[rootQ] += size[rootP];
        }
        --count;
        return true;
    }

    public int find(int p) {
        while (parent[p] != p) {
            parent[p] = parent[parent[p]];  // path compression
            p = parent[p];
        }
        return p;
    }
}

class Solution {
    // Kruskal’s algorithm to generate a minimum spanning tree for the graph
    public int minimumCost(int n, int[][] connections) {
        // Sort edges by cost ASC
        Arrays.sort(connections, (e1, e2) -> e1[2] - e2[2]);

        int ans = 0;
        UF uf = new UF(n);

        for (int[] edge : connections) {
            // nodes are 1-indexed
            if (uf.union(edge[0] - 1, edge[1] - 1)) {
                ans += edge[2];
            }
        }
        return uf.count == 1 ? ans : -1;
    }
}
// @lc code=end

