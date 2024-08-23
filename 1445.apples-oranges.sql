--
-- @lc app=leetcode id=1445 lang=mysql
--
-- [1445] Apples & Oranges
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    sale_date, 
    SUM(CASE WHEN fruit = 'apples' THEN 1 ELSE -1 END * sold_num) AS diff
FROM Sales
GROUP BY sale_date
ORDER BY sale_date;

-- @lc code=end

