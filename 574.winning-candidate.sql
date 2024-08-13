--
-- @lc app=leetcode id=574 lang=mysql
--
-- [574] Winning Candidate
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT b.name
FROM (
    SELECT
        candidateId
    FROM Vote
    GROUP BY candidateId
    ORDER BY COUNT(id) DESC
    LIMIT 1
) a
INNER JOIN Candidate b
ON a.candidateId = b.id;

-- @lc code=end

