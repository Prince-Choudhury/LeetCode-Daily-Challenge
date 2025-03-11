class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0,n=s.size();

        while(j<n)
        {
            mp[s[j]]++;
            
            while(mp.size()==3)
            {
                ans++;
                 ans+=n-j-1;
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
                
            }
           
            j++;

        }
        return ans;
    }
};