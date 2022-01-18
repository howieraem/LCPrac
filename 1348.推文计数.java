/*
 * @lc app=leetcode.cn id=1348 lang=java
 *
 * [1348] 推文计数
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;


// @lc code=start
// class TweetCounts {
//     Map<String, List<Integer>> d;

//     public TweetCounts() {
//        d = new HashMap<>();
//     }
    
//     public void recordTweet(String tweetName, int time) {
//         List<Integer> l = d.computeIfAbsent(tweetName, (key) -> new ArrayList<>());
//         l.add(time);
//     }
    
//     public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
//         if (!d.containsKey(tweetName))  return new ArrayList<>();;
//         int delta;
//         switch (freq) {
//             case "minute": delta = 60; break;
//             case "hour": delta = 3600; break;
//             case "day": delta = 86400; break;
//             default: delta = 1; break;
//         }

//         Integer[] res = new Integer[(endTime - startTime) / delta + 1];
//         Arrays.fill(res, 0);

//         for (Integer t : d.get(tweetName)) {
//             if (t >= startTime && t <= endTime) {
//                 int bucketIdx = (t - startTime) / delta;
//                 ++res[bucketIdx];
//             }
//         }
//         return Arrays.asList(res);
//     }
// }

class TweetCounts {

    // key 用户->推文时间->该时间推文发布数目
    private Map<String, TreeMap<Integer,Integer>> userTweetMap;
    
    public TweetCounts() {
        userTweetMap = new HashMap<>();
    }

    // 发布推文
    public void recordTweet(String tweetName, int time) {
        // 当前用户推文集合
        TreeMap<Integer, Integer> tweetMap = userTweetMap.computeIfAbsent(tweetName, k -> new TreeMap<>());
        // 推文时间记录，比之前次数多1
        tweetMap.put(time,tweetMap.getOrDefault(time,0) + 1);// 推文加入
    }

    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        List<Integer> res = new ArrayList<>();
        if (!userTweetMap.containsKey(tweetName)) {
            return res;
        }

        int delta;
        switch (freq) {
            case "minute": delta = 60; break;
            case "hour": delta = 3600; break;
            case "day": delta = 86400; break;
            default: delta = 1; break;
        }

        // 用户的全部推文时间集合
        TreeMap<Integer,Integer> tweetMap = userTweetMap.get(tweetName);
        int start = startTime;
        int end = Math.min(start + delta, endTime + 1);
        while (start <= endTime) {
            int count = 0;
            // 找到发文时间大于等于start的推文
            Map.Entry<Integer,Integer> entry = tweetMap.ceilingEntry(start);
            while (entry != null && entry.getKey() < end){
                count += entry.getValue();  // 推文数累加
                // 找比当前大的推文时间
                entry = tweetMap.higherEntry(entry.getKey());
            }
            res.add(count);
            // 时间后移
            start = end;
            end = Math.min(end + delta, endTime + 1);
        }
        return res;
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
// @lc code=end

