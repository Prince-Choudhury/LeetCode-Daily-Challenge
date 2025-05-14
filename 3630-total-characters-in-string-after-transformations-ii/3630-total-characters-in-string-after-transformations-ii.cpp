#define ll long long
class Solution {
public:
    int md = 1e9 + 7;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = s.size();
        vector<ll> fq(26);
        for(int i=0;i<n;i++){
            fq[s[i]-'a']++;
        }

        vector<vector<int>> T(26, vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=1;j<=nums[i];j++){
                T[i][(i+j)%26]++;
            }
        }

        auto Tt = binarypower(T,t);
        vector<ll> upfq(26,0);
        for(int i=0;i<26;i++){
            if(fq[i]==0) continue;
            for(int j=0;j<26;j++){
                upfq[i] = (upfq[i] + (Tt[i][j]*fq[i])%md)%md;
            }
        }
        ll ans = 0;
        for(int i=0;i<26;i++){
            ans = (ans + upfq[i])%md;
        }
        return (int)ans;
    }
    vector<vector<int>> binarypower(vector<vector<int>> T,ll exp){
        vector<vector<int>> res(26, vector<int>(26,0));
        for(int i=0;i<26;i++){
            res[i][i] = 1;
        }
        while(exp>0){
            if(exp&1){
                res = matmul(res,T);
            }
            T = matmul(T,T);
            exp>>=1;
        }
        return res;
    }
    vector<vector<int>> matmul(vector<vector<int>>& A, vector<vector<int>>& B){
        vector<vector<int>> res(26, vector<int>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ll Aij = A[i][j];
                if(Aij==0) continue;  
                for(int k=0;k<26;k++){
                    res[i][k] = (res[i][k] + (Aij*B[j][k])%md)%md; 
                }
            }
        }
        return res;
    }

};