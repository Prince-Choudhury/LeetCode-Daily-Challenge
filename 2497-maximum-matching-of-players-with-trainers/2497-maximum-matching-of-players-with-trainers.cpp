class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=players.size()-1;
        int j=trainers.size()-1;
        int cnt=0;
        while(i>=0 and j>=0){
            if(players[i]<=trainers[j]){
                cnt++;
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        return cnt;
    }
};