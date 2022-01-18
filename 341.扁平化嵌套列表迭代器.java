import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=341 lang=java
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private LinkedList<NestedInteger> lst;  // use linked list for efficient addFirst()

    public NestedIterator(List<NestedInteger> nestedList) {
        lst = new LinkedList<>(nestedList);        
    }

    @Override
    public Integer next() {
        return lst.removeFirst().getInteger();
    }

    @Override
    public boolean hasNext() {
        // instead of flattening and storing all integers in the constructor,
        // according to the principle of lazy computing (do not compute result
        // if not required), it is better to implement the flattening here.
        while (!lst.isEmpty() && !lst.getFirst().isInteger()) {
            List<NestedInteger> first = lst.removeFirst().getList();
            for (int i = first.size() - 1; i >= 0; --i) {
                lst.addFirst(first.get(i));
            }
        }
        return !lst.isEmpty();
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
// @lc code=end

