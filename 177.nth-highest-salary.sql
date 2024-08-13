--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--

-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      SELECT DISTINCT(salary) from Employee order by salary DESC
      LIMIT 1 OFFSET N
  );
END

/* MS SQL Server Solution
CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    DECLARE @maxSalary int
    SELECT @maxSalary = salary
    FROM (
        SELECT 
            ROW_NUMBER() OVER (ORDER BY salary DESC) AS rn,
            salary
        FROM (
            SELECT DISTINCT salary FROM Employee 
        ) t
    ) tb
    WHERE rn = @N
    RETURN @maxSalary
END
*/
-- @lc code=end

