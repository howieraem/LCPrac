--
-- @lc app=leetcode id=1454 lang=mysql
--
-- [1454] Active Users
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: with window function */
WITH tmp AS (
    SELECT 
        id, login_date,
        LEAD(login_date, 4) OVER (PARTITION BY id ORDER BY login_date) AS next_date
    FROM (
        SELECT id, login_date
        FROM Logins
        GROUP BY id, login_date
    ) t
)
SELECT distinct tmp.id, `name`
FROM tmp
INNER JOIN Accounts a
ON a.id = tmp.id
WHERE DATEDIFF(next_date, login_date) = 4
ORDER BY tmp.id;

/* Solution 2: without window function 
SELECT DISTINCT l1.id, a.name
FROM Logins l1
INNER JOIN Logins l2
ON l1.id = l2.id AND DATEDIFF(l2.login_date, l1.login_date) BETWEEN 0 AND 4
LEFT JOIN Accounts a
ON l1.id = a.id
GROUP BY l1.id, l1.login_date
HAVING COUNT(DISTINCT l2.login_date) >= 5
ORDER BY l1.id;
*/
-- @lc code=end

