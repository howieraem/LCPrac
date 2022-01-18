/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop_front();
            res.push_back(node->val);
            if (node->left) {
                q.push_back(node->left);
            }
            if (node->right) {
                q.push_back(node->right);
            }
        }
        return res;
    }
};
