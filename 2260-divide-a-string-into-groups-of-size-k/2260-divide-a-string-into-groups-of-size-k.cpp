class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for (int i = 0; i < s.size(); i = i + k) {
            int c = k;
            string temp = "";
            int j = i;
            while (c-- && j < s.size()) {
                temp += s[j];
                j++;
            }

            ans.push_back(temp);
        }

        int rem = s.size() % k;
        int num = k - rem;

        int n = ans.size();

        if (ans[n - 1].size() != k) {
            string st = ans[n - 1];
            while (num--) {
                st += fill;
            }

            ans[n - 1] = st;
        }

        return ans;
    }
};