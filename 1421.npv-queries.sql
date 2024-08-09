--
-- @lc app=leetcode id=1421 lang=mysql
--
-- [1421] NPV Queries
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    q.id,
    q.year,
    IFNULL(n.npv, 0) AS npv
FROM Queries q
LEFT JOIN NPV n
ON q.year = n.year AND q.id = n.id
ORDER BY q.id;

-- @lc code=end

