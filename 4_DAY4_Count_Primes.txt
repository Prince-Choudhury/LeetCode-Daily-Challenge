class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> isPrime(n+1, true);
        isPrime[0]=isPrime[1]=false;

        for(int i = 2; i*i<=n;i++){
            if(isPrime[i]){

                int j = i*i;
                while(j<=n){
                    isPrime[j] = false;
                    j+=i;
                }
            }
        }
        // Count the number of primes
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
