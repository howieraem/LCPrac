--
-- @lc app=leetcode id=2041 lang=mysql
--
-- [2041] Accepted Candidates From the Interviews
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    candidate_id
FROM Candidates c
LEFT JOIN Rounds r
    ON c.interview_id = r.interview_id
WHERE years_of_exp >= 2
GROUP BY candidate_id
HAVING SUM(r.score) > 15;

-- @lc code=end

