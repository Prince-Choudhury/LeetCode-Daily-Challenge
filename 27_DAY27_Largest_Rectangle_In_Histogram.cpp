class Solution {
public:

    vector<int>nextSmallerElement(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int>st;
        st.push(-1);

        for(int i = arr.size() - 1; i>=0; i--){
            int curr = arr[i];
            //Ans find karo curr ke liye
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }

    vector<int>prevSmallerElement(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int>st;
        st.push(-1);

        for(int i = 0; i<arr.size(); i++){
            int curr = arr[i];
            //Ans find karo curr ke liye
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;

    }   

    int largestRectangleArea(vector<int>& reheights) {

        vector<int>next = nextSmallerElement(reheights);

        //Make sure karna k next me koi bhi ans -1 na ho
        for(int i = 0; i<next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }

        vector<int> prev = prevSmallerElement(reheights);

            int maxArea = INT_MIN;

            for(int i =0; i<reheights.size(); i++){
               int length = reheights[i];
               int width = next[i] - prev[i]-1;
               int currArea = length * width;
               maxArea = max(maxArea, currArea);
            }
        return maxArea;
    }
};