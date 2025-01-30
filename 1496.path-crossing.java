/*
 * @lc app=leetcode id=1496 lang=java
 *
 * [1496] Path Crossing
 */

import java.util.*;

// @lc code=start
class Pair<F, S> {
    public final F first;
    public final S second;

    /**
     * Constructor for a Pair.
     *
     * @param first the first object in the Pair
     * @param second the second object in the pair
     */
    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    /**
     * Checks the two objects for equality by delegating to their respective
     * {@link Object#equals(Object)} methods.
     *
     * @param o the {@link Pair} to which this one is to be checked for equality
     * @return true if the underlying objects of the Pair are both considered
     *         equal
     */
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) {
            return false;
        }
        Pair<?, ?> p = (Pair<?, ?>) o;
        return Objects.equals(p.first, first) && Objects.equals(p.second, second);
    }

    /**
     * Compute a hash code using the hash codes of the underlying objects
     *
     * @return a hashcode of the Pair
     */
    @Override
    public int hashCode() {
        return (first == null ? 0 : first.hashCode()) ^ (second == null ? 0 : second.hashCode());
    }

    /**
     * Convenience method for creating an appropriately typed pair.
     * @param a the first object in the Pair
     * @param b the second object in the pair
     * @return a Pair that is templatized with the types of a and b
     */
    public static <A, B> Pair <A, B> create(A a, B b) {
        return new Pair<A, B>(a, b);
    }
}

class Solution {
    // Hash Set
    // T: O(n)
    // S: O(n)
    public boolean isPathCrossing(String path) {
        Set<Pair<Integer, Integer>> vis = new HashSet<>();
        vis.add(new Pair(0, 0));
        
        int x = 0;
        int y = 0;
        for (Character c : path.toCharArray()) {
            switch (c) {
                case 'N':
                    y += 1;
                    break;
                case 'S':
                    y -= 1;
                    break;
                case 'W':
                    x -= 1;
                    break;
                case 'E':
                    x += 1;
                    break;
                default:
                    break;
            }
            
            Pair<Integer, Integer> p = new Pair(x, y);
            if (vis.contains(p)) {
                return true;
            }
            vis.add(p);
        }

        return false;
    }
}
// @lc code=end

