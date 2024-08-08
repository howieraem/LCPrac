--
-- @lc app=leetcode id=596 lang=mysql
--
-- [596] Classes More Than 5 Students
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5;

-- @lc code=end

