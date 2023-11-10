class Solution {
public:

    bool palindrome(string st){
        int i = 0;
        int j = st.length() - 1;
        while(i<=j){
            if(st[i++]!=st[j--]){
                return false;
            }   
        }
        return true;
    
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i<s.length(); i++){
            for(int j = i; j<s.length(); j++){
                string st = s.substr(i, j-i+1);
                if(palindrome(st))
                    cnt++;
            }
        }
        return cnt;
    }
};