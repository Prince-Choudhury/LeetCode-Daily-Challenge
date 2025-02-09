class Solution {
public:
    int convert(string s){
        int num = 0;
        char ch1 = s[0];
        char ch2 = s[1];

        int n1 = ch1 - 'a';
        int n2 = ch2 - 'a';

        num = num + n1;
        num = num * 10 + n2;
        num = num * 60;

        char ch3 = s[3];
        char ch4 = s[4];
        
        int n3 = ch3 - 'a';
        int n4 = ch4 - 'a';

        int num2 = 0;
        num2 = num2 + n3;
        num2 = num2* 10 + n4;

        int ans = num + num2;

        return ans;
    }

    int solve(int a, int b){

        if(a == b){
            return 0;
        }

        else if(a>b){
            int x = a-b;
            int y = 1440 - a + b;
            return min(x, y);
        }

        else if(b>a){
            int x = b-a;
            int y = 1440 - b + a;
            return min(x,y);
        }
        return 0;
    }

    int findMinDifference(vector<string>& arr) {
        int n = arr.size();
        int ans = 1440;

        vector<int>v;

        for(int i = 0; i<n; i++){
            int minutes = convert(arr[i]);

            v.push_back(minutes);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i<v.size()-1; i++){
            int diff = solve(v[i], v[i+1]);
            ans = min(ans, diff);
        }

        //Check first and last --> Circular
        int difference = solve(v[0], v[v.size()-1]);
        ans = min(ans, difference);

        return ans;
    }
};