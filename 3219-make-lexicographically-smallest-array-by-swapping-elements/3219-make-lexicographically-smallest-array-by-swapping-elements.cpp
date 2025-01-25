class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);

        // Making (element, index) pair
        for(int i = 0; i<n; i++)
        {
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        int low = 0;

        // Sorting according to element
        sort(vec.begin(), vec.end());

        // Making new vector for storing and sorting indices
        vector<int> new_sorting(n);
        new_sorting [0] = vec[0].second;


        for(int i = 1; i<n; i++)
        {
            if(abs(vec[i].first-vec[i-1].first)>limit)
            {
                sort(new_sorting.begin() + low, new_sorting.begin() + i);
                low = i;
                // If difference between current and
                // previous element is greater than limit,
                // we will sort indices before it and make
                // current element new low
            }
            new_sorting [i] = vec[i].second;
        }
        sort(new_sorting.begin() + low, new_sorting.end());
        vector<int> ans(n);

        // filling in answer according to our new sorted index
        for(int i = 0; i<n; i++)
        {
            ans[new_sorting[i]] = vec[i].first;
        }

        return ans;
    }
};