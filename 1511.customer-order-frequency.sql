--
-- @lc app=leetcode id=1511 lang=mysql
--
-- [1511] Customer Order Frequency
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT c.customer_id, c.name
FROM Customers c
INNER JOIN Orders o ON c.customer_id = o.customer_id
INNER JOIN Product p ON o.product_id = p.product_id
GROUP BY 1, 2
HAVING SUM(CASE WHEN LEFT(o.order_date, 7) = '2020-06' THEN p.price * o.quantity ELSE 0 END) >= 100
    AND SUM(CASE WHEN LEFT(o.order_date, 7) = '2020-07' THEN p.price * o.quantity ELSE 0 END) >= 100

-- @lc code=end

