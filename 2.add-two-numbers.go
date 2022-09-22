/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
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
// T: O(max(len(l1), len(l2)))
// S: O(1)
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
	cur := dummy
	carry := 0

	for l1 != nil || l2 != nil {
		sum := carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		
		cur.Next = &ListNode{
			Val: sum % 10,
		}
		carry = sum / 10
		cur = cur.Next
	}

	// Don't forget the final carry
	if carry != 0 {
		cur.Next = &ListNode{
			Val: 1,
		}
	}

	return dummy.Next
}
// @lc code=end

