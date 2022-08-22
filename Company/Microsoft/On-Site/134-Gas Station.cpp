class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tunk= 0;
        int total_tunk = 0;
        int res = 0;
        for(int i=0; i<gas.size();i++){
            total_tunk += gas[i] - cost[i];
            tunk += gas[i] - cost[i];
            if(tunk <0){
                res = i+1;
                tunk = 0;
            }
            
        }
            
        return total_tunk >=0 ? res : -1;
    }
};