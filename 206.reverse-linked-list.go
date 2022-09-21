/*
 * @lc app=leetcode id=206 lang=golang
 *
 * [206] Reverse Linked List
 */

type ListNode struct {
    Val int
    Next *ListNode
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// T: O(n)
// S: O(1)
func reverseList(head *ListNode) *ListNode {
    var pre *ListNode = nil
	cur := head

	for cur != nil {
		// Record the original next node, and 
		// connect the node to previous node instead
		originalNext := cur.Next
		cur.Next = pre
		
		// Shift the pre and cur pointer forward
		pre = cur
		cur = originalNext
	}
	return pre
}
// @lc code=end

