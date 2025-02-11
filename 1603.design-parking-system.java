/*
 * @lc app=leetcode id=1603 lang=java
 *
 * [1603] Design Parking System
 */

// @lc code=start
// Array
// S: O(k), k := 3
class ParkingSystem {
    private int[] caps;

    // T: O(k)
    public ParkingSystem(int big, int medium, int small) {
        caps = new int[]{big, medium, small};
    }
    
    // T: O(1)
    public boolean addCar(int carType) {
        // if (carType < 1 || carType >= caps.length || caps[carType - 1] == 0) return false;
        return caps[carType - 1]-- > 0;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
// @lc code=end

