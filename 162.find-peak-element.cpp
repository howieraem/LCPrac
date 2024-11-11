/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // Binary search
    // T: O(log(n))
    // S: O(1)
    int findPeakElement(std::vector<int>& nums) {
        const int N = nums.size();

        // Handle edge cases
        if (N == 1) {
            return 0;
        }
        // Binary search won't work if the peak appears at the beginning or the end of the array,
        // unless we add dummy -inf to both the beginning and the end
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[N - 1] > nums[N - 2]) {
            return N - 1;
        }

        int l = 1; 
        int r = N - 2;

        // Why binary search works: nums[i] != nums[i - 1], and there are 
        // multiple target indices, so nums don't have to be sorted.
        // As we can return the index of any of the peaks, it is fine to 
        // discard half of the array in every iteration.
        while (l <= r) {
            int m = l + ((r - l) >> 1); 
            
            if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else if (nums[m] < nums[m - 1]) {
                r = m - 1;
            }
        }
        return l;
    }

    // Follow-up: if there are multiple peaks which should be all returned, then we have to use an O(n) algorithm.
    /*
    def find_peaks_strict(nums):
        """
        Finds all peak elements in the array where a peak is strictly greater than its neighbors.

        Args:
        nums (List[int]): The input array.

        Returns:
        List[int]: A list of all peak elements.
        """
        peaks = []
        n = len(nums)
        
        if n == 0:
            return peaks  # Empty array, no peaks

        for i in range(n):
            # Check left neighbor
            if i > 0:
                if nums[i] <= nums[i - 1]:
                    continue
            # Check right neighbor
            if i < n - 1:
                if nums[i] <= nums[i + 1]:
                    continue
            # If both conditions are satisfied, it's a peak
            peaks.append(nums[i])
        
        return peaks

    def find_peaks_non_strict(nums):
        """
        Finds all peak elements in the array where a peak is 
        greater than or equal to its neighbors.

        Args:
        nums (List[int]): The input array.

        Returns:
        List[int]: A list of all peak elements.
        """
        peaks = []
        n = len(nums)
        
        if n == 0:
            return peaks  # Empty array, no peaks

        for i in range(n):
            # Check left neighbor
            if i > 0:
                if nums[i] < nums[i - 1]:
                    continue
            # Check right neighbor
            if i < n - 1:
                if nums[i] < nums[i + 1]:
                    continue
            # If both conditions are satisfied, it's a peak
            peaks.append(nums[i])
        
        return peaks

    def find_peaks_single_plateau(nums):
        """
        Finds all peak elements in the array where plateaus are considered single peaks.

        Args:
        nums (List[int]): The input array.

        Returns:
        List[int]: A list of all peak elements.
        """
        peaks = []
        n = len(nums)
        i = 0
        
        while i < n:
            # Find the end of the plateau
            plateau_end = i
            while plateau_end + 1 < n and nums[plateau_end] == nums[plateau_end + 1]:
                plateau_end += 1
            
            # Check if the plateau is a peak
            left_ok = (i == 0) or (nums[plateau_end] > nums[i - 1])
            right_ok = (plateau_end == n - 1) or (nums[plateau_end] > nums[plateau_end + 1])
            
            if left_ok and right_ok:
                peaks.append(nums[plateau_end])
            
            # Move to the next element after the plateau
            i = plateau_end + 1
        
        return peaks
    */
};
// @lc code=end

