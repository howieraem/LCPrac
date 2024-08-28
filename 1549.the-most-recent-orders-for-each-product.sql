--
-- @lc app=leetcode id=1549 lang=mysql
--
-- [1549] The Most Recent Orders for Each Product
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        product_id, 
        order_id, 
        order_date,
        RANK() OVER (PARTITION BY product_id ORDER BY order_date DESC) AS rk
    FROM Orders
)
SELECT 
    p.product_name,
    a.product_id,
    a.order_id,
    a.order_date
FROM Products p
INNER JOIN a 
    ON p.product_id = a.product_id
WHERE a.rk = 1
ORDER BY p.product_name, a.product_id, a.order_id;

-- @lc code=end

