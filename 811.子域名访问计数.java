/*
 * @lc app=leetcode.cn id=811 lang=java
 *
 * [811] 子域名访问计数
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

// @lc code=start
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> res = new ArrayList<>();
        Map<String, Integer> cnts = new HashMap<>();
        for (String cpd : cpdomains) {
            String[] cnd = cpd.split("\\s+");
            int cnt = Integer.valueOf(cnd[0]);
            String[] ss = cnd[1].split("\\.");
            int last = ss.length - 1;
            String subdomain = "";
            for (int i = last; i >= 0; --i) {
                subdomain = ss[i] + (i < last ? "." : "") + subdomain;
                cnts.put(subdomain, cnts.getOrDefault(subdomain, 0) + cnt);
            }
        }

        for (String sd : cnts.keySet()) {
            res.add(cnts.get(sd) + " " + sd);
        }
        return res;
    }
}
// @lc code=end

