--
-- @lc app=leetcode id=1173 lang=mysql
--
-- [1173] Immediate Food Delivery I
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    ROUND(100.0 * 
        IFNULL(
            SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1.0 ELSE 0.0 END),
            0.0) / CAST(COUNT(delivery_id) AS FLOAT), 
        2) AS immediate_percentage
FROM Delivery;

-- @lc code=end

