/* Write your T-SQL query statement below */
SELECT 
    student_id,
    department_id,
    CASE
        WHEN COUNT(student_id) OVER (PARTITION BY department_id) - 1 = 0 THEN 0.0
        ELSE ROUND(
            (RANK() OVER (PARTITION BY department_id ORDER BY mark DESC) - 1) * 100.0 / 
            (COUNT(student_id) OVER (PARTITION BY department_id) - 1), 
        2)
    END AS 'percentage'
FROM Students;