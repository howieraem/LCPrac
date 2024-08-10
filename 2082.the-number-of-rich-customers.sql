--
-- @lc app=leetcode id=2082 lang=mysql
--
-- [2082] The Number of Rich Customers
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    COUNT(DISTINCT customer_id) AS rich_count
FROM Store
WHERE amount > 500; 

-- @lc code=end

