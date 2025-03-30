class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIdx;
        for(int i = 0; i < s.size(); i++){
            lastIdx[s[i]] = i;
        }
        int maxLastIdx = 0;
        int j = 0;
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            maxLastIdx = max(maxLastIdx, lastIdx[s[i]]);
            if(i == maxLastIdx){
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
    }
};