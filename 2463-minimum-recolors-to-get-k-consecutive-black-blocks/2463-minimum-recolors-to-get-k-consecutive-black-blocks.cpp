class Solution {
public:
    void solve(vector<string>& v, string s) {
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            for(int j=i;j<s.size();j++)
            {
                temp += s[j];
                v.push_back(temp);
            }
        }
    }
    
    int toReplace(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'W') {
                ans++;
            }
        }
        return ans;
    }

    int minimumRecolors(string blocks, int k) {
        vector<string> v;
     
        solve(v, blocks);  

        int ans = INT_MAX;

        for (int i = 0; i < v.size(); i++) {
            if (v[i].size() == k) {
                int newtoReplace = toReplace(v[i]);
                ans = min(ans, newtoReplace);
            }
        }

        return ans;
    }
};