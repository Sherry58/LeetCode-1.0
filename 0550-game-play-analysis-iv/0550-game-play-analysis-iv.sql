-- Write your PostgreSQL query statement below
SELECT ROUND(
    COUNT(a.player_id)/COUNT(t.player_id) :: NUMERIC , 2
) AS fraction

FROM

(SELECT player_id, event_date,
    ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) AS rn
    FROM Activity) t
LEFT JOIN
Activity a ON
t.player_id = a.player_id AND a.event_date = t.event_date + INTERVAL '1 day' 
WHERE t.rn = 1



