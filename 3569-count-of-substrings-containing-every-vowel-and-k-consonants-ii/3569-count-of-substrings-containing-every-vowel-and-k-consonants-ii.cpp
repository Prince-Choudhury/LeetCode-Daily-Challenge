class Solution {
public:
    long long atLeast(string s, int k){
        int n = s.size();
        int i = 0, j = 0;
        int cons = 0;
        long long res = 0;
        unordered_map<char, int> mp;

        while(j < n){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') mp[s[j]]++;
            else cons++;

            while(cons >= k && mp.size() == 5){
                res += (n - j);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                }
                else cons--;
                i++;
            }
            j++;
        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeast(word, k) - atLeast(word, k+1);
    }
};