import java.util.*;

/*
 * @lc app=leetcode.cn id=827 lang=java
 *
 * [827] 最大人工岛
 */

// @lc code=start
class UF {
    private int[] parent;
    private int[] size;

    public UF(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // a node's parent is itself initially
            size[i] = 1;
        }
    }
    
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)  return;  // already connected

        // Re-balance height to avoid building a linked list
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public int find(int x) {
        while (parent[x] != x) {
            // path compression
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    public int[] getSize() {
        return size;
    }
    
    public int getConnSize(int x) {
        int root = find(x);
        return size[root];
    }
}

class Solution {
    private static final int[] DIRNS = {-1, 0, 1, 0, -1};

    public int largestIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UF uf = new UF(m * n);  // flattened UF
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 1; k < 3; ++k) {
                        // Considering just right and top directions are sufficient
                        int x = i + DIRNS[k], y = j + DIRNS[k + 1];
                        if (x >= 0 && x < m 
                                && y >= 0 && y < n 
                                && grid[x][y] == 1) {
                            uf.union(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }

        Set<Integer> seen = new HashSet<>();
        int ans = Arrays.stream(uf.getSize()).max().getAsInt();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    seen.clear();
                    for (int k = 0; k < 4; ++k) {
                        // Need to consider all 4 directions to connect islands
                        int x = i + DIRNS[k], y = j + DIRNS[k + 1];
                        if (x >= 0 && x < m 
                                && y >= 0 && y < n 
                                && grid[x][y] == 1) {
                            int root = uf.find(x * n + y);
                            if (!seen.contains(root)) {
                                area += uf.getConnSize(root);
                                seen.add(root);
                            }
                        }
                    }
                    ans = Math.max(ans, area);
                }
            }
        }
        return ans;
    }
}
// @lc code=end

