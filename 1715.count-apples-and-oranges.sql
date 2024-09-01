--
-- @lc app=leetcode id=1715 lang=mysql
--
-- [1715] Count Apples and Oranges
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    SUM(b.apple_count + COALESCE(c.apple_count, 0)) AS apple_count,
    SUM(b.orange_count + COALESCE(c.orange_count, 0)) AS orange_count
FROM Boxes b
LEFT JOIN Chests c
ON b.chest_id = c.chest_id;

-- @lc code=end

