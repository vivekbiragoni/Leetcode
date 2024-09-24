-- Write your PostgreSQL query statement below
select name
from Customer 
where Customer.referee_id != 2 or customer.referee_id is null;