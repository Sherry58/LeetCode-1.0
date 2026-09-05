-- Write your PostgreSQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM(
    SELECT *,DENSE_RANK() OVER(ORDER BY salary DESC) AS drnk
    FROM Employee
)
WHERE drnk = 2