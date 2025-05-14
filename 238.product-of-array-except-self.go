package lc

// Prefix sum (variant)
// T: O(n)
// S: O(n)
func productExceptSelf(nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = 1
	}
	product_l := 1
	product_r := 1

	for l := 0; l < n; l++ {
		res[l] *= product_l
		product_l *= nums[l]

		r := n - 1 - l
		res[r] *= product_r
		product_r *= nums[r]
	}

	return res
}
