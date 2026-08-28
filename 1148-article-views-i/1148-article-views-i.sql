SELECT a.author_id AS id
FROM Views a
WHERE a.author_id = a.viewer_id 
GROUP BY a.author_id 
ORDER BY id

