/*
 * @lc app=leetcode id=572 lang=golang
 *
 * [572] Subtree of Another Tree
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

// Borrowed from Q100, pre-order traversal
// T: O(min(m, n)), m := the no. of nodes in p, n := the no. of nodes in q
// S: O(min(m, n)) worst case, linked list
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil {
		return q == nil
	} 
	if q == nil {
		return false
	}
	return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}


// Pre-order traversal
// T: O(m * n), m := the number of nodes in tree, n := the number of nodes in subtree
// S: O(m * n) worst case
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    if root == nil {
		return subRoot == nil
	}
	if isSameTree(root, subRoot) {
		return true
	}
	return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}
// @lc code=end

