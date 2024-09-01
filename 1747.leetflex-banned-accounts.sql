--
-- @lc app=leetcode id=1747 lang=mysql
--
-- [1747] Leetflex Banned Accounts
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT distinct l1.account_id
FROM LogInfo l1
INNER JOIN LogInfo l2
    ON l1.account_id = l2.account_id
        AND l1.ip_address <> l2.ip_address
        -- check overlap
        AND l1.logout >= l2.login
        AND l1.login < l2.logout;

-- @lc code=end

