class Solution {
public:
    bool isvow(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'
          || ch == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n=w.size();
        
        vector<int> pre(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            string s=w[i];
            char f=s[0],l=s[s.size()-1];
            
            //check vowels
            if(isvow(f) && isvow(l)){
                cnt++;
            }
            
            pre[i]=cnt;
        }
        vector<int> ans(q.size());
        int i=0;
        
        //for(int i=0; i<pre.size(); i++) cout<<pre[i]<<" ";
        for(auto &it: q){
            int s=it[0],e=it[1];
            if(s == 0){
                ans[i++] = pre[e];
            }
            else{
                ans[i++] = pre[e]-pre[s-1];
            }
        }
        
        return ans;
    }
};