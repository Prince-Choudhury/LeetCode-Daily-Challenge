class Solution {
public:
    long long maximumValueSum(vector<int>& nodes, int k, vector<vector<int>>& e) {
        int n = nodes.size();
        vector<int> diff(n, 0);
        long long sum = 0l;
        for(int i=0;i<n;i++) {
            diff[i] = (nodes[i]^k )- nodes[i];
            sum+=nodes[i]*1l;
        } 
        sort(diff.begin(), diff.end(), greater<int>());
        for(int i=0;i<n-1;i+=2) {
            if((diff[i] + diff[i+1])>0) {
                sum+=(diff[i] + diff[i+1])*1l;
            }
        }
        return sum;
    }
};