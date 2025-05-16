class Solution {
public:
     bool f(string &s,string& t)
     {
        int c = 0;
        for(int i=0;i<s.size();i++) 
        c+= s[i] != t[i];

        return c == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        int dp[n];
        for(int i=0;i<n;i++) 
        {
            dp[i] = 1;
            for(int j=0;j<i;j++) 
            {
                if(words[i].size() == words[j].size() && f(words[i],words[j]) && groups[i] != groups[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int l = *max_element(dp,dp+n);
        int i = n-1;
        vector<string> ans;
        for(int i=n-1;i>=0;i--) 
        {
            if(dp[i] != l) 
            continue;
            int x = words[i].size();
            vector<pair<string,int>> v = {{words[i],groups[i]}}; 
            int j = i;
            int m = l-1;
            while(j>=0 && m>0) 
            {
                if(words[j].size() == x && f(words[j],v.back().first) && dp[j] == m && v.back().second != groups[j])
                {
                    m--;
                    v.push_back({words[j],groups[j]});
                }
                j--;
            }
            if(v.size() == l) 
            {
                for(int k=v.size()-1;k>=0;k--) 
                ans.push_back(v[k].first);

                break;
            }
        }
        return ans;    
    }
};