--
-- @lc app=leetcode id=1532 lang=mysql
--
-- [1532] The Most Recent Three Orders
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    -- one order per day, so use RANK() rather than DENSE_RANK()
    SELECT 
        RANK() OVER (PARTITION BY o.customer_id ORDER BY o.order_date DESC) AS rk,
        c.name AS customer_name,
        o.customer_id,
        o.order_id,
        o.order_date
    FROM Orders o
    INNER JOIN Customers c
        ON o.customer_id = c.customer_id
)
SELECT 
    customer_name,
    customer_id,
    order_id,
    order_date
FROM a
WHERE rk <= 3
ORDER BY customer_name, customer_id, order_date DESC;

-- @lc code=end

