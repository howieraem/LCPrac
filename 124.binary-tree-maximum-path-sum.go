/*
 * @lc app=leetcode id=124 lang=golang
 *
 * [124] Binary Tree Maximum Path Sum
 */
import "math"

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
func helper(node *TreeNode, res *[1]int) int {
	if node == nil {
		return 0
	}

	leftBranchMaxSum := helper(node.Left, res)
	rightBranchMaxSum := helper(node.Right, res)
	
	// Construct the current path with both branches,
	// and update result if path sum is greater
	pathSum := leftBranchMaxSum + rightBranchMaxSum + node.Val
	if pathSum > res[0] {
		res[0] = pathSum
	}

	// When constructing the next path, choose the left branch, the right branch or none of them.
	// One branch includes the current node.
	branchSum := node.Val
	if leftBranchMaxSum > rightBranchMaxSum {
		branchSum += leftBranchMaxSum
	} else {
		branchSum += rightBranchMaxSum
	}
	// Discard both branches, namely the current node and its subtree nodes will not appear in the max path
	if branchSum > 0 {
		return branchSum
	} else {
		return 0
	}
}


// T: O(n)
// S: O(n) recursion stack worst case
func maxPathSum(root *TreeNode) int {
    res := [1]int{math.MinInt32}
	helper(root, &res)
	return res[0]
}
// @lc code=end

