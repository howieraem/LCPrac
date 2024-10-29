/** Form of postorder result: [left subtree | right subtree | root] */
class Solution {
public:
/*
    // Solution based on mono-stack: O(N) time
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> monostack;
        int rootVal = INT_MAX;

        // Reverse iteration of postorder: [root | right subtree | left subtree]
        // 维护一个单调栈，每次遇到大于栈顶元素的点，我们认为它是栈顶元素的右子树上的点。
        // 每次遇到比栈顶元素小的点，我们就循环弹出栈顶元素，直到栈为空或者栈顶元素大于它。
        // 这样，最后弹出的节点为它的根。以上过程一直重复下去，如果都满足r_i小于当前根节点，
        // 则返回true，否则返回false。由于我们需要考虑根节点的右子树，所以最初设置初始
        // root值为正无穷。
        // Detailed explanations:
        // https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (postorder[i] > rootVal)  return false;
            while (!monostack.empty() && postorder[i] < monostack.top()) {
                rootVal = monostack.top();
                monostack.pop();
            }
            monostack.push(postorder[i]);
        }
        return true;
    }
*/

    // Solution based on divide and conquer: O(N^2) time. 
    // Interestingly, the runtime in C++ is faster than the mono-stack solution.
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }

private:
    static bool verifyPostorder(vector<int>& postorder, int i, int j) {
        if (i >= j)  return true;
        int rootVal = postorder[j];
        int p = i;
        // Values in the left subtree are always less than the root value
        while (postorder[p] < rootVal) ++p;

        // Left subtree is postorder[i:m] and right subtree is postorder[m:j].
        // Values in the right subtree are always greater than the root value
        int m = p;
        while (postorder[p] > rootVal) ++p;

        // Verify if p is at the root value now.
        // Recursively verify the children subtrees.
        return p == j && verifyPostorder(postorder, i, m - 1) && verifyPostorder(postorder, m, j - 1);
    }
};
