--
-- @lc app=leetcode id=1587 lang=mysql
--
-- [1587] Bank Account Summary II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    u.name AS `name`,
    SUM(t.amount) AS balance
FROM Transactions t
INNER JOIN Users u
ON t.account = u.account
GROUP BY u.name
HAVING SUM(t.amount) > 10000;

-- @lc code=end

