class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>arr;
        int len = right - left + 1;
        for(int i = left; i<=right; i++){
            arr.push_back(i);
        }

        vector<int>ans;
        for(int i = 0; i<arr.size(); i++){
            int num = arr[i];
            bool isTrue = true;

            if(num<2) continue;

            for(int j = 2; j*j<=num; j++){
                if(num % j == 0){
                    isTrue = false;
                    break;
                }
            }

            if(isTrue){
                ans.push_back(num);
            }

        }

        if(ans.size()<=1){
            return {-1, -1};
        }

        int minDiff = INT_MAX;
        int index = -1;

        for (int i = 0; i < ans.size() - 1; i++) {
            int diff = ans[i + 1] - ans[i];
            if (diff < minDiff) {
                minDiff = diff;
                index = i;
            }
        }

        return {ans[index], ans[index + 1]};
    }
};