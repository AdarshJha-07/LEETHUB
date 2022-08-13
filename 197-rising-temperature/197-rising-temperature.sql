select w1.id from weather w1 join weather w2 on (To_Days(w1.recordDate) - To_Days(w2.recordDate)) = 1 
and w1.temperature > w2.temperature;

