/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // Stack simulation
    // T: O(n)
    // S: O(n) (may be considered O(1) because the result container and the stack are the same)
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> res;  // also simulates the stack
        res.reserve(asteroids.size());
        for (const int& a : asteroids) {
            if (a > 0) {
                res.push_back(a);
            } else {    // a < 0
                // Colliding (except for equal size case)
                while (!res.empty() && res.back() > 0 && res.back() < -a) {
                    res.pop_back();
                }
                if (res.empty() || res.back() < 0) {
                    // all asteroids traveling left
                    res.push_back(a);
                } else if (res.back() == -a) {
                    // If abs values equal, can only pop one, so this case 
                    // is separate from the while loop above
                    res.pop_back();
                }
            }           
        }
        return res;
    }
};
// @lc code=end

