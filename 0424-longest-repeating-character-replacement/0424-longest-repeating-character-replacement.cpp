class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int l = 0;
        int freq[26] = {0};

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;

            // Recalculate max frequency after every addition or removal
            int maxf = 0;
            for (int i = 0; i < 26; i++) {
                maxf = max(maxf, freq[i]);
            }

            int changes = (r-l+1) - maxf;

            // If more than k changes are needed, shrink the window
            while (changes > k) {
                freq[s[l] - 'A']--;
                l++;

                // Recalculate maxf again since window changed
                maxf = 0;
                for (int i = 0; i < 26; i++) {
                    maxf = max(maxf, freq[i]);
                }
                changes = (r-l+1) - maxf;
            }

            if(changes<=k){
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};