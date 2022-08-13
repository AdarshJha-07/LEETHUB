# Write your MySQL query statement below

Select s.Score ,Count(t.Score) As 'Rank' from Scores s,
(Select  Distinct Score from Scores ) t 
where s.Score<=t.Score
Group By s.id
Order By s.Score desc;
# SELECT S.Score, COUNT(S2.Score) AS 'Rank' FROM Scores S,
# (SELECT DISTINCT Score FROM Scores) S2
# WHERE S.Score<=S2.Score
# GROUP BY S.Id 
# ORDER BY S.Score DESC;