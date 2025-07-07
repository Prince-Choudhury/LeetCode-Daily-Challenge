bool arrange(vector<int> & v1, vector<int> &v2){
    return v1[1] < v2[1];
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.size() == 0 ){
            return 0;
        }
        int i, j, noOfEvents = 0;
        set<int> s;
        sort(events.begin(),events.end(),arrange);
        int n = events.size();
        int lastDay = events[n-1][1];
        for(i = 0; i <= lastDay; i++){
            s.insert(i);
        }
        for(i = 0; i < events.size(); i++){
            auto day = s.lower_bound(events[i][0]);
            if(day == s.end() || *day > events[i][1]){
                continue;
            }else{
                noOfEvents++;
                s.erase(day);
            }
        }
        return noOfEvents;
    }
};