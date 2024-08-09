--
-- @lc app=leetcode id=1517 lang=mysql
--
-- [1517] Find Users With Valid E-Mails
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT *
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_\\.-]*@leetcode[.]com$';

/*
- ^[A-Za-z] must start with a letter
- [A-Za-z0-9_\\.-]* zero or more characters must be one of the following:
    - letter
    - digit
    - '_'
    - '.'
    - '-'
- @leetcode[.]com$ [.] exact match, $ must end with com
*/ 

-- @lc code=end

