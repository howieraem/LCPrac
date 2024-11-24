/*
 * @lc app=leetcode id=110 lang=golang
 *
 * [110] Balanced Binary Tree
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

// Post-order traversal (pruned)
// returns -1 if (sub)tree is imbalanced, otherwise the depth
func helper(node *TreeNode) int {
	if node == nil {
		return 0
	}

	leftDepth := helper(node.Left)
	if leftDepth < 0 {
		// pruning
		return -1
	}
	rightDepth := helper(node.Right)
	if rightDepth < 0 {
		// pruning
		return -1
	}

	// Not using math.Abs() here as it returns float64
	if leftDepth >= rightDepth && leftDepth-rightDepth <= 1 {
		return leftDepth + 1
	} else if leftDepth < rightDepth && rightDepth-leftDepth <= 1 {
		return rightDepth + 1
	} else {
		return -1
	}
}

// T: O(n)
// S: O(log(n)) if tree is balanced, otherwise O(n) worst case
func isBalanced(root *TreeNode) bool {
	return helper(root) != -1
}

// @lc code=end
