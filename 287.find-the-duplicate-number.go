/*
 * @lc app=leetcode id=287 lang=golang
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// T: O(n)
// S: O(1)
func findDuplicate(nums []int) int {
	/*
	Similar idea to Q142 finding the entrance of a cycle in a linked list.
	This works because the numbers are in the range [1...n]. 
	
	If there is no duplicate in the array, we can map each indexes to each numbers 
	in this array. In other words, we can have a mapping function f(index) = number.
	If we start from index = 0, we can get a value according to this mapping 
	function, and then we use this value as a new index and, again, we can 
	get the other new value according to this new index. We repeat this process 
	until the index exceeds the array. By doing so, we can get a sequence which 
	can be regarded as a linked list. If there is duplicate in the array, the 
	mapping function is many-to-one. The sequence we get definitely has a cycle. 

	(Better be illustrated with examples)
	*/
    fast := nums[nums[0]]
	slow := nums[0]
	for fast != slow {
		fast = nums[nums[fast]]
		slow = nums[slow]
	}

	p1 := 0
	p2 := slow
	for p1 != p2 {
		p1 = nums[p1]
		p2 = nums[p2]
	}
	return p1
}
// @lc code=end

