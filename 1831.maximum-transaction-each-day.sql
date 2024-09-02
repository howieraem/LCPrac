--
-- @lc app=leetcode id=1831 lang=mysql
--
-- [1831] Maximum Transaction Each Day
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        transaction_id,
        RANK() OVER (PARTITION BY DAY(`day`) ORDER BY amount DESC) as rk
    FROM Transactions
)
SELECT transaction_id
FROM a
WHERE rk = 1
ORDER BY transaction_id;

-- @lc code=end

