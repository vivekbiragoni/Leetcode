Joins in SQL are used to combine rows from two or more tables based on a related column between them. Here are the main types of joins and their purposes:

### 1. **INNER JOIN**
An `INNER JOIN` returns only the rows that have matching values in both tables. If there is no match, the row is not included in the result.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
INNER JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
```
- This query returns only the employees who have a corresponding unique ID in the `EmployeeUNI` table.

### 2. **LEFT JOIN (or LEFT OUTER JOIN)**
A `LEFT JOIN` returns all rows from the left table (the first table mentioned), and the matched rows from the right table. If no match is found, NULL values are returned for columns from the right table.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
```
- This query returns all employees, including those without a unique ID. For employees without a unique ID, the `unique_id` will be `NULL`.

### 3. **RIGHT JOIN (or RIGHT OUTER JOIN)**
A `RIGHT JOIN` returns all rows from the right table (the second table mentioned), and the matched rows from the left table. If no match is found, NULL values are returned for columns from the left table.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
RIGHT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
```
- This query returns all rows from `EmployeeUNI`, including those that don't have a corresponding employee. For such rows, the `name` will be `NULL`.

### 4. **FULL JOIN (or FULL OUTER JOIN)**
A `FULL JOIN` returns rows when there is a match in one of the tables. It returns all rows from the left table and all rows from the right table, with `NULL` values in places where the join condition is not met.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
FULL JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
```
- This query returns all employees and all unique IDs, pairing them where possible and filling in `NULL` where there is no match.

### 5. **CROSS JOIN**
A `CROSS JOIN` returns the Cartesian product of the two tables. Every row from the first table is paired with every row from the second table.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
CROSS JOIN EmployeeUNI;
```
- This query pairs each employee with every unique ID, leading to a result set where the number of rows is the product of the number of rows in the two tables.

### 6. **SELF JOIN**
A `SELF JOIN` is a regular join but the table is joined with itself. This can be useful to compare rows within the same table.

**Example:**
```sql
SELECT a.name AS Employee1, b.name AS Employee2
FROM Employees a, Employees b
WHERE a.id != b.id;
```
- This query pairs each employee with every other employee, excluding self-pairings.

### 7. **NATURAL JOIN**
A `NATURAL JOIN` automatically joins tables based on all columns with the same name and datatype. It can be either an `INNER` or `OUTER` join.

**Example:**
```sql
SELECT Employees.name, EmployeeUNI.unique_id
FROM Employees
NATURAL JOIN EmployeeUNI;
```
- This query automatically joins the tables on columns that have the same names and compatible data types. However, it's generally not recommended for production use due to its implicit nature.

### Practical Example of Joins in a Context:

Given two tables:

**Employees:**
```
+----+----------+
| id | name     |
+----+----------+
| 1  | Alice    |
| 2  | Bob      |
| 3  | Charlie  |
+----+----------+
```

**Departments:**
```
+----+------------+
| id | department |
+----+------------+
| 1  | HR         |
| 2  | Engineering|
| 4  | Sales      |
+----+------------+
```

- **INNER JOIN**:
  ```sql
  SELECT Employees.name, Departments.department
  FROM Employees
  INNER JOIN Departments ON Employees.id = Departments.id;
  ```
  Result: Only pairs with matching IDs:
  ```
  +--------+------------+
  | name   | department |
  +--------+------------+
  | Alice  | HR         |
  | Bob    | Engineering|
  +--------+------------+
  ```

- **LEFT JOIN**:
  ```sql
  SELECT Employees.name, Departments.department
  FROM Employees
  LEFT JOIN Departments ON Employees.id = Departments.id;
  ```
  Result: All employees, with departments where available:
  ```
  +--------+------------+
  | name   | department |
  +--------+------------+
  | Alice  | HR         |
  | Bob    | Engineering|
  | Charlie| NULL       |
  +--------+------------+
  ```

- **RIGHT JOIN**:
  ```sql
  SELECT Employees.name, Departments.department
  FROM Employees
  RIGHT JOIN Departments ON Employees.id = Departments.id;
  ```
  Result: All departments, with employees where available:
  ```
  +--------+------------+
  | name   | department |
  +--------+------------+
  | Alice  | HR         |
  | Bob    | Engineering|
  | NULL   | Sales      |
  +--------+------------+
  ```

- **FULL JOIN** (Note: Not all databases support `FULL JOIN` directly):
  ```sql
  SELECT Employees.name, Departments.department
  FROM Employees
  FULL JOIN Departments ON Employees.id = Departments.id;
  ```
  Result: All employees and all departments:
  ```
  +--------+------------+
  | name   | department |
  +--------+------------+
  | Alice  | HR         |
  | Bob    | Engineering|
  | Charlie| NULL       |
  | NULL   | Sales      |
  +--------+------------+
  ```
