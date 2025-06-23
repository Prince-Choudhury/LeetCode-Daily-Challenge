class Solution {
public:
    bool is_palindrome(const string& s)
    {
        int l = 0, r = s.length() - 1;
        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    string tobasek(long long n, int k)
    {
        if(n == 0) return "0";
        string res = "";
        while(n > 0)
        {
            res += to_string(n%k);
            n /= k;
        }
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        long long len = 1;
        while(n > 0)
        {
            long long hl = (len + 1) / 2;
            long long l = pow(10, hl - 1);
            long long r = pow(10, hl);
            for(long long i = l; i < r; ++i)
            {
                string f1 = to_string(i);
                string f2 = f1;
                reverse(f2.begin(), f2.end());
                string p_str = f1 + f2.substr(len % 2);
                long long p = stoll(p_str);
                string bks = tobasek(p, k);
                if(is_palindrome(bks))
                {
                    sum += p;
                    n--;
                    if(n == 0) return sum;
                }
            }
            len++;
        }
        return sum;
    }
};