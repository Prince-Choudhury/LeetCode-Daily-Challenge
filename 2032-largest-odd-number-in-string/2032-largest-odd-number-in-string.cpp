class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        int index =-1;
        while(i>=0){
            int ele = num[i] -'0';
            if(ele%2 ==1)
            {
                index = i;
                break;
            }
            i--;
        }
        if(index ==-1) return "";
        num =num.substr(0,index+1);
        return num;
    }
};