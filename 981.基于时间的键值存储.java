/*
 * @lc app=leetcode.cn id=981 lang=java
 *
 * [981] 基于时间的键值存储
 */
import java.util.Map;
import java.util.HashMap;
// import java.util.TreeMap;

import java.util.ArrayList;
import java.util.List;


// @lc code=start
// Method 1: HashMap + TreeMap
// class TimeMap {
//     Map<String, TreeMap<Integer, String>> d;

//     /** Initialize your data structure here. */
//     public TimeMap() {
//         d = new HashMap<>();
//     }

//     public void set(String key, String value, int timestamp) {
//         if (!d.containsKey(key)) {
//             d.put(key, new TreeMap<>());
//         }
//         d.get(key).put(timestamp, value);
//     }

//     public String get(String key, int timestamp) {
//         if (!d.containsKey(key))  return "";
//         TreeMap<Integer, String> values = d.get(key);
//         // Below is the maximum key in `values` that is 
//         // less than or equal to timestamp (probably
//         // implemented with binary sort)
//         Integer t = values.floorKey(timestamp);
//         return t != null ? values.get(t) : "";
//     }
// }

// Method 2: HashMap + Binary Search 
// (not as efficient as TreeMap if value at the timestamp need to be updated)
class TimeMap {
    class Pair<T, V> {
        T t;
        V v;

        public Pair(T timestamp, V value) {
            t = timestamp;
            v = value;
        }
    }

    Map<String, List<Pair<Integer, String>>> d;

    /** Initialize your data structure here. */
    public TimeMap() {
        d = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        if (!d.containsKey(key)) {
            d.put(key, new ArrayList<>());
        }
        // Assuming a timestamp is inserted once only for each key 
        // (i.e. not updating value for the given timestamp)
        d.get(key).add(new Pair<>(timestamp, value));
    }

    public String get(String key, int timestamp) {
        if (!d.containsKey(key))  return "";
        List<Pair<Integer, String>> values = d.get(key);
        int l = 0, r = values.size() - 1;
        // Deal with special cases
        if (timestamp < values.get(l).t)  return "";
        if (timestamp >= values.get(r).t)  return values.get(r).v;

        // Find the maximum timestamp <= the given timestamp,
        // so search for the right (upper) boundary
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            int mTime = values.get(m).t;
            if (mTime <= timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (r < 0)  return "";  
        // Note: no need to check `value.get(r).t == timestamp` here
        return values.get(r).v;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
// @lc code=end

