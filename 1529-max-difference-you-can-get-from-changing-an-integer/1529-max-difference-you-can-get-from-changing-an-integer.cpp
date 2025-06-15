class Solution {
    int strToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }

public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        string numStr2 = numStr;
        char a = 'x';
        char b = 'x';
        char toReplaceB = '0';
        for (int i = 0; i < numStr.size(); i++) {

            if (a == 'x' && numStr[i] != '9')
                a = numStr[i];
            if (b == 'x' && numStr[i] != '1' && numStr[i] != '0') {
                b = numStr[i];
                if (i == 0)
                    toReplaceB = '1';
            }

            if (numStr[i] == a) {
                numStr[i] = '9';
            }
            if (numStr2[i] == b) {
                numStr2[i] = toReplaceB;
            }
        }
        int newNum = strToInt(numStr);
        int newNum2 = strToInt(numStr2);
        return newNum - newNum2;
    }
};