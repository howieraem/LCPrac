--
-- @lc app=leetcode id=1555 lang=mysql
--
-- [1555] Bank Account Summary
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT paid_by AS `user_id`, -amount AS credit FROM Transactions
    UNION ALL
    SELECT paid_to AS `user_id`, amount AS credit FROM Transactions
    UNION ALL
    SELECT `user_id`, credit FROM Users
)
SELECT 
    a.user_id,
    b.user_name,
    SUM(a.credit) AS credit,
    CASE WHEN SUM(a.credit) < 0 THEN 'Yes' ELSE 'No' END AS credit_limit_breached
FROM a
INNER JOIN Users b
ON a.user_id = b.user_id
GROUP BY a.user_id, b.user_name;

-- @lc code=end

