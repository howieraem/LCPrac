--
-- @lc app=leetcode id=584 lang=mysql
--
-- [584] Find Customer Referee
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT `name`
FROM Customer
WHERE id IS NULL OR id != 2;

-- @lc code=end

