# Write your MySQL query statement below

Select * from Cinema c1 where id mod 2 <> 0  and c1.description <> 'boring' order by c1.rating desc;
