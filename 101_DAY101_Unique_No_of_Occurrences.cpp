class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mapping;
        unordered_set<int>occurrenceSet;
        int n = arr.size();

        for(int i = 0; i<n; i++){
            mapping[arr[i]]++;
        }

        for(auto i : mapping){
            if(!occurrenceSet.insert(i.second).second){
                // If the insertion fails, it means the occurrence count is not unique
                return false;
            }
        }
        return true;
    }
};