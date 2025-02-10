class Solution {
public:
    string clearDigits(string s) {
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'){
                s.erase(i, 1);
                if(i-1>=0){
                    s.erase(i-1, 1);
                }
                i=0;
            }
        }

        return s;
    }
};