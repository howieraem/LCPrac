--
-- @lc app=leetcode id=1205 lang=mysql
--
-- [1205] Monthly Transactions II
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        country, `state`, amount, LEFT(c.`trans_date`, 7) AS `month`, 1 AS tag
    FROM Transactions t1
    INNER JOIN Chargebacks c 
    ON t1.id = c.trans_id

    UNION ALL
    
    SELECT 
        country, `state`, amount, LEFT(t2.`trans_date`, 7) AS `month`, 0 AS tag
    FROM Transactions t2 
    WHERE `state` != 'declined'
)
SELECT 
    `month`, 
    country,
    SUM(CASE WHEN `state` = 'approved' AND tag = 0 THEN 1 ELSE 0 END) AS approved_count,
    SUM(CASE WHEN `state` = 'approved' AND tag = 0 THEN amount ELSE 0 END) AS approved_amount,
    SUM(CASE WHEN tag = 1 THEN 1 ELSE 0 END) AS chargeback_count,
    SUM(CASE WHEN tag = 1 THEN amount ELSE 0 END) AS chargeback_amount
FROM a
GROUP BY country, `month`;

-- @lc code=end

