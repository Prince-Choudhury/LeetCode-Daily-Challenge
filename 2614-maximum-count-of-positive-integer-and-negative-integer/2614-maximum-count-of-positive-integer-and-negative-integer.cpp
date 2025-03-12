class Solution {
public:
    int maximumCount(vector<int>& arr) {
        int posCount = 0;
        int negCount = 0;

        for(int i = 0; i<arr.size(); i++){
            if(arr[i]<0 && arr[i]!=0){
                negCount++;
            }

            else if(arr[i]>0 && arr[i]!=0){
                posCount++;
            }
        }

        return max(negCount, posCount);
    }
};