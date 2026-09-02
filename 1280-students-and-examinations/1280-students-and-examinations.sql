
SELECT st.student_id, st.student_name, sb.subject_name, COUNT(ex.student_id) AS attended_exams FROM
(Students st CROSS JOIN Subjects sb) LEFT JOIN Examinations ex
ON st.student_id = ex.student_id AND sb.subject_name = ex.subject_name
GROUP BY st.student_id, st.student_name, sb.subject_name
ORDER BY st.student_id, sb.subject_name