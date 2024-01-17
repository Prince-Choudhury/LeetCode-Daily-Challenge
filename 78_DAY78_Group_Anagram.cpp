class Solution {
public:
    string sortString(string word) {
        sort(word.begin(), word.end());
        return word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> word_map;
        map<string, int>::const_iterator pos;
        vector<vector<string>> output;
        string key, word;
        int index;
        int count = 0;
        for (int i = 0; i < strs.size(); i++) {
            word = strs.at(i);
            key = sortString(word);
            pos = word_map.find(key);
            if (pos == word_map.end()) {
                word_map.insert(pair<string, int>(key, count));
                vector<string> new_word_vec;
                new_word_vec.push_back(word);
                output.push_back(new_word_vec);
                count++;
            }
            else {
                output.at(pos->second).push_back(word);
            }
        }
        return output;
    }
};