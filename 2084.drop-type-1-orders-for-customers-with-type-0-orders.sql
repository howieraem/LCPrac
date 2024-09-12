--
-- @lc app=leetcode id=2084 lang=mysql
--
-- [2084] Drop Type 1 Orders for Customers With Type 0 Orders
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    order_id,
    customer_id,
    order_type
FROM (
    SELECT 
        order_id,
        customer_id,
        order_type,
        DENSE_RANK() OVER (PARTITION BY customer_id ORDER BY order_type) rk
    FROM Orders
) a
WHERE rk = 1;

-- @lc code=end

