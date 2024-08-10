--
-- @lc app=leetcode id=1821 lang=mysql
--
-- [1821] Find Customers With Positive Revenue this Year
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT customer_id
FROM Customers
WHERE `year` = 2021
  AND revenue > 0; 

-- @lc code=end

