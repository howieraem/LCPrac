/*
 * @lc app=leetcode.cn id=389 lang=java
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
    // public char findTheDifference(String s, String t) {
    //     int[] cnts = new int[26];
    //     for (int i = 0; i < s.length(); ++i) {
    //         ++cnts[s.charAt(i) - 'a'];   
    //     }
    //
    //     for (int i = 0; i < t.length(); ++i) {
    //         if (--cnts[t.charAt(i) - 'a'] < 0) {
    //             return t.charAt(i);
    //         }
    //     }
    //     return 'a';
    // }

    public char findTheDifference(String s, String t) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans ^= s.charAt(i);   
        }
    
        for (int i = 0; i < t.length(); ++i) {
            ans ^= t.charAt(i);   
        }
        return (char) ans;
    }
}
// @lc code=end

