/*
 * @lc app=leetcode id=98 lang=golang
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// Pre-order traversal
func helper(root, curMinNode, curMaxNode *TreeNode) bool {
	if root == nil {
		return true
	}
	if (curMinNode != nil && root.Val <= curMinNode.Val) || (curMaxNode != nil && root.Val >= curMaxNode.Val) {
		return false
	}
	return helper(root.Left, curMinNode, root) && helper(root.Right, root, curMaxNode)
}


// T: O(n)
// S: O(n) recursion stack worst case
func isValidBST(root *TreeNode) bool {
    return helper(root, nil, nil)
}
// @lc code=end

