class Solution {
public:
    int MOD=1e9+7;
    void solve(long long a, long long n, long long &ans){
        if(n==0) return;
        // finish n 

        if(n%2==0) {
            solve(a*a%MOD,n/2,ans);
        }
        else {
            solve(a,n-1,ans=(a*ans)%MOD);
        }
    }
    int countGoodNumbers(long long n) {
        long long even=n/2 + n%2;
        long long odd=n/2;
        long long eveans=1;
        long long oddans=1;
        solve(5,even,eveans);
        solve(4,odd,oddans);
        return (eveans*oddans%MOD);
    }
};