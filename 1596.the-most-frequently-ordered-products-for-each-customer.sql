--
-- @lc app=leetcode id=1596 lang=mysql
--
-- [1596] The Most Frequently Ordered Products for Each Customer
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        customer_id,
        product_id,
        DENSE_RANK() OVER (PARTITION BY customer_id ORDER BY COUNT(*) DESC) AS rk
    FROM Orders
    GROUP BY customer_id, product_id
)
SELECT 
    a.customer_id, 
    a.product_id, 
    p.product_name
FROM a
LEFT JOIN Products p
    ON a.product_id = p.product_id
WHERE a.rk = 1;

-- @lc code=end

