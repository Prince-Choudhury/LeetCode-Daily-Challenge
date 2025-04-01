class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {

        if(k == 1 && arr.size() == 1){
            return arr[0];
        }
        priority_queue<int>pq;
        int n = arr.size();

        k = k%n;

        for(auto x : arr){
            pq.push(x);
        }

        while(k!=1 && !pq.empty()){
            k--;
            pq.pop();
        }

        cout<<pq.top();

        return pq.top();
    }
};