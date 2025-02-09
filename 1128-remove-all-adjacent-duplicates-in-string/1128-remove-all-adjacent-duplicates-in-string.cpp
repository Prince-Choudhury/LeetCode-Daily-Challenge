class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        while(i+1<s.size()){
            if(s[i] == s[i+1]){
                int index = 1;
                if(i>0){
                    index = i;
                }
                
                s.erase(i, 2);
                i = index -1;
            }
            else{
                i++;
            }
        }

        string ans = s;

        return ans;
    }
};