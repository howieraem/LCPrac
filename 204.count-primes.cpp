/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include <cmath>
#include <utility>

using std::fill_n;

// @lc code=start
class Solution {
public:
    // T: O(n * log(log(n)))
    // S: O(n)
    int countPrimes(int n) {
        if (n < 2)  return 0;
        bool is_prime[n];
        fill_n(is_prime, n, true);
        // is_prime[0] = is_prime[1] = false;

        int ans = 0;

        /*
        // Approach 1: iterate from 2 to n and increment answer at the same time
        for (int i = 2; i < n; ++i) {   // T: O(n)
            if (is_prime[i]) {
                ++ans;
                
                // Multiples of a prime is not a prime
                // T: O(log(log(n)))
                for (int j = (i << 1); j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        */

        // Approach 2: iterate from 2 to ceil(sqrt(n)), then count
        // The reason why we can stop at ceil(sqrt(n)) is because 
        // a factor of a number can only be int(n ** 0.5) + 1 or less.
        // For example, if x = y * z, then x = z * y. If y < z, z is 
        // visited as soon as y is visited. 
        // This approach seems to be a bit faster despite the extra loop.
        int sqrt_n = ceil(sqrt(n));
        for (int i = 2; i < sqrt_n; ++i) {
            if (is_prime[i]) {
                for (int j = (i << 1); j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; ++i)  ans += is_prime[i];
        return ans;
    }
};
// @lc code=end

