class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top = 0, bottom = 0, both = 0;
        int ans = n;
        for(int i=1;i<=6;i++){
            top = 0, bottom = 0, both = 0;
            for(int j=0;j<n;j++){
                if(tops[j] != i && bottoms[j] != i) break;
                if(tops[j] == i && bottoms[j] == i) both++;
                if(tops[j] != i) bottom++;
                if(bottoms[j] != i) top++;
            }
            if(ans > min(top, bottom) && top+bottom+both == n) ans = min(top, bottom);
        }
        if(ans < n) return ans;
        return -1;
    }
};