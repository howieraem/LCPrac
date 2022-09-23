/*
 * @lc app=leetcode id=199 lang=golang
 *
 * [199] Binary Tree Right Side View
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

// Note: need to pass a pointer of the slice to append node values properly
func helper(node *TreeNode, depth int, res *[]int) {
	if node == nil {
		return
	}
	if depth == len(*res) {
		*res = append(*res, node.Val)
	}

	depth++

	// IMPORTANT: visit right child first, not a standard post-order traversal.
	// If left child is visited first, then the result will be left side view.
	helper(node.Right, depth, res)
	helper(node.Left, depth, res)
}


// T: O(n)
// S: O(n) recursion stack worst case
func rightSideView(root *TreeNode) []int {
    res := []int{}
	helper(root, 0, &res)
	return res
}
// @lc code=end

