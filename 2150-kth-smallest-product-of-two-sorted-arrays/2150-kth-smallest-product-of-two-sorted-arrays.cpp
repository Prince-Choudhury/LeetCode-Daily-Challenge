
class Solution {
public:
    typedef long long ll; 
    bool isPossible(vector<int>& nums1, vector<int>& nums2, ll &target, ll &k){
        int n = nums1.size();
        int m = nums2.size();
        ll count = 0;
for(int i = 0; i<n; i++){
            int low = 0;
            int high = m-1;
            if(nums1[i] > 0){
                while(low <= high){
                    int mid = low + (high-low)/2;
                    if(1LL*nums2[mid]*nums1[i] <= target){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    } 
                }

                count += low;
            }
            else if(nums1[i] < 0) {

                while(low <= high){
                    int mid = low + (high-low)/2;
                    if(1LL*nums2[mid]*nums1[i] <= target){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    } 
                }
                count += (m - high-1);
            }
            else{
                if(target >= 0){
                    count += m;
                }
            }
         if(count >= k) return true;
        }
        return false;
    }



    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        int n = nums1.size();
        int m = nums2.size();

        ll low = -1e10;
        ll high = 1e10;
        ll ans = 0;
        while(low <= high){
            ll mid = low + (high-low)/2;

            if(isPossible(nums1, nums2, mid, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};