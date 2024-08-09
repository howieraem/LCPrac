--
-- @lc app=leetcode id=1251 lang=mysql
--
-- [1251] Average Selling Price
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    p.product_id,
    ROUND(IFNULL(SUM(p.price * u.units * 1.00) / SUM(u.units * 1.00), 0.0), 2) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;

-- @lc code=end

