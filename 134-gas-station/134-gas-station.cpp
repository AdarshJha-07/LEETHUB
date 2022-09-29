class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int t_gas=0,t_cost=0,start=0,curr=0;
        for(int i=0;i<gas.size();i++)
            t_gas+=gas[i];
        for(int i=0;i<cost.size();i++)
            t_cost+=cost[i];
        if(t_gas<t_cost)
            return -1;
        for(int i=0;i<gas.size();i++){
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        return start;
    }
};