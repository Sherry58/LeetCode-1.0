-- Write your PostgreSQL query statement below
WITH temp AS(
    SELECT *,DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
)

SELECT d.name AS Department,
    t.name AS Employee,
    t.salary AS Salary
FROM 
Department d LEFT JOIN temp t
ON d.id = t.departmentId
WHERE t.rnk <= 3

