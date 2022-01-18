class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        l = len(word) - 1
        DIRN = [1, 0, -1, 0, 1]
        m, n = len(board), len(board[0])

        def backtrack(i, j, k):
            # Move the validation here instead of after `if k == l` 
            # because the initial step/char needs to be checked
            if not (0 <= i < m) or not (0 <= j < n) or board[i][j] != word[k]:
                return False
            if k == l:
                return True
            ret = False
            # tmp, board[i][j] = board[i][j], ''
            board[i][j] = ''
            for d in range(4):
                di, dj = DIRN[d:d + 2]
                if backtrack(i + di, j + dj, k + 1):
                    ret = True
                    break
            # board[i][j] = tmp
            board[i][j] = word[k]
            return ret

        for i in range(m):
            for j in range(n):
                if backtrack(i, j, 0):
                    return True
        return False
