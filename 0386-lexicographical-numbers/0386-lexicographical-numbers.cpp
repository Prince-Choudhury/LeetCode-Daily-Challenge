class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;

        for(int i = 1; i<=n; i++){
            string s = to_string(i);
            temp.push_back(s);
        }

        sort(temp.begin(), temp.end());

        vector<int>ans;

        for(auto i : temp){
            int num = stoi(i);
            ans.push_back(num);
        }

        return ans;
        
    }
};