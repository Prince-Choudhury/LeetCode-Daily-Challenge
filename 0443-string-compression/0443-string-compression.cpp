class Solution {
public:
    int compress(vector<char>& s) {
        string ans = "";
        int i = 0, n = s.size();
        while (i < n) {
            int count = 1;
            char ch = s[i];
            
            if (i+1<n && s[i] == s[i + 1]) {
                while (i +1< n && s[i] == s[i + 1]) {
                    count++;
                    i++;
                }
                
                if (count > 1) {
                    string temp = to_string(count);
                    ans += ch;
                    ans += temp;
                    i=i+1;
                }
            }else{
                ans+=ch;
                i++;
            }
        }
        s.clear();

        for(int i=0;i<ans.size();i++)
        {
            char ch = ans[i];
            s.push_back(ch);
        }
        
        return s.size();
    }
};