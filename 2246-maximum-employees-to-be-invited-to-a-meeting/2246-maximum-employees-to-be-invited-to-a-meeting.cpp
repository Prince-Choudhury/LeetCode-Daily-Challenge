class Solution {
public:
    int topo(int i,vector<int> &indegree,vector<int> adj[],vector<int> &vis)
    {
        queue<int> q;
        q.push(i);
        int el=i;
        while(q.size()>0)
        {
            int node=q.front();
            el=node;
            vis[node]=1;
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return adj[el][0]; // element of the cycle
    }

    int dfs(int node,vector<int> adj[],vector<int> &vis) // Longest Cycle
    {
        int c=0;
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                c+=dfs(it,adj,vis);
            }
        }
        return c+1;
    }

    int maxdfs(int node,vector<int> adj[],int a,vector<int> &vis) // longest tail
    {
        vis[node]=1;
        int c=0;
        for(auto it:adj[node])
        {
            if(it!=a)
            {
                c=max(c,maxdfs(it,adj,a,vis));
            }
        }
        return c+1;
    }

    int maximumInvitations(vector<int>& favorite) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<int> adj[favorite.size()],vis(favorite.size(),0);
        vector<int> indegree(favorite.size(),0),radj[favorite.size()];
        for(int i=0;i<favorite.size();i++)
        {
            adj[i].push_back(favorite[i]);
            radj[favorite[i]].push_back(i);
            indegree[favorite[i]]++;
        }
        int ans1=0,cy=0;
        for(int i=0;i<favorite.size();i++)
        {
            if(indegree[i]==0 && !vis[i])
            {
                int p=topo(i,indegree,adj,vis);
                if(adj[adj[p][0]][0]==p)// cycle of length 2
                {
                    int a=adj[p][0];
                    int b=maxdfs(p,radj,a,vis)-1; // longest tail
                    vis[p]=0; // so that later can be detected while calculating componants with cycle length 2
                    ans1+=b;
                }
            }
        }
        int c=0;
        for(int i=0;i<favorite.size();i++)
        {
            if(!vis[i])
            {
                int a=dfs(i,adj,vis);
                if(a==2)
                {
                    c++; // Number of componants with cycle length 2
                }
                else
                {
                    cy=max(cy,a); // Finding Maximum Cycle
                }
            }
        }
        int fans=ans1+2*c; // adding 2 nodes of cycle length 2 for each componant
        return max(cy,fans);
    }
};