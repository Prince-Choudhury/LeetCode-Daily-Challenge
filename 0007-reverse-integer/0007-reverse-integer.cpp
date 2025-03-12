/*

class Solution {
public:
    int reverse(int n) {
        if (n == 0) return 0;
        
        string s = to_string(n);
        std::reverse(s.begin(), s.end()); 
        
        if (n < 0) {
            s.pop_back(); // Remove '-' from the end
            s = "-" + s;  // Add '-' at the front
        }

        long ans = stol(s); // Convert to long to prevent overflow

        // Check if within int range
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        
        return static_cast<int>(ans);
    }
};

*/

class Solution {
public:
    int reverse(int n) {
        if(n == 0){
            return 0;
        }

        long ans = 0;

        while(n!=0){
            int digit = n%10;

            ans = ans*10 + digit;

            n = n/10;

        }

        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }

        return int(ans);
    }

};