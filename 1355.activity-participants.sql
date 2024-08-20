--
-- @lc app=leetcode id=1355 lang=mysql
--
-- [1355] Activity Participants
--

-- @lc code=start
-- Write your MySQL query statement below
WITH t AS (
    SELECT
        a.name, 
        IFNULL(COUNT(f.name), 0) AS num
    FROM Activities a
    LEFT JOIN Friends f
    ON a.name = f.activity
    GROUP BY a.name
)
SELECT `name` AS activity
FROM t
WHERE num > (SELECT MIN(num) FROM t) 
    AND num < (SELECT MAX(num) FROM t);

-- @lc code=end

