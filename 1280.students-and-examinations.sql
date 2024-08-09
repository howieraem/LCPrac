--
-- @lc app=leetcode id=1280 lang=mysql
--
-- [1280] Students and Examinations
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    a.student_id, 
    a.student_name,
    b.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM Students a
CROSS JOIN Subjects b   -- in case Subjects table is empty, no rows should be shown in result
LEFT JOIN Examinations e
ON a.student_id = e.student_id AND b.subject_name = e.subject_name
GROUP BY 1, 2, 3
ORDER BY 1, 3;

-- @lc code=end

