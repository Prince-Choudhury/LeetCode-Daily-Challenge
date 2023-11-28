class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> st;
        st.push(0);

        vector<int> ans(prices.size());  // Initialize ans with the same size as prices

        for(int i = prices.size() - 1; i >= 0; i--){
            int curr = prices[i];

            while(!st.empty() && st.top() > curr){
                st.pop();
            }
            ans[i] = curr - st.top();
            st.push(curr);
        }
        return ans;
    }
};
