class Solution {
public:
    long countSteps(int n, long prefix, long nextPrefix) {
        long steps = 0;
        while (prefix <= n) {
            steps += min((long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        k--;  
        
        while (k > 0) {
            long steps = countSteps(n, current, current + 1);
            
            if (steps <= k) {
               
                current++;
                k -= steps;  
            } else {
               
                current *= 10;
                k--;  
            }
        }
        
        return current;
    }
};




//TLE

/*
class Solution {
public:

    static bool mycomp(int a, int b){
        return to_string(a)<to_string(b);
    }

    int findKthNumber(int n, int k) {

        vector<int>arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        }

        sort(arr.begin(), arr.end(), mycomp);

        return arr[k-1];
    }
};*/