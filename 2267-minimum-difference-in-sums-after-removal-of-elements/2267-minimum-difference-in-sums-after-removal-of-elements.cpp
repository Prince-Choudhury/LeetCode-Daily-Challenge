class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        long long ans = LLONG_MAX, cur = 0;
        priority_queue<int> rq;
        priority_queue<int, vector<int>, greater<int>> lq;
        vector<long long> r(n+1), l(n+1);
        
        for(int i = 0; i < n; i++) {
            rq.push(nums[i]);
            cur += nums[i];
        }
        r[0] = cur;

        for(int i = n; i < 2*n; i++) {
            if(rq.top() > nums[i]) {
                cur -= rq.top();
                rq.pop();
                cur += nums[i];
                rq.push(nums[i]);
            }
            r[i-n+1] = cur;
        }

        cur = 0; 
        for(int i = 3*n-1; i >= 2*n; i--) {
            lq.push(nums[i]);
            cur += nums[i];
        }
        l[n] = cur;

        for(int i = 2*n-1; i >= n; i--) {
            if(lq.top() < nums[i]) {
                cur -= lq.top();
                lq.pop();
                cur += nums[i];
                lq.push(nums[i]);
            }
            l[i-n] = cur;
        }

        for(int i = 0; i <= n; i++)
            ans = min(ans, r[i]-l[i]);

        return ans;
    }
};