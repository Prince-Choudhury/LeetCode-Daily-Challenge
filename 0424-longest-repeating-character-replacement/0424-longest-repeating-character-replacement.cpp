class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int l = 0;
        int maxf = 0;
        int freq[26] = {0};

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;

            maxf = max(maxf, freq[s[r]-'A']);

            int changes = (r-l+1) - maxf;

            if (changes > k) {
                freq[s[l] - 'A']--;
                l++;

                changes = (r-l+1) - maxf;
            }

            if(changes<=k){
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};