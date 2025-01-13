class Solution {
public:

    int solve(vector<int>&prices, int index, int size, int &min_price, int&maxprof){
        if(index>=size){
            return maxprof;
        }

        maxprof = max(maxprof,prices[index]-min_price);
        min_price = min(prices[index],min_price);

        return solve(prices, index+1, size, min_price, maxprof);
    }

    int maxProfit(vector<int>& prices) {
        int index = 1;
        int size = prices.size();
        int min_price = prices[0];
        int maxprof = 0;
        int ans = solve(prices, index, size, min_price, maxprof);
        return ans;
    }
};


