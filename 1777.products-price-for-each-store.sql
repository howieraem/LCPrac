--
-- @lc app=leetcode id=1777 lang=mysql
--
-- [1777] Product's Price for Each Store
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    product_id,
    MAX(CASE WHEN store = 'store1' then price ELSE NULL END) AS store1,
    MAX(CASE WHEN store = 'store2' then price ELSE NULL END) AS store2,
    MAX(CASE WHEN store = 'store3' then price ELSE NULL END) AS store3
FROM Products
GROUP BY product_id;

-- @lc code=end

