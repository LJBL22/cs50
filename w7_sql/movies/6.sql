SELECT AVG(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);
-- return a list of id, that's why we should use 'IN' instead of '='