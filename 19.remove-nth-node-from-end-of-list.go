/*
 * @lc app=leetcode id=19 lang=golang
 *
 * [19] Remove Nth Node From End of List
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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	// return dummy->next at the end, just in case the original head gets deleted
    dummy := &ListNode{}
	dummy.Next = head

	// Use fast and slow pointers. 
	// First, move the fast pointer n steps ahead.
	// Then, move both pointers forward until the fast pointer reaches the end of the list.
	// slow->next should point to the nth node from the end of the list.
	fast := dummy
	slow := dummy
	for n > 0 {
		fast = fast.Next
		n--
	}

	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}

	// IMPORTANT: we want slow pointer points to the node in front of the node to be deleted
	// Delete the node
	slow.Next = slow.Next.Next

	return dummy.Next
}
// @lc code=end

