

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by end time
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // Step 2: Precompute the maximum value up to each point
        int n = events.size();
        vector<int> maxVal(n, 0); // maxVal[i] stores the max value from event 0 to i
        maxVal[0] = events[0][2];
        for (int i = 1; i < n; i++) {
            maxVal[i] = max(maxVal[i - 1], events[i][2]);
        }

        // Step 3: Calculate the maximum sum of two non-overlapping events
        int result = 0;
        for (int i = 0; i < n; i++) {
            // Option 1: Take this event alone
            result = max(result, events[i][2]);

            // Option 2: Combine this event with a previous non-overlapping event
            int start = events[i][0];
            int low = 0, high = i - 1, bestPrev = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (events[mid][1] < start) { // Compatible event found
                    bestPrev = max(bestPrev, maxVal[mid]);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            result = max(result, events[i][2] + bestPrev);
        }

        return result;
    }
};

