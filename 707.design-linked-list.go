/*
 * @lc app=leetcode id=707 lang=golang
 *
 * [707] Design Linked List
 */
package lc

// @lc code=start
// S: O(n)
type Node struct {
	nxt *Node
	pre *Node
	val int
}

type MyLinkedList struct {
	head *Node
	tail *Node
	sz   int
}

// T: O(1)
func Constructor() MyLinkedList {
	head := &Node{val: -1, nxt: nil, pre: nil}
	tail := &Node{val: -1, nxt: nil, pre: nil}
	head.nxt = tail
	tail.pre = head
	return MyLinkedList{
		head: head,
		tail: tail,
		sz:   0,
	}
}

// T: O(n)
func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.sz {
		return -1
	}

	cur := this.head
	for i := 0; i <= index; i++ {
		cur = cur.nxt
	}
	return cur.val
}

// T: O(1)
func (this *MyLinkedList) AddAtHead(val int) {
	node := &Node{
		nxt: this.head.nxt,
		pre: this.head,
		val: val,
	}

	this.head.nxt.pre = node
	this.head.nxt = node

	this.sz++
}

// T: O(1)
func (this *MyLinkedList) AddAtTail(val int) {
	node := &Node{
		nxt: this.tail,
		pre: this.tail.pre,
		val: val,
	}

	this.tail.pre.nxt = node
	this.tail.pre = node

	this.sz++
}

// T: O(n)
// Potential optimization: if index is approaching this.sz, iterate from this.tail instead
func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.sz {
		return
	}

	if index == this.sz {
		this.AddAtTail(val)
		return
	}

	if index <= 0 {
		this.AddAtHead(val)
		return
	}

	cur := this.head
	for i := 0; i <= index; i++ {
		cur = cur.nxt
	}

	node := &Node{
		nxt: cur,
		pre: cur.pre,
		val: val,
	}

	cur.pre.nxt = node
	cur.pre = node

	this.sz++
}

// T: O(n)
func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index >= this.sz {
		return
	}

	cur := this.head.nxt
	for index > 0 {
		cur = cur.nxt
		index--
	}

	cur.pre.nxt = cur.nxt
	cur.nxt.pre = cur.pre

	this.sz--
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
// @lc code=end
