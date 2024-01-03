class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //create min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(nums[i]);
        }
        //for remaining elements, push only if they are greater than top
        for(int i =k; i<n; i++) {
                int element = nums[i];
                if(element > pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;
    }
};