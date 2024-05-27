# Write your MySQL query statement below
SELECT w1.id
from Weather w1
join Weather w2
on w1.recordDate = date_add(w2.recordDate, interval 1 day )
where w1.temperature > w2.temperature;


-- To find all dates' IDs with higher temperatures compared to their previous dates, you can use a self-join on the `Weather` table, where you join the table with itself based on consecutive dates. Then, you can filter the rows where the temperature on the current date is higher than the temperature on the previous date. Here's how you can write the SQL query for this:

-- ```sql
-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2 ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
-- WHERE w1.temperature > w2.temperature;
-- ```

-- Explanation of the query:

-- 1. `SELECT w1.id`: This selects the IDs from the `Weather` table where the temperature is higher than the temperature on the previous date.

-- 2. `FROM Weather w1`: This specifies the first instance of the `Weather` table, aliased as `w1`.

-- 3. `JOIN Weather w2 ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)`: This joins the `Weather` table with itself based on consecutive dates. `w1` represents the current date, and `w2` represents the previous date (which is obtained by adding one day to `w1.recordDate`).

-- 4. `WHERE w1.temperature > w2.temperature`: This condition filters the rows where the temperature on the current date (`w1.temperature`) is higher than the temperature on the previous date (`w2.temperature`).

-- This query effectively retrieves the IDs of dates where the temperature is higher than the temperature on the previous date.