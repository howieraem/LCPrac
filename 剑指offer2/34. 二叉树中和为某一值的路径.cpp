/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        backtrack(root, path, target);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(TreeNode* node, vector<int> &path, int curTarget) {
        if (!node)  return;
        path.push_back(node->val);
        if (!node->left && !node->right && node->val == curTarget) {
            res.push_back(vector<int>(path));
        } else {
            curTarget -= node->val;
            backtrack(node->left, path, curTarget);
            backtrack(node->right, path, curTarget);
        }
        path.pop_back();
    }
};