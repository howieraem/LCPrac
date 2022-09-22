/*
 * @lc app=leetcode id=146 lang=golang
 *
 * [146] LRU Cache
 */

// @lc code=start
// doubly linked list and hash map
type Node struct {
	K int
	V int
	Prev *Node
	Next *Node
}


type LRUCache struct {
    head *Node
	tail *Node
	cap int
	keyToNode map[int]*Node
}


func Constructor(capacity int) LRUCache {
	lruCache := LRUCache{
		head: &Node{},
		tail: &Node{},
		cap: capacity,
		keyToNode: make(map[int]*Node),
	}
	lruCache.head.Next = lruCache.tail
	lruCache.tail.Prev = lruCache.head
	return lruCache
}


// T: O(1)
func (this *LRUCache) addFront(node *Node) {
	node.Prev = this.head
	node.Next = this.head.Next
	this.head.Next.Prev = node
	this.head.Next = node
}


// T: O(1)
func (this *LRUCache) remove(node *Node) {
	node.Next.Prev = node.Prev
	node.Prev.Next = node.Next
}


// T: O(1)
func (this *LRUCache) moveToFront(node *Node) {
	this.remove(node)
	this.addFront(node)
}


// T: O(1)
func (this *LRUCache) Get(key int) int {
    node, ok := this.keyToNode[key]
	if !ok {
		return -1
	}
	this.moveToFront(node)
	return node.V
}


// T: O(1)
func (this *LRUCache) Put(key int, value int)  {
    node, ok := this.keyToNode[key]
	if ok {
		node.V = value
		this.moveToFront(node)
	} else {
		if len(this.keyToNode) == this.cap {
			back := this.tail.Prev
			this.remove(back)
			delete(this.keyToNode, back.K)
		}
		node = &Node{}
		node.K = key
		node.V = value
		this.keyToNode[key] = node
		this.addFront(node)
	}
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

