class Solution {
    // Binary search
    // T: O(n * log(max(candies)))
    // S: O(1)
    public int maximumCandies(int[] candies, long k) {
        int l = 1;
        int r = 1;
        for (int x : candies) {
            r = Math.max(r, x);
        }

        int ans = 0;
        while (l <= r) {
            int m = l + ((r - l) >> 1);

            // check if possible to allocate candies to k children
            long childAllocated = 0;
            for (int x : candies) {
                childAllocated += x / m;
            }

            if (childAllocated >= k) {
                // can allocate more children with the current number of candies
                ans = m;
                // try to increase the number of candies to reduce "waste"
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
}