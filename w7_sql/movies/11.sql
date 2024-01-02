SELECT title FROM stars JOIN people JOIN movies JOIN ratings
ON movies.id = stars.movie_id AND ratings.movie_id = movies.id AND stars.person_id = people.id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC LIMIT 5;