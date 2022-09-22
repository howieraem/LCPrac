/*
 * @lc app=leetcode id=543 lang=golang
 *
 * [543] Diameter of Binary Tree
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
// Note: In Go, need to pass either array pointer or slice to modify res 
func helper(root *TreeNode, res *[1]int) int {
	if root == nil {
		return 0
	}
	leftDepth := helper(root.Left, res)
	rightDepth := helper(root.Right, res)

	curDiameter := leftDepth + rightDepth
	if curDiameter > res[0] {
		res[0] = curDiameter
	}
	
	if leftDepth > rightDepth {
		return leftDepth + 1
	} else {
		return rightDepth + 1
	}
}


// T: O(n)
// S: O(n) worst case, linked list
func diameterOfBinaryTree(root *TreeNode) int {
    res := [1]int{0}
	helper(root, &res)
	return res[0]
}
// @lc code=end

