SELECT title FROM movies
JOIN stars AS sa ON movies.id = sa.movie_id AND sa.person_id = (SELECT id FROM people WHERE name = 'Jennifer Lawrence')
JOIN stars AS sb ON movies.id = sb.movie_id AND sb.person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper');