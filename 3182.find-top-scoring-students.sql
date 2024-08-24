WITH a AS (
    SELECT 
        major, 
        COUNT(DISTINCT course_id) AS major_num_courses
    FROM courses
    GROUP BY major
), b AS (
    SELECT 
        s.student_id,
        COUNT(DISTINCT e.course_id) AS student_num_courses,
        a.major_num_courses
    FROM students s
    INNER JOIN courses c
        ON s.major = c.major
    INNER JOIN enrollments e
        ON c.course_id = e.course_id AND s.student_id = e.student_id
    INNER JOIN a
        ON s.major = a.major
    WHERE e.grade = 'A'
    GROUP BY s.student_id
)
SELECT student_id
FROM b
WHERE student_num_courses = major_num_courses
ORDER BY student_id;
