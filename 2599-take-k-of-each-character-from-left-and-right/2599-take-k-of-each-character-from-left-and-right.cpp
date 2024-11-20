class Solution {
public:
    bool check1(vector<int> &v,int &k){
        for(auto &i: v){
            if(i<k)return true;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        vector<int> v(3,0);
        for(auto &i: s){
            v[i-'a']++;
        }
        if(check1(v,k)){
            return -1;
        }
        int i = 0, j =0,n=s.length(),ans=0;
        while(i<n){
            v[s[i]-'a']--;
            while(check1(v,k)){
                v[s[j]-'a']++;
                j++;
            }
            ans = max(i-j+1,ans);
            i++;
        }
        return s.length()-ans;
    }
};