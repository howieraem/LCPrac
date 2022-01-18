/*
 * @lc app=leetcode.cn id=381 lang=java
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */
import java.util.*;

// @lc code=start
class RandomizedCollection {
    Map<Integer, Set<Integer>> mp;
    List<Integer> lst;
    Random rand = new Random();

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        mp = new HashMap<>();
        lst = new ArrayList<>();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean notExists = true;
        if (mp.containsKey(val) && !mp.get(val).isEmpty()) {
            notExists = false;
        } else {
            mp.put(val, new LinkedHashSet<>());
        }
        mp.get(val).add(lst.size());
        lst.add(val);
        return notExists;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!mp.containsKey(val) || mp.get(val).isEmpty())  return false;
        int last = lst.get(lst.size() - 1);
        int remove_idx = mp.get(val).iterator().next();
        mp.get(val).remove(remove_idx);
        lst.set(remove_idx, last);
        mp.get(last).add(remove_idx);
        mp.get(last).remove(lst.size() - 1);
        lst.remove(lst.size() - 1);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return lst.get(rand.nextInt(lst.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

