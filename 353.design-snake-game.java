/*
 * @lc app=leetcode id=353 lang=java
 *
 * [353] Design Snake Game
 */
import java.util.*;

// @lc code=start
class SnakeGame {
    private int w, h, foodIdx, score;
    private int[][] food;
    Deque<Integer> body;
    Set<Integer> bodySet;  // For fast lookup. (r, c) is converted to one integer r * w + c

    public SnakeGame(int width, int height, int[][] food) {
        w = width;
        h = height;
        this.food = food;
        score = 0;
        body = new ArrayDeque<>();
        bodySet = new HashSet<>();

        // Initially at (0, 0)
        body.offer(0);
        bodySet.add(0);
    }
    
    // T: O(1)
    public int move(String direction) {
        if (score == -1) return -1;  // already game over

        int r = body.peekFirst() / w, c = body.peekFirst() % w;
        switch (direction) {
            case "U": --r; break;
            case "D": ++r; break;
            case "L": --c; break;
            case "R": ++c; break;
        }
        // check if out of bound
        if (r < 0 || r >= h || c < 0 || c >= w) return score = -1;

        // try moving forward
        int newHead = r * w + c;
        bodySet.remove(body.peekLast());
        if (bodySet.contains(newHead)) {
            // collision with itself
            return score = -1;
        }
        // now new head is valid
        bodySet.add(newHead);
        body.offerFirst(newHead);

        // check if eating the current food displayed
        if (foodIdx < food.length && r == food[foodIdx][0] && c == food[foodIdx][1]) {
            bodySet.add(body.peekLast());  // food eaten, old tail doesn't change, add it back to bodySet
            ++foodIdx;
            return ++score;
        }

        // no food eaten, remove previous tail from deque as well
        body.pollLast();
        return score;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
// @lc code=end

