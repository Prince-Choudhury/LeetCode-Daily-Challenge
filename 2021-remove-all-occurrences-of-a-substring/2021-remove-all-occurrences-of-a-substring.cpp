class Solution {
public:
    vector<int> computeLPS(string s){
        vector<int>lps(s.size(), 0);
        int i = 1;
        int j = 0;
        while(i<s.size()){
            if(s[i]==s[j]){
                lps[i] = j+1;;
                i++;
                j++;
            }

            else{
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }

        return lps;
    }

    bool applyKMP(string s, string part){
        vector<int> lps = computeLPS(part);

        int i = 0;
        int j = 0;
        while(i<s.size()){
            if(s[i] == part[j]){
                i++;
                j++;
            }

            else{
                if(j == 0) i++;
                else j = lps[j-1];
            }

            if(j == part.size()){
                return 1;
            }
        }

        return 0;
    }

    int findIndex(string s, string part){
        vector<int> lps = computeLPS(part);

        int i = 0;
        int j = 0;
        int index = -1;
        while(i<s.size()){
            if(s[i] == part[j]){
                i++;
                j++;
            }

            else{
                if(j == 0) i++;
                else j = lps[j-1];
            }

            if(j == part.size()){
                index = (i-1) - part.size() + 1; // i-part.size()
                return index;
            }
        }

        return -1;
    }
    void solve(string &s, string part)
    {
        if(!applyKMP(s,part))
        {
            return;
        }else{
            int index =findIndex(s,part);
            s.erase(index,part.size());
            solve(s,part);
        }
    }
    string removeOccurrences(string s, string part) {
        solve(s,part);
        
        return s;
    }
};