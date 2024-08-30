--
-- @lc app=leetcode id=1699 lang=mysql
--
-- [1699] Number of Calls Between Two Persons
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT
        CASE WHEN from_id > to_id THEN to_id ELSE from_id END AS person1,
        CASE WHEN from_id > to_id THEN from_id ELSE to_id END AS person2,
        duration
    FROM Calls
)
SELECT
    person1,
    person2,
    COUNT(1) AS call_count,
    SUM(duration) AS total_duration
FROM a
GROUP BY person1, person2;

-- @lc code=end

