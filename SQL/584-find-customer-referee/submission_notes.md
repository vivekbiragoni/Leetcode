When you use the `!=` operator in SQL, it won't return rows where the `referee_id` is `NULL` because `NULL` is not considered a value that can be compared using standard comparison operators like `=` or `!=`. In SQL, `NULL` represents an unknown value, and any comparison with `NULL` yields `NULL` (which is treated as false in the context of a `WHERE` clause).

To include rows where `referee_id` is `NULL` or any value other than 2, you should explicitly check for `NULL` using the `IS NULL` condition. Here is how you can adjust your query:

```sql
SELECT name 
FROM Customer 
WHERE referee_id != 2 OR referee_id IS NULL;
```

This query will return rows where `referee_id` is not equal to 2 as well as rows where `referee_id` is `NULL`.
