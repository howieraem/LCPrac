/*
 * @lc app=leetcode id=4 lang=golang
 *
 * [4] Median of Two Sorted Arrays
 */
import "math"

// @lc code=start
// T: O(log(min(n1, n2)))
// S: O(1) ignoring variable swapping
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) > len(nums2) {
		// Always search on the shorter array to reduce time complexity
		nums1, nums2 = nums2, nums1
	}
	n1 := len(nums1)
	n2 := len(nums2)

	/*
		If we split the sorted array to two halves of equal lengths, then
		median is the average of max(lower half) and min(upper half), i.e. the
		two numbers immediately next to the split point. If the array size is
		odd, max(lower half) and min(upper half) should be the same element.

		The task is to find the indexes m1 and m2 from nums1 and nums2 respectively to
	    calculate the median of the merged array. Note that m1 and m2 are indices
		closest to the median of the merged array, not the indices of the medians
		of nums1 and nums2.
	    If (n1 + n2) is odd:
	        median = max(nums1[m1 - 1], nums2[m2 - 1])
	    Else:
	        median = (max(nums1[m1 - 1], nums2[m2 - 1]) + min(nums1[m1], nums2[m2])) / 2.

	    Based on the fact that the number of elements on the left of the median must equal
	    the number of elements on the right of the median, we can derive the relationship
	    between m1, m2 and array lengths:
	        m1 + m2 = n1 + n2 - m1 - m2 + ((n1 + n2) % 2)
	        m1 + m2 = (n1 + n2 + 1) // 2 which is a constant

		Binary search the leftmost m1 in nums1 which is sorted such that nums1[m1] == nums2[m2 - 1].
		m2 is immediately determined by m1.
	*/
	k := (n1 + n2 + 1) >> 1
	l := 0
	r := n1
	for l < r {
		m1 := (l + r) >> 1
		m2 := k - m1
		if nums1[m1] >= nums2[m2-1] {
			r = m1
		} else {
			l = m1 + 1
		}
	}

	m1 := l
	m2 := k - l

	// Be aware of edge cases
	var maxLowerHalf int
	if m1 > 0 && m2 > 0 {
		if nums1[m1-1] > nums2[m2-1] {
			maxLowerHalf = nums1[m1-1]
		} else {
			maxLowerHalf = nums2[m2-1]
		}
	} else if m1 > 0 {
		maxLowerHalf = nums1[m1-1]
	} else if m2 > 0 {
		maxLowerHalf = nums2[m2-1]
	}

	if ((n1 + n2) & 1) == 1 {
		return float64(maxLowerHalf)
	}

	var minUpperHalf int
	if m1 < n1 && m2 < n2 {
		if nums1[m1] < nums2[m2] {
			minUpperHalf = nums1[m1]
		} else {
			minUpperHalf = nums2[m2]
		}
	} else if m1 < n1 {
		minUpperHalf = nums1[m1]
	} else if m2 < n2 {
		minUpperHalf = nums2[m2]
	}
	return float64(maxLowerHalf+minUpperHalf) / 2
}

// @lc code=end

