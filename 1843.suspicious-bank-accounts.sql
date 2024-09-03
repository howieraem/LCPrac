--
-- @lc app=leetcode id=1843 lang=mysql
--
-- [1843] Suspicious Bank Accounts
--

-- @lc code=start
-- Write your MySQL query statement below
WITH t1 AS (
    SELECT
        t.account_id,
        DATE_FORMAT(`day`, '%Y%m') AS `month`
    FROM Transactions t
    LEFT JOIN Accounts a
        ON t.account_id = a.account_id
    WHERE t.type = 'creditor'
    GROUP BY a.account_id, DATE_FORMAT(`day`, '%Y%m')
    HAVING SUM(t.amount) > a.max_income
),
t2 AS (
    SELECT 
        account_id,
        `month` - ROW_NUMBER() OVER (PARTITION BY account_id ORDER BY `month`) AS diff
    FROM t1
)
SELECT DISTINCT account_id
FROM t2
GROUP BY account_id, diff
HAVING COUNT(diff) >= 2;
ORDER BY account_id;

-- @lc code=end

