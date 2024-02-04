class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFreq;

        for (const string& word : words) {
            wordFreq[word]++;
        }

        auto compare = [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> minHeap(compare);

        for (const auto& entry : wordFreq) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
