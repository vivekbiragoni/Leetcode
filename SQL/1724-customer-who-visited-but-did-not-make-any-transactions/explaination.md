This MySQL query is aimed at retrieving the number of visits made by each customer where no transactions occurred. Here's a breakdown of the query:

```sql
SELECT
    customer_id,
    COUNT(visit_id) AS count_no_trans
```
- This part of the query selects the `customer_id` column and counts the occurrences of `visit_id`. The result is aliased as `count_no_trans`.

```sql
FROM
    Visits
```
- This specifies that the data is being retrieved from the `Visits` table.

```sql
WHERE
    visit_id NOT IN (
        SELECT
            visit_id
        FROM
            Transactions
    )
```
- This part of the query filters the rows based on a condition. It selects visits where the `visit_id` is not present in the `Transactions` table. This effectively selects visits where no transactions occurred.

```sql
GROUP BY
    customer_id
```
- This groups the result set by the `customer_id`, ensuring that the count of visits is aggregated per customer.

### Explanation:

The query first selects all visits from the `Visits` table. Then, it filters out visits where transactions occurred by checking if their `visit_id` is not present in the `Transactions` table. After filtering, it groups the remaining visits by `customer_id` and counts the number of visits for each customer where no transactions occurred. This provides a count of visits without transactions for each customer.
