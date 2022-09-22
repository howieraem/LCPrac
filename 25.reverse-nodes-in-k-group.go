/*
 * @lc app=leetcode id=25 lang=golang
 *
 * [25] Reverse Nodes in k-Group
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
func reverseList(head *ListNode) *ListNode {
	var pre *ListNode = nil
	cur := head
	for cur != nil {
		originalNext := cur.Next
		cur.Next = pre

		pre = cur
		cur = originalNext
	}
	return pre
}


// T: O(n)
// S: O(1)
func reverseKGroup(head *ListNode, k int) *ListNode {
	// Need a dummy head node as the original head will not be the same if k > 1
    dummy := &ListNode{}
	dummy.Next = head

	prevNodeOfGroupBegin := dummy
	groupEnd := dummy
	for groupEnd != nil {
		for i := 0; i < k; i++ {
			groupEnd = groupEnd.Next
			if groupEnd == nil {
				// keep the order of the remaining nodes if they can't form a group of k
				return dummy.Next
			}
		}
		
		// Separate the group from the original list
		groupBegin := prevNodeOfGroupBegin.Next
		nextNodeOfGroupEnd := groupEnd.Next
		groupEnd.Next = nil  // IMPORTANT: without this line, reverseList() won't work properly
		
		// Reverse the group and connect it back to the original list
		prevNodeOfGroupBegin.Next = reverseList(groupBegin)
		groupBegin.Next = nextNodeOfGroupEnd

		// Prepare for the next group
		prevNodeOfGroupBegin = groupBegin
		groupEnd = groupBegin
	}
	
	return dummy.Next
}
// @lc code=end

