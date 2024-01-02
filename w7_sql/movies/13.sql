-- -- 1. 102 KB 的所有電影
-- SELECT * FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- AND stars.person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon');

-- -- 2. 抓出所有人的 id 了
-- SELECT * FROM movies
-- JOIN stars AS sa ON movies.id = sa.movie_id AND sa.person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon')
-- JOIN stars AS sb ON movies.id = sb.movie_id AND sb.person_id IN (SELECT id FROM people);

-- -- 3. 卡住
-- SELECT * FROM movies
-- JOIN stars AS sa ON movies.id = sa.movie_id AND sa.person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon')
-- JOIN stars AS sb ON movies.id = sb.movie_id AND sb.person_id IN (SELECT id FROM people)
-- JOIN people;

-- list the names of all people who starred in a movie
-- in which Kevin Bacon also starred.
---- Your query should output a table with a single column for the name of each person.
---- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
---- Kevin Bacon himself should not be included in the resulting list.


-- 11/14我提交的寫法 (w/ChatGPT)
-- SELECT DISTINCT people.name FROM people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- WHERE movies.id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon'))
-- AND NOT people.name = 'Kevin Bacon';


-- 最後如果有重複的似乎可以用 group by name ? ＝> DISTINCT

-- 11/16同學用 WITH 的寫法
-- WITH kv AS (
--     SELECT
--         m.id
--     FROM
--         movies AS m
--     JOIN
--         stars AS s ON s.movie_id = m.id
--     JOIN
--         people AS p ON p.id = s.person_id
--     WHERE
--         p.name = "Kevin Bacon"
--         AND p.birth = 1958
-- )
-- SELECT
--     DISTINCT p.name
-- FROM
--     movies AS m
-- JOIN
--     stars AS s ON m.id = s.movie_id
-- JOIN
--     people AS p ON s.person_id = p.id
-- WHERE
--     m.id IN (SELECT * FROM kv)
--     AND p.name != "Kevin Bacon";


-- 11/17 我重寫的寫法
WITH kb_films AS (
    SELECT movies.id FROM movies
    JOIN stars ON movies.id IS stars.movie_id
    JOIN people ON stars.person_id IS people.id
    WHERE people.name = "Kevin Bacon"
    AND people.birth = "1958"
)
SELECT DISTINCT people.name FROM people
JOIN stars ON people.id IS stars.person_id
JOIN movies on stars.movie_id IS movies.id
WHERE movies.id IN (SELECT id FROM kb_films)
AND people.name != "Kevin Bacon";


