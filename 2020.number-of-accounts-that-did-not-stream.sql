--
-- @lc app=leetcode id=2020 lang=mysql
--
-- [2020] Number of Accounts That Did Not Stream
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT COUNT(t.account_id) AS accounts_count
FROM Subscriptions s
LEFT JOIN Streams t
ON s.account_id = t.account_id
    AND YEAR(t.stream_date) <> 2021
    AND YEAR(s.end_date) = 2021
WHERE t.account_id IS NOT NULL;

-- @lc code=end

