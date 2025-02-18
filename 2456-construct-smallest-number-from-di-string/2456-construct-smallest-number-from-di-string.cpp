class Solution {
public:
   string smallestNumber(string pattern) {
       string result;
       stack<int> stk;
        
        int n = pattern.size();
        for(int i = 0; i <= n; i++){
            // Push the current index + 1 to stack
            stk.push(i + 1);
            
            if(i == pattern.size() || pattern[i] == 'I'){
                // Pop all elements from the stack and add to result
                while(!stk.empty()){
                    result+='0' +stk.top();
                    stk.pop();
                }
            }
        }

        return result;
    }
};