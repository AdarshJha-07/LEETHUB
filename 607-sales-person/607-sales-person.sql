# Write your MySQL query statement below

# Select  sp.name  from Orders od join SalesPerson sp on od.sales_id= sp.sales_id join Company cp on od.com_id = cp.com_id where  cp.name <> 'RED';
with cte as
(Select sales_id from orders  o join company c on o.com_id  = c.com_id where c.name ='RED')
Select name from salesPerson  sp where sp.sales_id not  IN (select distinct cte.sales_id from cte);