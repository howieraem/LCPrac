--
-- @lc app=leetcode id=1988 lang=mysql
--
-- [1988] Find Cutoff Score for Each School
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    school_id,
    COALESCE(MIN(score), -1) AS score
FROM Schools
LEFT JOIN Exam 
    ON capacity >= student_count
GROUP BY school_id; 

-- @lc code=end

