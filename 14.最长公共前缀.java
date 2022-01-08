/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
        // slightly simpler solution
        // if (strs.length == 0) 
        //     return "";
        String ans = strs[0];
        for (int i = 1; i < strs.length; ++i) {
            int j = 0;
            for (; j < ans.length() && j < strs[i].length(); j++) {
                if(ans.charAt(j) != strs[i].charAt(j)) break;
            }
            ans = ans.substring(0, j);
            if (ans.isEmpty())
                return ans;
        }
        return ans;
    }
    /*
    original solution:

    public String longestCommonPrefix(String[] strs) {
        int ns = strs.length;
        if (ns == 0) return "";
        else if (ns == 1) return strs[0];
        int idx = 0;
        boolean valid = true;
        StringBuilder sb = new StringBuilder();

        while (true) {
            String str0 = strs[0];
            if (idx >= str0.length()) break;
            char c = str0.charAt(idx);
            for (int i=1; i<ns; ++i) {
                String str = strs[i];
                if (idx >= str.length() || c != str.charAt(idx)) {
                    valid = false; break;
                }
            }
            if (!valid) break;
            sb.append(c);
            ++idx;
        }
        return sb.toString();
    }
    */
}
// @lc code=end

// class Test14 {
//     public static void main(String[] args) {
//         String[] ss = {"dog1"};
//         Solution s = new Solution();
//         System.out.println(s.longestCommonPrefix(ss));
//     }
// }
