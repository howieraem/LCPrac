/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
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
func swapPairs(head *ListNode) *ListNode {
    dummy := &ListNode{}
	dummy.Next = head

	cur := dummy
	for cur.Next != nil && cur.Next.Next != nil {
		a := cur.Next
		b := cur.Next.Next
		
		a.Next = b.Next
		cur.Next = b
		b.Next = a
		
		cur = cur.Next.Next
	}

	return dummy.Next
}
// @lc code=end

