class Solution {
public:
    void rec(int prev,int& m,string&temp,vector<string>&cols){
        if(temp.size()==m){
            cols.push_back(temp);
            return;
        }

        for(int i=1;i<=3;i++){
            if(i!=prev){
                temp.push_back('0'+i);
                rec(i,m,temp,cols);
                temp.pop_back();
            }
        }
    }
    int colorTheGrid(int m, int n) {

        vector<vector<int>>grid(m,vector<int>(n));

        vector<string>cols;
        string temp="";
        rec(0,m,temp,cols);
        int mod=1e9+7;

        unordered_map<string,vector<string>>adj;
        for(auto it:cols){
            for(auto it2:cols){
                string x=it;
                string y=it2;
                bool f=true;
                for(int i=0;i<m;i++){
                    if(x[i]==y[i]){
                        f=false;
                        break;
                    }
                }
                if(f){
                    adj[x].push_back(y);
                }
                
            }
        }
        unordered_map<string,int>prev;
        for(auto it:adj){
            prev[it.first]=1;
        }

        for(int col=1;col<n;col++){
            unordered_map<string,int>next;
            for(auto it:prev){
                string x=it.first;
                int cnt=it.second;
                for(auto it2:adj[x]){
                    next[it2]=(next[it2]+cnt)%mod;;
                }
            }
            prev=next;
        }

        int ans=0;
        for(auto it:prev){
            ans=(ans+it.second)%mod;
        }
        return ans;
    }
};