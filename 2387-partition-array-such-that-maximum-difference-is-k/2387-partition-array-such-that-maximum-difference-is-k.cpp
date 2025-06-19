class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        int last=-1;
        int count=0;
        while(pq.size()>0)
        {
            int t=pq.top();
            pq.pop();
            if(last!=-1)
            {
                if(last-t<=k)
                {
                    continue;
                }
                else
                {
                    last=t;
                    count++;
                }
            }
            else
            { count++;
                last=t;
            }
        }
        return count;
    }
};