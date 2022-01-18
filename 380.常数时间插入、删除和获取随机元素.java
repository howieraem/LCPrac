/*
 * @lc app=leetcode.cn id=380 lang=java
 *
 * [380] 常数时间插入、删除和获取随机元素
 */
import java.util.*;


// @lc code=start
class RandomizedSet {
    Map<Integer, Integer> mp;
    List<Integer> lst;
    Random rand = new Random();    

    /** Initialize your data structure here. */
    public RandomizedSet() {
        mp = new HashMap<>();
        lst = new ArrayList<>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (mp.containsKey(val))  return false;
        mp.put(val, lst.size());
        lst.add(lst.size(), val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!mp.containsKey(val))  return false;
        int last = lst.get(lst.size() - 1);
        int idx = mp.get(val);
        lst.set(idx, last);
        mp.put(last, idx);
        lst.remove(lst.size() - 1);
        mp.remove(val);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return lst.get(rand.nextInt(lst.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

