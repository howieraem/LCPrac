import java.util.HashMap;
import java.util.LinkedHashSet;

/*
 * @lc app=leetcode.cn id=460 lang=java
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
    HashMap<Integer, Integer> key2val;
    HashMap<Integer, Integer> key2freq;

    // Relation from frequency to key is one to many.
    // Use linked hash set for efficient editing.
    HashMap<Integer, LinkedHashSet<Integer>> freq2keys;

    int minFreq, cap;

    public LFUCache(int capacity) {
        key2val = new HashMap<>();
        key2freq = new HashMap<>();
        freq2keys = new HashMap<>();
        minFreq = 0;
        cap = capacity;
    }
    
    public int get(int key) {
        if (!key2val.containsKey(key))  return -1;
        increaseFreq(key);
        return key2val.get(key);
    }
    
    public void put(int key, int value) {
        if (cap <= 0)  return;
        if (key2val.containsKey(key)) {
            key2val.put(key, value);
            increaseFreq(key);
            return;
        }

        if (cap <= key2val.size())  removeMinFreqKey();
        key2val.put(key, value);
        key2freq.put(key, 1);
        freq2keys.putIfAbsent(1, new LinkedHashSet<>());
        freq2keys.get(1).add(key);
        minFreq = 1;
    }

    private void increaseFreq(int key) {
        int oldFreq = key2freq.get(key);
        key2freq.put(key, oldFreq + 1);

        freq2keys.get(oldFreq).remove(key);
        freq2keys.putIfAbsent(oldFreq + 1, new LinkedHashSet<>());
        freq2keys.get(oldFreq + 1).add(key);

        if (freq2keys.get(oldFreq).isEmpty()) {
            freq2keys.remove(oldFreq);
            if (oldFreq == minFreq) {
                ++minFreq;
            }
        }
    }

    private void removeMinFreqKey() {
        LinkedHashSet<Integer> leastFrequentKeys = freq2keys.get(minFreq);
        // remove the oldest key
        int deletedKey = leastFrequentKeys.iterator().next();
        leastFrequentKeys.remove(deletedKey);
        if (leastFrequentKeys.isEmpty()) {
            // Since this function is only called when key does not exist
            // and minFreq will be set to 1 later anyways, no need to
            // update minFreq here. 
            freq2keys.remove(minFreq); 
        }
        
        key2val.remove(deletedKey);
        key2freq.remove(deletedKey);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

