class Solution {
public:
    char smaller(vector<int> &freq){
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                return ('a'+i);
            }
        }

        return ('a'+26);
    }
    
    string robotWithString(string s) {
		// Store the frequencies, which help in finding the smaller char to the right of the current char
        vector<int> freq(26, 0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        
        string ans = "";
        string t = "";
        int i = 0;
        
        while(i<s.size()){
            t.push_back(s[i]);
            freq[s[i]-'a']--;
			// If there is no smaller character to the right of the top, then it should be added to the ans
            while(!t.empty() && t.back() <= smaller(freq)){
                ans.push_back(t.back());
                t.pop_back();
            }
            i++;
            
        }
        
        return ans;
    }
};