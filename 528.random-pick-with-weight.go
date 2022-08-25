/*
 * @lc app=leetcode id=528 lang=golang
 *
 * [528] Random Pick with Weight
 */
 import "math/rand"

// @lc code=start
type Solution struct {
    preSum []int
}

// T: O(n)
// S: O(n)
func Constructor(w []int) Solution {
	sol := Solution{}
    sol.preSum = make([]int, len(w))
	sol.preSum[0] = w[0]
	for i := 1; i < len(w); i++ {
		sol.preSum[i] = sol.preSum[i - 1] + w[i]
	}
	return sol
}

// T: O(log(sum(w)))
func (this *Solution) PickIndex() int {
    target := rand.Intn(this.preSum[len(this.preSum) - 1])
	l := 0
	r := len(this.preSum) - 1
	for l < r {
		m := l + ((r - l) >> 1)
		if this.preSum[m] > target {
			r = m
		} else {
			// Note: when preSum[m] == target, need to pick the next index
			l = m + 1
		}
	}
	return l
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */
// @lc code=end

