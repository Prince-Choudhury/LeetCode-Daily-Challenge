class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }

       string temp = s+s;

       if(temp.find(goal) == string::npos){ // No matches found
        return false;
       }

       return true;
    }
};