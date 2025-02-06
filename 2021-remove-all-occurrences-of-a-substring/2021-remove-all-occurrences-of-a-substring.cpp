class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!= string :: npos){
            int index = s.find(part);
            int len = part.size();
            s.erase(index, len);
        }

        return s;
    }
};