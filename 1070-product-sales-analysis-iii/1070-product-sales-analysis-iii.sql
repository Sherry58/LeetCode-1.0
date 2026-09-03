-- Write your PostgreSQL query statement below
SELECT product_id, year AS first_year, quantity, price
FROM (
    SELECT *, DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year) AS rnk FROM Sales) t
WHERE rnk = 1
