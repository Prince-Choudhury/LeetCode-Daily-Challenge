class Solution {
public:
    void addNum(int a, vector<int>& f)
    {
        for(int i = 0; i < 32; i++)
        {
            if(a & (1<<i)) f[i]++;
        }
    }
    void subNum(int a, vector<int>& f)
    {
        for(int i = 0; i < 32; i++)
        {
            if(a & (1<<i)) f[i]--;
        }
    }
    int val(vector<int>& f)
    {
        int num = 0;
        for(int i = 0; i < 32; i++)
        {
            if(f[i]) num += 1 << i;
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(32,0);

        int i = 0, j = 0, l = INT_MAX;
        while(i <= j && j < nums.size())
        {
            addNum(nums[j], f);

            while(val(f) >= k && i <= j)
            {
                l = min(l, j-i+1);
                subNum(nums[i], f);
                i++;
            }

            j++;
        }
        if(l == INT_MAX) return -1;
        return l;
    }
};