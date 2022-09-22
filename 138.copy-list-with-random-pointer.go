/*
 * @lc app=leetcode id=138 lang=golang
 *
 * [138] Copy List with Random Pointer
 */

type Node struct {
	Val int
	Next *Node
	Random *Node
}

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

// T: O(n)
// S: O(1)
func copyRandomList(head *Node) *Node {
	if head == nil {
		return head
	}

	// Clone each node and put it after the original node
	cur := head
	for cur != nil {
		copy := &Node{
			Val: cur.Val,
			Next: cur.Next,
		}
		cur.Next = copy

		cur = copy.Next
	}

	// Copy the random connections.
	// The copied random connections should point to the copied nodes.
	cur = head
	for cur != nil {
		if cur.Random != nil {
			cur.Next.Random = cur.Random.Next
		}
		cur = cur.Next.Next
	}

	// Decouple the copied list
	headCopy := head.Next
	cur = head
	curCopy := headCopy
	for cur != nil {
		cur.Next = cur.Next.Next
		if curCopy.Next != nil {
			curCopy.Next = curCopy.Next.Next
		}

		cur = cur.Next
		curCopy = curCopy.Next
	}
	return headCopy
}
// @lc code=end

