/*
 * @lc app=leetcode id=100 lang=golang
 *
 * [100] Same Tree
 */
package lc

type TreeNode struct {
	Val   int
	Left  *TreeNode
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

// Pre-order traversal
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

// @lc code=end
