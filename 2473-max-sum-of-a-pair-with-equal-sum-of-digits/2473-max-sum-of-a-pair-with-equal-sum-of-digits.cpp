class Solution {
public:
    int digitSum(int n)
    {
        int sum =0;
        while(n)
        {
            int digit = n%10;
            sum += digit;
            n = n/ 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int sum =-1;
        unordered_map<int,int> mp ;
        for(int i=0;i<nums.size();i++)
        {
            int ele = digitSum(nums[i]);
     
            if(mp.find(ele) != mp.end())
            {
                int j = mp[ele];
                int add = nums[j] + nums[i];
                cout<<add<<" ";
                sum = max(sum,add);
                if(nums[j]<=nums[i])
                {
                    mp[ele] =i;
                }
            }
            else{
                mp[ele] =i;
            }
        }
        return sum;
    }
};