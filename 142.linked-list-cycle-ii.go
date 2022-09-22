/*
 * @lc app=leetcode id=142 lang=golang
 *
 * [142] Linked List Cycle II
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
func detectCycle(head *ListNode) *ListNode {
    // Check if cycle exists.
	// If fast and slow pointers meet somewhere, there must be a cycle.
	fast := head
	slow := head
	noCycle := true
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			noCycle = false
			break
		}
	}
	if noCycle {
		return nil
	}

	// Check cycle entrance.
	// Set a pointer to head and another pointer to the point found above, and 
	// make them shift at the same speed. The point they meet is the answer.
	p1 := head
	p2 := slow
	for p1 != p2 {
		p1 = p1.Next
		p2 = p2.Next
	}
	return p1
}
// @lc code=end

