class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;

        for(int i = 0; i<words.size(); i++){
            string str = words[i];

            if(str.find(x) != string::npos){
                ans.push_back(i);
            }
        }

        return ans;
    }
};