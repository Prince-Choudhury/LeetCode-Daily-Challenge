
/*
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!= string :: npos){
            int index = s.find(part);
            int len = part.size();
            s.erase(index, len);
        }

        return s;
    }
};

*/

class Solution {
public:
    vector<int> compute(string pat) {
        vector<int> lps(pat.size(), 0);
        int i = 1, j = 0;

        while (i < pat.size()) {
            if (pat[i] == pat[j]) {
                lps[i] = j + 1;
                i++, j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1]; // Corrects improper looping
                }
            }
        }
        return lps;
    }

    bool kmp(string s, string pat) {
        vector<int> lps = compute(pat);
        int i = 0, j = 0;

        while (i < s.size()) {
            if (s[i] == pat[j]) {
                i++, j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }

            if (j == pat.size()) {
                return true; 
            }
        }

        return false; 
    }

    int getIndex(string s, string pat) {
        int n = s.size(), m = pat.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && s[i + j] == pat[j]) {
                j++;
            }

            if (j == m) {
                return i;
            }
        }

        return -1;
    }

    void solve(string& s, string part) {
        if (!kmp(s, part)) {
            return;
        } else {
            int i = getIndex(s,part);
            string a = "", b = "", finS = "";
            a = s.substr(0, i);

            if (i + part.size() < s.size()) {
                b = s.substr(i + part.size());
            }

            finS = a + b;
            s = finS;
            solve(s, part);
        }
    }
    string removeOccurrences(string s, string part) {
        
        string ans = s;
        solve(ans,part);

        return ans;
    }
};