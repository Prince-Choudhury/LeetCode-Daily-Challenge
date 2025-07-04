class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int inc = 0;
        k--;

        long long l = k;
        int bits = 0;
        while(l>>=1){
            bits++;
        }
        for(int i = bits; i >=0; i--){
            int bit = (k >> i) & 1;
            if(bit) inc += operations[i];
        }
        return (inc%26) + 'a';
    }
};