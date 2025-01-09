class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (auto it : words) {
            int i = 0, j = 0;
            while (i < it.size() && j < pref.size()) {
                if (it[i] == pref[j]) {
                    i++;
                    j++;
                } else break;
            }
            if (j == pref.size()) cnt++;
        }
        return cnt;
    }
};