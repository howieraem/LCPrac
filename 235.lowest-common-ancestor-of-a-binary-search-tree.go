/*
 * @lc app=leetcode id=235 lang=golang
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

// In a BST where node values are unique, leftChild.Val < root.Val < RightChild.Val
// T: O(n)
// S: O(1)
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	var ans *TreeNode = nil
	for ans == nil {
		if p.Val < root.Val && q.Val < root.Val {
			root = root.Left
		} else if p.Val > root.Val && q.Val > root.Val {
			root = root.Right
		} else {
			// p and q are on different sides, so root is the lowest common ancestor
			ans = root
		}
	}
	return ans
}

// @lc code=end
