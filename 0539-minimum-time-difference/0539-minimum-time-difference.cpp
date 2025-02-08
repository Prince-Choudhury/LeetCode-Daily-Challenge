class Solution {
public:
    int convert(string s) {
        int ans = 0;
        char ch1 = s[0];
        char ch2 = s[1];
        int digit1 = ch1 - '0', digit2 = ch2 - '0';
        ans += digit1;
        ans = ans * 10 + digit2;
        ans = ans * 60;
        char ch3 = s[3];
        char ch4 = s[4];
        digit1 = ch3 - '0', digit2 = ch4 - '0';

        int a = digit1 * 10 + digit2;
        ans = ans + a;
        return ans;
    }
    int solve(int a, int b) {

        if (a == b) {
            return 0;
        } else if (a > b) {
            int x = a - b;
            int y = 1440 - a + b;
            return min(x, y);
        } else if (b > a) {
            int x = b - a;
            int y = 1440 - b + a;
            return min(x, y);
        }
        return 0;
    }
    int findMinDifference(vector<string>& timePoints) {
        int ans = 1440;
        int n = timePoints.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            string s = timePoints[i];
            int a = convert(s);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
      
        for(int i=0;i<v.size()-1;i++)
        {
            int dif =solve(v[i],v[i+1]);
            ans = min(ans,dif);
        }
        int dif = solve(v[0],v[v.size()-1]);
        ans = min(ans,dif);

        return ans;
    }
};