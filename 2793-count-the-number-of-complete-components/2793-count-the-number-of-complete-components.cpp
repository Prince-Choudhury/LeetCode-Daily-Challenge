class Solution {
public:
    vector<int> par, edgeCount, nodeCount;
    int find(int i){
        if(par[i] == -1) return i;
        return find(par[i]);
    }
    
    void unionPair(int a, int b ){
        int pa = find(a), pb = find(b);
        edgeCount[pa] += 1;
        if(pa != pb){
            par[pb] = pa;
            edgeCount[pa] += edgeCount[pb];
            nodeCount[pa] += nodeCount[pb];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        par.resize(n, -1);   edgeCount.resize(n, 0);    nodeCount.resize(n, 1);
        for(auto e: edges) unionPair(e[0], e[1]);
        for(int i = 0; i < n; ++i){
            if(nodeCount[i] && par[i] == -1  && ( nodeCount[i] * (nodeCount[i] - 1)/2 == edgeCount[i] ) ) ans++;
        }
        return ans;
    }
};