/*
 * @lc app=leetcode id=208 lang=golang
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
// S: O(n * 26), n := maximum word len
type Trie struct {
	children [26]*Trie
	isWord bool
}


func Constructor() Trie {
	return Trie{}
}


// T: O(len(word))
func (this *Trie) Insert(word string)  {
	node := this
	for _, c := range word {
		ci := c - 'a'
		if node.children[ci] == nil {
			node.children[ci] = &Trie{}
		}
		node = node.children[ci]
	}
	node.isWord = true
}


// T: O(len(word))
func (this *Trie) Search(word string) bool {
    node := this
	for _, c := range word {
		ci := c - 'a'
		if node.children[ci] == nil {
			return false
		}
		node = node.children[ci]
	}
	return node.isWord
}


// T: O(len(prefix))
func (this *Trie) StartsWith(prefix string) bool {
    node := this
	for _, c := range prefix {
		ci := c - 'a'
		if node.children[ci] == nil {
			return false
		}
		node = node.children[ci]
	}
	return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end

