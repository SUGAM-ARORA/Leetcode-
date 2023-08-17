# Write your MySQL query statement below
(SELECT name results
FROM `Users` U, `MovieRating` MR
WHERE U.user_id = MR.user_id
GROUP BY U.user_id
ORDER BY COUNT(MR.user_id) DESC, name ASC LIMIT 1)
UNION ALL
(SELECT title results
FROM `Movies` M, `MovieRating` MR
WHERE M.movie_id = MR.movie_id AND created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY M.movie_id
ORDER BY AVG(rating) DESC, title ASC LIMIT 1)