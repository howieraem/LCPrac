class Solution {
    // Binary search + Math
    // T: O(n * log(min(ranks) * car ^ 2))
    // S: O(1)
    public long repairCars(int[] ranks, int cars) {
        int minRank = Integer.MAX_VALUE;
        for (int rk : ranks) {
            minRank = Math.min(minRank, rk);
        }

        long l = 1;
        long r = (long)minRank * cars * cars;

        while (l < r) {
            long m = l + ((r - l) >> 1);
            if (canRepair(m, ranks, cars)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    private boolean canRepair(long t, final int[] ranks, final int cars) {
        long carsRepaired = 0;
        for (int rk : ranks) {
            carsRepaired += Math.sqrt(t / rk);
            if (carsRepaired >= cars) {
                return true;
            }
        }
        return false;
    }
}