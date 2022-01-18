/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        x = k;
        inorder(root);
        return ans;
    }

private:
    int x;
    int ans = INT_MIN;

    void inorder(TreeNode* root) {
        if (!root)  return;
        inorder(root->right);
        if (!(--x)) { 
            ans = root->val;
            return;
        }
        inorder(root->left);
    }
};
