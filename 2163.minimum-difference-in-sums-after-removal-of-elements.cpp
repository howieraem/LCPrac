#include <bits/stdc++.h>

using std::priority_queue;
using std::vector;

class Solution {
public:
    // Heap + Greedy + prefix sum?
    // T: O(n * log(n))
    // S: O(n)
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;

        // stores the smallest n numbers in the first part
        priority_queue<int> min_heap;

        // stores the largest n numbers in the second part
        priority_queue<int, vector<int>, std::greater<>> max_heap;

        // max_sum[i] is the max. sum of n numbers in nums[i:]
        vector<long long> max_r_sums(nums.size());

        // left and right parts overlap for nums[n:2n] 

        // process nums[n:]
        long long r_sum = 0LL;
        for (int i = nums.size() - 1; i >= n; --i) {
            max_heap.push(nums[i]);
            r_sum += nums[i];
            if (max_heap.size() > n) {
                r_sum -= max_heap.top();
                max_heap.pop();
            } 
            
            if (max_heap.size() == n) {
                max_r_sums[i] = r_sum;
            }
        }

        // process nums[:2*n]
        long long ans = LLONG_MAX;
        long long l_sum = 0LL;
        for (int i = 0; i < (n << 1); ++i) {
            min_heap.push(nums[i]);
            l_sum += nums[i];
            if (min_heap.size() > n) {
                l_sum -= min_heap.top();
                min_heap.pop();
            } 
            
            if (min_heap.size() == n) {
                ans = std::min(ans, l_sum - max_r_sums[i + 1]);
            }
        }

        return ans;
    }
};