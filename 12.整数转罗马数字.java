import java.util.Map;
import java.util.LinkedHashMap;

/*
 * @lc app=leetcode.cn id=12 lang=java
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
    private static final Map<Integer, String> RULES = new LinkedHashMap<>(){{
        put(1000, "M");
        put(900, "CM"); 
        put(500, "D"); 
        put(400, "CD");
        put(100, "C");
        put(90, "XC"); 
        put(50, "L");
        put(40, "XL"); 
        put(10, "X");
        put(9, "IX"); 
        put(5, "V");
        put(4, "IV"); 
        put(1, "I");
    }};

    public String intToRoman(int num) {
        StringBuffer ans = new StringBuffer();
        for (Map.Entry<Integer, String> e : RULES.entrySet()) {
            int dec = e.getKey();
            if (num >= dec) {
                int cnt = num / dec;
                num %= dec;
                for (int i = 0; i < cnt; ++i) {
                    ans.append(e.getValue());
                }
            }
        }
        return ans.toString();
    }
}
// @lc code=end

