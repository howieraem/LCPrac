--
-- @lc app=leetcode id=1811 lang=mysql
--
-- [1811] Find Interview Candidates
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT contest_id, gold_medal AS u_id FROM Contests
    UNION ALL
    SELECT contest_id, silver_medal AS u_id FROM Contests
    UNION ALL
    SELECT contest_id, bronze_medal AS u_id FROM Contests
),
b AS (
    SELECT 
        u_id, 
        contest_id,
        LEAD(contest_id, 1) OVER (PARTITION BY u_id ORDER BY contest_id) AS contest2_id,
        LEAD(contest_id, 2) OVER (PARTITION BY u_id ORDER BY contest_id) AS contest3_id
    FROM a
),
c AS (
    SELECT u_id
    FROM b
    WHERE contest_id + 1 = contest2_id AND contest_id + 2 = contest3_id
    
    UNION

    SELECT gold_medal AS u_id
    FROM Contests
    GROUP BY gold_medal
    HAVING COUNT(gold_medal) >= 3
)
SELECT `name`, mail 
FROM Users u
INNER JOIN c
    ON u.user_id = c.u_id;

-- @lc code=end

