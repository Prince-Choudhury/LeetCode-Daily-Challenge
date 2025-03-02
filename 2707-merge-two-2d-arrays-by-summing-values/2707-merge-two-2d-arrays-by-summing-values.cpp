class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        int m=n1.size(),n=n2.size();
        vector<vector<int>> ans;
        
        int i=0,j=0;
        while(i<m && j<n){
            
            if(n1[i][0] < n2[j][0]){
                ans.push_back(n1[i]);
                i++;
            }
            
            else if(n1[i][0] > n2[j][0]){
                ans.push_back(n2[j]);
                j++;    
            }
            
            else{
                vector<int> r(2);
                r[0]=n2[j][0];
                r[1]=n1[i][1]+n2[j][1];
                ans.push_back(r);
                j++;
                i++;
            }
        }
        
        if(i<m){
            while(i<m){
                ans.push_back(n1[i]);
                i++;
            }
        }
        
        if(j<n){
            while(j < n){
                ans.push_back(n2[j]);
                j++;
            }   
        }
        
        return ans;
    }
};