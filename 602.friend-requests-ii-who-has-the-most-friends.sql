--
-- @lc app=leetcode id=602 lang=mysql
--
-- [602] Friend Requests II: Who Has the Most Friends
--

-- @lc code=start
-- Write your MySQL query statement below

WITH a AS (
    SELECT id, COUNT(*) as num FROM (
        SELECT requester_id AS id FROM RequestAccepted
        UNION ALL
        SELECT accepter_id AS id FROM RequestAccepted
    ) t
    GROUP BY id
)
SELECT id, num
FROM a
ORDER BY num DESC
LIMIT 1;


-- @lc code=end

