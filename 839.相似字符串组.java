/*
 * @lc app=leetcode.cn id=839 lang=java
 *
 * [839] 相似字符串组
 */

// @lc code=start
class UF {
    private int cnt;
    private int[] parents;
    private int[] sizes;

    public UF(int n) {
        cnt = n;
        parents = new int[n];
        sizes = new int[n];
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    public void union(int u, int v) {
        int rU = find(u), rV = find(v);
        if (rU != rV) {
            --cnt;
            if (sizes[rU] > sizes[rV]) {
                parents[rV] = rU;
                sizes[rU] += sizes[rV];
            } else {
                parents[rU] = rV;
                sizes[rV] += sizes[rU];
            }
        }
    }

    public int find(int x) {
        while (x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    public int getCount() {
        return cnt;
    }
}

class Solution {
    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        UF uf = new UF(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.union(i, j);
                }
            }
        }
        return uf.getCount();
    }

    private boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) != b.charAt(i) && ++diff > 2)  return false;
        }
        return true;
    }
}
// @lc code=end

