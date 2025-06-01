class Solution {
public:

    long long distributeCandies(int n, int limit) {
        
        long long ans=0;
        
        for(int i=0;i<=limit;i++){
            
            int tar=n-i;
            
            if(tar<0){
                break;
            }
            
            if(tar==0){
                ans++;
                continue ;
            }
            
            if(tar<=limit){
                ans += (tar+1);
            }
            else if( tar>limit){
                if(tar > 2*limit){
                    continue ;
                }
                else if(tar == 2*limit){
                    ans++;
                }
                else{
                    int b = tar - limit ;
                    ans += limit - b + 1 ;
                }
                
            }
            
        }
        return ans;
    }
};