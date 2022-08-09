/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(r), r := len(reservedSeats)
    // S: O(r)
    int maxNumberOfFamilies(int n, const vector<vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reserved;
        for (const auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            reserved[row] |= (1 << col);
        }

        // seats 2, 3 and 4, 5
        int mask1 = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

        // seats 6, 7 and 8, 9
        int mask2 = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // seats 4, 5, 6, 7
        int mask3 = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        int allocations_in_rows_with_reservations = 0;
        for (const auto& p : reserved) {
            int reserved_in_row = p.second;

            // Check (2+2)-seat allocations first
            int cnt = ((reserved_in_row & mask1) == 0) + ((reserved_in_row & mask2) == 0);

            // Check 4-seat allocation
            if (cnt == 0 && (reserved_in_row & mask3) == 0) {
                cnt = 1;
            }
            allocations_in_rows_with_reservations += cnt;
        }

        // For rows without any reservation, can have at most 2 4-seat allocations
        int allocations_in_rows_without_reservations = ((n - reserved.size()) << 1);
        return allocations_in_rows_with_reservations + allocations_in_rows_without_reservations;
    }
};
// @lc code=end

