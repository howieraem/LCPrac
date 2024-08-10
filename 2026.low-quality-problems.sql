--
-- @lc app=leetcode id=2026 lang=mysql
--
-- [2026] Low-Quality Problems
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT problem_id
FROM Problems
WHERE CAST(likes AS DECIMAL) / (likes + dislikes) < 0.6
ORDER BY problem_id;

-- @lc code=end

