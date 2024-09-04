--
-- @lc app=leetcode id=1934 lang=mysql
--
-- [1934] Confirmation Rate
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    s.user_id,
    CAST(AVG(
        CASE
            WHEN c.action = 'confirmed' THEN 1.0
            ELSE 0.0
        END
    ) AS DECIMAL(18, 2)) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
    ON s.user_id = c.user_id
GROUP BY s.user_id;

-- @lc code=end

