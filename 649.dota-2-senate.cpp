/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */
#include <bits/stdc++.h>

using std::queue;
using std::string;

// @lc code=start
class Solution {
public:
    // Queue + two pointers + greedy
    // T: O(n)
    // S: O(n)
    string predictPartyVictory(string senate) {
        queue<int> rad; 
        queue<int> dir;
        int n = senate.length();

        // Add all senators to respect queue with index
        for (int i = 0; i < n; i++){
            if (senate[i] == 'R') {
                rad.push(i);
            } else {
                dir.push(i);
            }
        }

        // Use increasing n to keep track of position
        while (!rad.empty() && !dir.empty()){
            // Only "winner" stays in their queue
            if (rad.front() < dir.front()){
                // Because of the order, the smaller/earlier index will always win.
                // The winner is push to queue again with a larger index to simulate
                // the next round.
                rad.push(n++);
            } else {
                dir.push(n++);
            }
            rad.pop(); 
            dir.pop();
        }

        return rad.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end

