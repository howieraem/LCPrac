import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=609 lang=java
 *
 * [609] 在系统中查找重复文件
 */

// @lc code=start
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> d = new HashMap<>();

        for (String path : paths) {
            String[] frags = path.split("\\s+");
            String dir = frags[0];
            for (int i = 1; i < frags.length; ++i) {
                String frag = frags[i];
                String[] fileNameAndContent = frag.split("\\(", 2);
                // Keep the trailing ')' as it doesn't affect results
                List<String> samePaths = d.computeIfAbsent(fileNameAndContent[1], k -> new ArrayList<>());
                samePaths.add(dir + '/' + fileNameAndContent[0]);
            }
        }

        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, List<String>> e : d.entrySet()) {
            List<String> keyRes = e.getValue();
            if (keyRes.size() > 1)  res.add(keyRes);
        }
        return res;
    }
}
// @lc code=end

