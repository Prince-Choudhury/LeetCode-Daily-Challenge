class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans ="";
        int i =0;

        while(i<n){
            if(ans.length() > 0){
                if(ans[ans.length()-1]==s[i])
                    ans.pop_back();
            
                else
                    ans.push_back(s[i]);
            }
            else
                ans.push_back(s[i]);
            
            i++;
        }
        return ans;
        
 
        
    }
};