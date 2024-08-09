--
-- @lc app=leetcode id=1565 lang=mysql
--
-- [1565] Unique Orders and Customers Per Month
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    DATE_FORMAT(order_date, "%Y-%m") AS `month`,
    COUNT(order_id) AS order_count,
    COUNT(DISTINCT customer_id) AS customer_count
FROM Orders
WHERE invoice > 20
GROUP BY 1;

-- @lc code=end

