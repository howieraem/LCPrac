--
-- @lc app=leetcode id=1571 lang=mysql
--
-- [1571] Warehouse Manager
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    w.name AS warehouse_name,
    SUM(p.Width * p.Length * p.Height * w.units) AS volume
FROM Warehouse w
LEFT JOIN Products p
ON w.product_id = p.product_id
GROUP BY w.name;

-- @lc code=end

