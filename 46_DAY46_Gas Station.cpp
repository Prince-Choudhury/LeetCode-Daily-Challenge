class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        //index from where we are starting the movement
        int start = 0;

        //har ek index ko check krra h, k vo answer h ya nahi
        for(int i = 0; i<gas.size(); i++){
            balance = balance + gas[i] - cost[i];

            if(balance < 0){
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }

        if(balance -deficit >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};