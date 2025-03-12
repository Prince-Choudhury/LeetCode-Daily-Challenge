class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0){
            return false;
        }

        long ans = 0;
        int num = n;

        while(n!=0){
            int digit = n%10;
            ans = ans*10 + digit;

            n = n/10;
        }

        if(ans == num){
            return true;
        }

        return false;
        
    }
};