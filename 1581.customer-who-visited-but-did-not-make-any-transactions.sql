--
-- @lc app=leetcode id=1581 lang=mysql
--
-- [1581] Customer Who Visited but Did Not Make Any Transactions
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    v.customer_id,
    COUNT(v.customer_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id AND t.amount IS NOT NULL -- Transactions.amount could be originally NULL in some test cases
WHERE t.amount IS NULL
GROUP BY v.customer_id;

-- @lc code=end

