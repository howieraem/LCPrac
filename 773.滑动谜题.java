import java.util.Set;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=773 lang=java
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
    private static final int[][] NEIGHBORS = {
        {1, 3},
        {0, 4, 2},
        {1, 5},
        {0, 4},
        {3, 1, 5},
        {4, 2}
    };
    private static final int M = 2, N = 3;
    private static final String TARGET = "123450";

    public int slidingPuzzle(int[][] board) {
        // trick: flatten the 2D board and pre-define neighbor indices in 1D for each cell.
        // Then, BFS is more applicable.
        String start = "";
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                start += String.valueOf(board[i][j]);
            }
        }
        int ans = 0;
        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        q.add(start);
        visited.add(start);

        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                String cur = q.poll();
                if (cur.equals(TARGET))  return ans;
                int idx = 0;
                while (cur.charAt(idx) != '0')  ++idx;  // find where '0' currently is
                for (int adj : NEIGHBORS[idx]) {
                    String newBoard = swap(cur, adj, idx);
                    if (!visited.contains(newBoard)) {
                        q.add(newBoard);
                        visited.add(newBoard);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }

    private static String swap(String str, int i, int j)  { 
        StringBuilder sb = new StringBuilder(str); 
        sb.setCharAt(i, str.charAt(j)); 
        sb.setCharAt(j, str.charAt(i)); 
        return sb.toString(); 
    } 
}
// @lc code=end

