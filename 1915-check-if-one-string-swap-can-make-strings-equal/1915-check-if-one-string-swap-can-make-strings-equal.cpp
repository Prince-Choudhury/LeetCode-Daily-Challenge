class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }

        if(s1 == s2){
            return true;
        }

        string s = s2;
        for(int i = 0; i<s2.size(); i++){
            for(int j = i+1; j<s2.size();j++){
                swap(s[i], s[j]);
                if(s == s1){
                    return true;
                }
                s = s2;
            }
        }

        return false;
    }
};