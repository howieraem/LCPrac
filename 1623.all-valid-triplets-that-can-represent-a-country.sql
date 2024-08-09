--
-- @lc app=leetcode id=1623 lang=mysql
--
-- [1623] All Valid Triplets That Can Represent a Country
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    s1.student_name AS member_A,
    s2.student_name AS member_B,
    s3.student_name AS member_C
FROM SchoolA s1
CROSS JOIN SchoolB s2 
CROSS JOIN SchoolC s3
WHERE s1.student_id <> s2.student_id
    AND s2.student_id <> s3.student_id
    AND s1.student_id <> s3.student_id
    AND s1.student_name <> s2.student_name
    AND s2.student_name <> s3.student_name
    AND s1.student_name <> s3.student_name;

-- @lc code=end

