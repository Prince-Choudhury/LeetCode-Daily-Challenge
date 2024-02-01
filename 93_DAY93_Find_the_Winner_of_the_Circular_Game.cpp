class Solution {
public:
    int findTheWinner(int n, int k) {
        //All player should go into a queue
        queue<int>q;
        
        for(int i = 1; i<=n; i++){
            q.push(i);
        }

        while(q.size() > 1){
            //Simulate the game
            for(int i = 1; i < k; i++){
                auto player = q.front();
                q.pop();

                //It is not eliminated yet
                q.push(player);
            }

            //Kth player must be eliminated
            q.pop();
        }
        return q.front();
    }
};