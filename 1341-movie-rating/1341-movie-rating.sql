-- Write your PostgreSQL query statement below
SELECT name AS results FROM(
    SELECT u.name, COUNT(r.movie_id) AS cnt
    FROM 
    Users u LEFT JOIN MovieRating r
    ON u.user_id = r.user_id
    GROUP BY u.name
    ORDER BY cnt DESC, u.name
    LIMIT 1
)

UNION ALL

SELECT title FROM(
SELECT m.title, AVG(r.rating) AS avg_rating
FROM
Movies m LEFT JOIN MovieRating r
ON m.movie_id = r.movie_id 
WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY m.title
ORDER BY avg_rating DESC,m.title
LIMIT 1)



