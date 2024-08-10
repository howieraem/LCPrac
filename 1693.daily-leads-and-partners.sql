--
-- @lc app=leetcode id=1693 lang=mysql
--
-- [1693] Daily Leads and Partners
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    date_id,
    make_name,
    COUNT(DISTINCT lead_id) AS unique_leads,
    COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY 1, 2;

-- @lc code=end

