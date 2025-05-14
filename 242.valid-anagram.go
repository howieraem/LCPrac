package lc

// Hash Map
// T: O(n)
// S: O(alpha_sz)
func isAnagram(s string, t string) bool {
	n := len(s)
	if n != len(t) {
		return false
	}
	cnts := make([]int, 26)

	for i := 0; i < n; i++ {
		cnts[int(s[i]-'a')]++
		cnts[int(t[i]-'a')]--
	}

	for _, cnt := range cnts {
		if cnt != 0 {
			return false
		}
	}
	return true
}
