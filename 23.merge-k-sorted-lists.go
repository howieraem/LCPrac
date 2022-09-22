/*
 * @lc app=leetcode id=23 lang=golang
 *
 * [23] Merge k Sorted Lists
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
// T: O(len(list1) + len(list2))
func conquer(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	
	dummy := &ListNode{}
	cur := dummy
	for list1 != nil && list2 != nil {
		if list1.Val < list2.Val {
			cur.Next = list1
			list1 = list1.Next
		} else {
			cur.Next = list2
			list2 = list2.Next
		}
		cur = cur.Next
	}

	if list1 != nil {
		cur.Next = list1
	} else {
		cur.Next = list2
	}

	return dummy.Next
}


func divideAndConquer(lists []*ListNode, l int, r int) *ListNode {
	if l > r {
		return nil
	} else if l == r {
		return lists[l]
	} else {
		m := l + ((r - l) >> 1)
		list1 := divideAndConquer(lists, l, m)
		list2 := divideAndConquer(lists, m + 1, r)
		return conquer(list1, list2)
	}
}


// T: O(m * log(n)), m := max length of one list, n := the number of lists
// S: O(log(n)) recursion stack
func mergeKLists(lists []*ListNode) *ListNode {
    return divideAndConquer(lists, 0, len(lists) - 1)
}
// @lc code=end

