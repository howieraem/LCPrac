--
-- @lc app=leetcode id=1633 lang=mysql
--
-- [1633] Percentage of Users Attended a Contest
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    contest_id,
    ROUND(
        COUNT(1) / (SELECT CAST(COUNT(1) AS DECIMAL) FROM Users) * 100, 
        2) AS `percentage`
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1

-- @lc code=end

