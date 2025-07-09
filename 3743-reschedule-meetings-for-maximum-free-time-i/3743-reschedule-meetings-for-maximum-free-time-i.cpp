class Solution {
public:
    int maxFreeTime(int n, int k, vector<int>& start, vector<int>& end) {
        vector<int> gaps ;
        int s = start.size() ;

        if( start[0] > 0 ) {
            gaps.push_back(start[0]) ;
        }
        for(int i= 1 ; i < s ; i++) {
             gaps.push_back(start[i] - end[i-1]) ;
        }
        if( n- end[s-1] > 0 )
         gaps.push_back(n-end[s-1]) ;

        for(auto i : gaps) cout << i <<" " ;
        cout << endl ;
        int temp = 0 ;
        for(int i = 0 ; i<=k && i < gaps.size() ; i++) {
            temp += gaps[i] ;
            cout << temp << " " ;
        }

        int maxi = temp ;
        for(int i = k+1 ; i < gaps.size() ; i++) {
            temp = temp + gaps[i] - gaps[i-k-1] ;
            maxi = max( maxi , temp) ;
            cout << temp << " " ;
        }

        return maxi ;
    }
};