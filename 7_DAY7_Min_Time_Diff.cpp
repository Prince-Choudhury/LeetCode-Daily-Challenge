class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        //Step 1: Convert time string into minutes integer value
        vector<int>minutes;
        for(int i = 0; i< timePoints.size();i++){
            string curr = timePoints[i];
            int hour = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalmin = (hour*60) + min;
            minutes.push_back(totalmin);
        }

        //step 2: sort
        sort(minutes.begin(), minutes.end());

        //step 3: Diff and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();
        for(int i = 0; i<n-1;i++){
            int diff = minutes[i+1]-minutes[i];
            mini = min(mini, diff);
        }

        //step 4: Diff between first and last because time is circular
        int lastDiff = (minutes[0]+1440) - minutes[n-1];
        mini = min(mini, lastDiff);
        
        return mini;
        
    }
};