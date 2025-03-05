# Write your MySQL query statement below
-- SELECT id FROM Views 
select distinct author_id as id from Views
WHERE author_id = viewer_id 
ORDER BY id ASC;