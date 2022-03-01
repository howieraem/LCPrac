/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class SparseVector {
    // Assuming x.data.size() < y.data.size()
    static int dot(SparseVector *x, SparseVector *y) {
        int ans = 0;
        for (const auto &[i, num] : x->data) {
            if (y->data.find(i) != y->data.end()) {
                ans += num * y->data[i];
            }
        }
        return ans;
    }

public:
    unordered_map<int, int> data;

    // T: O(n), n := the number of non-zero elements in nums (i.e. this->data.size())
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                data[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    // T: O(min(m, n)), m := vec.data.size()
    int dotProduct(SparseVector& vec) {
        const int n1 = data.size(), n2 = vec.data.size();
        if (!n1 || !n2)  return 0;
        // Reduces the number of iterations
        return n1 > n2 ? dot(&vec, this) : dot(this, &vec);        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end

