--
-- @lc app=leetcode id=586 lang=mysql
--
-- [586] Customer Placing the Largest Number of Orders
--

-- @lc code=start
-- Write your MySQL query statement below

-- Solution for only 1 customer having max count
-- SELECT customer_number
-- FROM Orders
-- GROUP BY customer_number
-- ORDER BY COUNT(*) DESC
-- LIMIT 1;

-- Solution for multiple customers having the same max count
WITH a AS (
    SELECT 
        customer_number,
        DENSE_RANK() OVER (ORDER BY COUNT(order_number) DESC) AS rk
    FROM Orders
    GROUP BY customer_number
)
SELECT customer_number
FROM a
WHERE rk = 1;

-- @lc code=end

