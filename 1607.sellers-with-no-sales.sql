--
-- @lc app=leetcode id=1607 lang=mysql
--
-- [1607] Sellers With No Sales
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    s.seller_name
FROM Seller s
LEFT JOIN Orders o
ON s.seller_id = o.seller_id 
    AND sale_date BETWEEN '2020-01-01' AND '2020-12-31'
WHERE o.seller_id IS NULL
ORDER BY 1;

-- @lc code=end

