class Solution {
public:
    int dfs(unordered_map<int,vector<int>>& graph, int currentNode, int parentNode,int k){
        if(k<0) return 0;
        if(k==0) return 1;
        int ans = 1;
        for(auto& nextNode:graph[currentNode]){
            if(nextNode!=parentNode){
                ans+=dfs(graph,nextNode,currentNode,k-1);
            }
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        unordered_map<int,vector<int>> graph1, graph2;
        for(auto& edge:edges1){
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge:edges2){
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        
        vector<int>ans(n,0);
        int summation = 0;
        for(int i=0;i<m;i++){
            summation = max(summation,dfs(graph2,i,-1,k-1));
        }
        for(int i=0;i<n;i++){
            ans[i] += dfs(graph1,i,-1,k)+summation;
        }
        return ans;
    }
};