/*
 * @lc app=leetcode id=1507 lang=java
 *
 * [1507] Reformat Date
 */
import java.util.*;

// @lc code=start
class Solution {
    private static final Map<String, String> MONTH = new HashMap<String, String>() {{
        put("Jan", "01");
        put("Feb", "02");
        put("Mar", "03");
        put("Apr", "04");
        put("May", "05");
        put("Jun", "06");
        put("Jul", "07");
        put("Aug", "08");
        put("Sep", "09");
        put("Oct", "10");
        put("Nov", "11");
        put("Dec", "12");
    }};;

    public String reformatDate(String date) {
        String[] data = date.split("\\s+");
        StringBuilder sb = new StringBuilder();
        sb.append(data[2]).append('-');     // year
        sb.append(MONTH.get(data[1])).append('-');  // month
        // Add a leading zero if day is less than 10 
        sb.append(data[0].length() == 3 ? ('0' + data[0].substring(0, 1)) : data[0].substring(0, 2));
        return sb.toString();
    }
}
// @lc code=end

