--
-- @lc app=leetcode id=1112 lang=mysql
--
-- [1112] Highest Grade For Each Student
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        student_id, 
        course_id, 
        grade,
        RANK() OVER (PARTITION BY student_id ORDER BY grade DESC, course_id ASC) AS rk
    FROM Enrollments
)
SELECT student_id, course_id, grade
FROM a
WHERE rk = 1
ORDER BY student_id;

-- @lc code=end

