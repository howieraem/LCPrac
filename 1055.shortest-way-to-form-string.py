#
# @lc app=leetcode id=1055 lang=python3
#
# [1055] Shortest Way to Form String
#

# @lc code=start
class Solution:
    # T: O(M * S + N), S := alphabet size
    # S: O(M * S)
    def shortestWay(self, source: str, target: str) -> int:
        M = len(source)

        # Build inverted index for chars in source.
        # -1 means char doesn't exist (or exhausted).
        d = [[0] * 26] * M
        d[M - 1] = [-1] * 26
        d[M - 1][self.get_ch_idx(source[-1])] = M - 1
        for i in range(M - 2, -1, -1):
            d[i] = d[i + 1][:]
            d[i][self.get_ch_idx(source[i])] = i

        ans = 0
        i = 0
        for c in target:
            c_idx = self.get_ch_idx(c)

            # If there is no existence of c with i >= 0,
            # then it doesn't exist at all in source.
            # Impossible to form target.
            if d[0][c_idx] == -1:
                return -1
            
            # If there is no c left in source with index >= i, even 
            # though there are c's from earlier in the subsequence,
            # need to use a new subsequence and reset i.
            if d[i][c_idx] == -1:
                ans += 1
                i = 0

            # Continue taking chars from the subsequence
            i = d[i][c_idx] + 1

            if i == M:
                ans += 1
                i = 0

        # Need to add 1 if it's in the middle of matching another subsequence
        return ans + (i != 0)

    @staticmethod
    def get_ch_idx(c):
        return ord(c) - ord('a')


# @lc code=end

