class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        double ans=0, n=classes.size(), i=0;
        priority_queue<pair<double,int>> pq;
        for(auto x:classes) 
        pq.push({((double)(x[0]+1)/(x[1]+1))-((double)(x[0])/(x[1])),i++});
        // har class mi 1 pass student daal ke max heap mi arrange kar rahe hai 
        // ki kismi profit ho raha hai , WITH ITS INDEX;
        while(k--)
        {
            int i=pq.top().second;
            int p=classes[i][0]++, t=classes[i][1]++; //add 1 student in that class
            pq.pop();
            // ab uska new profit on adding a passes student daal denge
            pq.push({((double)(p+2)/(t+2))-((double)(p+1)/(t+1)),i});           
        }
        for(auto x:classes)
        {
            ans+=((double)x[0])/x[1];
        }
        return ans/n;
    }
};