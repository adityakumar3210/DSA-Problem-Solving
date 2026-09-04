class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = INT_MIN;


        for(int i=0; i<n; i++) {

            maxi     = max(nums[i], maxi);
            int mini = INT_MAX;

            for(int j=i; j<n; j++) {

                mini = min(nums[j], mini);
            }

            if(maxi - mini <= k) 
               return i;

        }

        return -1;
    }
};