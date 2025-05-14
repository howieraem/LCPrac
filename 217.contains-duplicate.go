package lc

// Hash Map
// T: O(n)
// S: O(n)
func containsDuplicate(nums []int) bool {
	mp := make(map[int]bool)
	for _, x := range nums {
		if _, exists := mp[x]; exists {
			return true
		}
		mp[x] = true
	}
	return false
}
