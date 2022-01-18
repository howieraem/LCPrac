/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
typedef pair<int, int> int_pair;

class Solution {
public:
    // T: O(k * log(k))
    // S: O(k)
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m = nums1.size(), n = nums2.size();

        // min heap (because we are finding the kth smallest)
        auto compare = [&nums1, &nums2](const int_pair &a, const int_pair &b) { 
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<int_pair, vector<int_pair>, decltype(compare)> pq(compare);
        pq.emplace(0, 0);

        vector<vector<int>> res;
        while (k-- > 0 && pq.size()) {
            auto p = pq.top(); pq.pop();
            res.push_back({nums1[p.first], nums2[p.second]});

            /**
             * Explanations to the if conditions below:
             * 1. Starting from pair (0, 0) (indices corresponding to the minimum sum)
             * 2. The only two possible followers (immediate larger ones) are (0, 1) and (1, 0). 
             *    Any other indices, say (1, 1) and (1, 2), have to be larger.
             * 3. Every time you get a current minimum (i, j), you want to push (i+1, j) and (i, j+1) into heap. 
             *    You don't need to worry about others yet.
             * 4. The problem here is, if you are at (2, 3), you will push (3, 3) and (2, 4); Then later, 
             *    you are at (3, 2), and you will push (3, 3) and (4, 2). (3, 3) will be pushed twice.
             * 5. It is easy to realize, if you are at (2, 3), and you haven't seen (3, 2) yet, meaning (3, 2) is 
             *    either still in the queue but not popped yet or not even pushed into queue, you don't need to 
             *    worry about (3, 3) at this moment, because (3, 2) is guaranteed to be no greater than (3, 3). 
             *    So you can wait till you see (3, 2).
             * 6. Every time you see (i, j), just push (i + 1, j) into queue. (i, j + 1) will then be pushed into queue later 
             *    when (i - 1, j + 1) is encountered. The only exception to this is, when i == 0, there is no (i - 1, j + 1), 
             *    so you want to push both (i + 1, j) and (i, j + 1) when i == 0. 
             */
            if (p.first + 1 < m) {
                pq.emplace(p.first + 1, p.second);
            }
            if (!p.first && p.second + 1 < n) {
                pq.emplace(p.first, p.second + 1);
            }
        }
        return res;
    }
};
// @lc code=end

