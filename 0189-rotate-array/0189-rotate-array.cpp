class Solution {
public:
    void rotate(vector<int>& arr, int k) {

        k = k%arr.size();
        
        if(k>=arr.size()){
            return;
        }

        vector<int>arr1(arr.size()-k);
        
        int index = k;
        int n = arr.size()-1;
        while(k!=0){
            int ele = arr[n];
            arr.pop_back();
            arr1.push_back(ele);
            k--;
            n--;
        }

        reverse(arr1.begin(), arr1.end());

        for(int i = 0; i<arr.size(); i++){
            arr1[index] = arr[i];
            index++;
        }

        arr = arr1;
    }
};