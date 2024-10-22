/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
#include <bits/stdc++.h>

using namespace std;

/*
// @lc code=start
// Quick sort: may get TLE in leetcode's testcases, but works well in reality if numbers are random and distinct
// T Worst: O(n^2)
// T Average: O(n*log(n))
// S: O(1)
class Solution {
    std::mt19937 gen;

    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r)  return;
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }

    int partition(vector<int> &nums, int l, int r) {
        std::uniform_int_distribution<> distrib(l, r);
        int pivot_idx = distrib(gen);
        swap(nums[pivot_idx], nums[r]);
        
        int pivot = nums[r];
        int i = l - 1;
        for (int j = i + 1; j < r; ++j) {
            if (nums[j] < pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[r]);
        return i;
    }

public:
    Solution() : gen((std::random_device())()) {};

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
*/

/*
// Heap sort: simulate heap push and heap pop
// T: O(n*log(n))
// S: O(1)
class Solution {
    void max_heapify(vector<int> &nums, int l, int r) {
        int root = l, child = (root << 1) + 1;
        while (child <= r) {
            if (child + 1 <= r && nums[child] < nums[child + 1]) {
                ++child;
            }
        
            if (nums[root] > nums[child]) {
                return;
            } else {
                swap(nums[root], nums[child]);
                root = child;
                child = (root << 1) + 1;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        for (int i = (n >> 1) - 1; i >= 0; --i) {
            max_heapify(nums, i, n - 1);
        }

        for (int i = n - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            max_heapify(nums, 0, i - 1);
        }
        return nums;
    }
};
*/

/*
// Merge sort (out of place): parallelizable
// T: O(n*log(n))
// S: O(n)
class Solution {
    void mergeSort(vector<int> &nums, int l, int r) {
        if (l == r) {
            return;
        }
        int m = l + ((r - l) >> 1);
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        // Merge
        vector<int> tmp(r - l + 1);
        int i = l; 
        int j = m + 1; 
        int k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else { 
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int p = 0; p < k; ++p) {
            nums[l + p] = tmp[p];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
*/
// @lc code=end

