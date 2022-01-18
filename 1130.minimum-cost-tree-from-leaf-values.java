import java.util.*;

/*
 * @lc app=leetcode id=1130 lang=java
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
    // Similar idea to a Huffman Tree.
    // Since the values of the bottom-most nodes will be involved the 
    // most in calculation, we want them to be as small as possible, 
    // and larger values in the array should be close to the root.
    // Detailed Explanation:
    // https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values/solution/wei-shi-yao-dan-diao-di-jian-zhan-de-suan-fa-ke-xi/
    public int mctFromLeafValues(int[] arr) {
        int ans = 0;

        // We can use a mono-stack to get the small values (stack top).
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.MAX_VALUE);
        for (int x : arr) {
            while (x >= stack.peek()) {
                ans += stack.pop() * Math.min(stack.peek(), x);
            }
            stack.push(x);
        }
        while (stack.size() > 2) {
            // Remaining nodes (with larger values)
            ans += stack.pop() * stack.peek();
        }
        return ans;
    }
}
// @lc code=end

