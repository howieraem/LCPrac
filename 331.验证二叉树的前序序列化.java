/*
 * @lc app=leetcode.cn id=331 lang=java
 *
 * [331] 验证二叉树的前序序列化
 */


// @lc code=start
class Solution {
    public boolean isValidSerialization(String preorder) {
        // A binary tree is a directed acyclic graph (DAG), so check whether
        // total in degrees == total out degrees
        int in = -1, out = 0, max = preorder.length() - 1;
        int i = 0;
        char[] str = preorder.toCharArray();
        while (i <= max) {
            if (str[i] == ',') {
                ++i;
                continue;
            }
            ++in;   // every node incl. null has one parent
            if (out < in)  return false;
            if (str[i] <= '9' && str[i] >= '0') {
                out += 2;   // a non-null node has two children
                while (i < max && str[i + 1] <= '9' && str[i + 1] >= '0') {
                    // in case there are more digits in a number
                    ++i;
                }
            }
            ++i;
        }
        return out == in;
    }
}
// @lc code=end

