# Write your MySQL query statement below

select name as Customers from Customers cc where cc.id not  in

(Select o.customerId from Orders  o join Customers c On o.customerId = c.id);