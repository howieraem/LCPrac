/*
 * @lc app=leetcode id=226 lang=golang
 *
 * [226] Invert Binary Tree
 */

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// Post-order traversal 
// T: O(n)
// S: O(n) worst case, linked list 
func invertTree(root *TreeNode) *TreeNode {
    if root != nil {
		invertTree(root.Left)
		invertTree(root.Right)
		root.Left, root.Right = root.Right, root.Left
	}
	return root
}
// @lc code=end

