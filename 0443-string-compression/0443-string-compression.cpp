class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        int n = chars.size();
        int i = 0;

        while(i<n){
            int count = 1;
            char ch = chars[i];

            if(i+1<n && chars[i] == chars[i+1]){
                while(i+1<n && chars[i] == chars[i+1]){
                    count++;
                    i++;
                }

                if(count>1){
                    string s = to_string(count);
                    ans+=ch;
                    ans+= s;
                    i++;
                }
            }
            else{
                ans+=ch;
                i++;
            }
        }

        chars.clear();
        for(int i =0; i<ans.size(); i++){
            char ch1 = ans[i];
            chars.push_back(ch1);
        }

        return ans.size();
    }
};