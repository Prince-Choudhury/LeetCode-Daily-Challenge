class Solution {
public:
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
            string s = arr[i];
            int h = stoi(s.substr(0, 2));
            h = h*60;

            int m = stoi(s.substr(3, 2));

            int minutes = h + m;

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