class RecentCounter {
    queue<int>q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        //1.
        q.push(t);

        //2. pop invalid req. older, older than t - 3000
        while(!q.empty() && q.front() < (t - 3000)){
            q.pop();
        }

        //3. Now q has only number of recent calls : R = [t - 3000, t]
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */