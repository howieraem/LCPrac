/*
 * @lc app=leetcode.cn id=721 lang=java
 *
 * [721] 账户合并
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;

// @lc code=start
class UF {
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

        // 小树接到大树下面，使时间复杂度为O(logN)
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    /**
     * Finds the root node of a node.
     * 
     * @param x An integer less than the graph capacity n.
     * @return An integer representing the root node value.
     */
    public int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩，进一步降低find()和union()复杂度至O(1)，
            // 动态调整使树高不超过3
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        final int n = accounts.size();
        UF uf = new UF(n);
        Map<String, Integer> email2nameId = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            List<String> emails = accounts.get(i);
            for (int j = 1; j < emails.size(); ++j) {
                String email = emails.get(j);
                if (!email2nameId.containsKey(email)) {
                    email2nameId.put(email, i);
                } else {
                    uf.union(i, email2nameId.get(email));
                }
            }
        }

        Map<Integer, List<String>> nameId2emails = new HashMap<>();
        for (Map.Entry<String, Integer> e : email2nameId.entrySet()) {
            List<String> newEmails = nameId2emails.computeIfAbsent(uf.find(e.getValue()), k -> new ArrayList<>());
            newEmails.add(e.getKey());
        }
              
        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<Integer, List<String>> e : nameId2emails.entrySet()) {
            List<String> emails = e.getValue();
            Collections.sort(emails);
            List<String> account = new ArrayList<>();
            account.add(accounts.get(e.getKey()).get(0));
            account.addAll(emails);
            res.add(account);
        }
        return res;
    }
}
// @lc code=end

