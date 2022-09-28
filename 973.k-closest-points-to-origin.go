/*
 * @lc app=leetcode id=973 lang=golang
 *
 * [973] K Closest Points to Origin
 */
import "math/rand"

// @lc code=start
func d(p []int) int {
	return p[0] * p[0] + p[1] * p[1]
}


// Returns a number randomly in [min, max]
func randBetween(min, max int) int {
	// rand.Intn(x)'s range is [0, n)
	return rand.Intn(max + 1 - min) + min
}


// Returns the index of the pivot (point of partition)
func partition(points [][]int, begin int, end int) int {
	p := randBetween(begin, end)
	points[begin], points[p] = points[p], points[begin]
	pivot := d(points[begin])

	l := begin + 1  // plus 1 because pivot is now at points[begin]
	r := end

	for l <= r {
		if d(points[l]) <= pivot {
			l++
			continue
		} 
		if d(points[r]) > pivot {
			r--
			continue
		}

		points[l], points[r] = points[r], points[l]
		l++
		r--
	}

	// Now r should be the new index of pivot, so that numbers on the left
    // are less than or equal to pivot and numbers on the right are greater 
    // than pivot. 
	points[begin], points[r] = points[r], points[begin]
	return r
}


// We don't care the order of the k points, so we can use quick select
// T: O(n ^ 2) worst, O(n) best/average
// S: O(1) iterative
func kClosest(points [][]int, k int) [][]int {
    n := len(points)
	if n == k {
		return points
	}

	// Return the left subarray points[:k]
	l := 0
	r := n - 1
	for l < r {
		m := partition(points, l, r)
		if m == k {
			break
		} else if m > k {
			// Too many points in the left subarray
			r = m - 1
		} else {
			// Not enough points in the left subarray
			l = m + 1
		}
	}
	return points[:k]
}
// @lc code=end

