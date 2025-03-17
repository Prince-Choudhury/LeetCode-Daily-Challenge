class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        set<int>st;

        for(int i = 0; i<arr.size(); i++){
            st.insert(arr[i]);
        }

        int index = 0;
        for(auto x : st){
            arr[index] = x;
            index++;
        }

        return st.size();
    }
};