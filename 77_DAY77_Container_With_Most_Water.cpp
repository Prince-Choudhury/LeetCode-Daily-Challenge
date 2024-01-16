class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0;
        int j=height.size()-1;
        int area=0;
        while(i<j){
            if(height[i]<=height[j]){
                //width = j-i
                //if arr[i]<=arr[j] then length = arr[i]
                //area = max(area, length*width)
                //else length = arr[j]
                //area = max(area, length*width)
                area=max(area, height[i]*(j-i));
                i++;
            }
            else{
                area=max(area, height[j]*(j-i));
                j--;
            }
        }
    
        return area;
   
    }
};