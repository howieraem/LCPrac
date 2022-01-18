import java.util.*;
/*
 * @lc app=leetcode.cn id=952 lang=java
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start
class UF {
    private int[] parents;
    private int[] sizes;

    public UF(int n) {
        parents = new int[n];
        sizes = new int[n];
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    public int find(int x) {
        while (x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    public void union(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            if (sizes[ri] > sizes[rj]) {
                parents[rj] = ri;
                sizes[ri] += sizes[rj];
            } else {
                parents[ri] = rj;
                sizes[rj] += sizes[ri];
            }
        }
    }

    public int[] getSizes() {
        return sizes;
    }
}

class Solution {
    public int largestComponentSize(int[] nums) {
        // If using union find from gcd of all pairs in `nums`, TLE will happen.
        // Thus, construct the graph with divisible factos of each number,
        // and then find the maximum component by root of each number
        int max = Arrays.stream(nums).max().getAsInt();
        UF uf = new UF(max + 1);

        for (int num : nums) {
            int sqrt = (int) Math.sqrt(num); 
            for (int k = 2; k <= sqrt; ++k) {
                if (num % k == 0) {
                    uf.union(num, k);
                    uf.union(num, num / k);
                }
            }
        }

        int[] cc = new int[max + 1];
        int ans = 1;
        for (int num : nums) {
            ans = Math.max(ans, ++cc[uf.find(num)]);
        }
        return ans;
    }
}
// @lc code=end

