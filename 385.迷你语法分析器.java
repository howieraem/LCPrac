/*
 * @lc app=leetcode.cn id=385 lang=java
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    char[] chars;
    int cur = 0;

    public NestedInteger deserialize(String s) {
        chars = s.toCharArray();
        if (chars[0] != '[')  return new NestedInteger(Integer.valueOf(s));
        return getNest();
    }

    private NestedInteger getNest() {
        NestedInteger nest = new NestedInteger();
        int num = 0, sign = 1;
        while (cur != chars.length - 1) {
            ++cur;
            char c = chars[cur];

            if (c == ',')  continue;
            if (c == '[')  nest.add(getNest());
            else if (c == ']')  return nest;
            else if (c == '-')  sign = -1;
            else {
                // digits
                num = 10 * num + sign * ((int) c - '0');
                char next = chars[cur + 1];
                if (next == ',' || next == ']') {
                    // end of a number
                    nest.add(new NestedInteger(num));
                    num = 0;
                    sign = 1;
                }
            }
        }
        return null;
    }
}
// @lc code=end

