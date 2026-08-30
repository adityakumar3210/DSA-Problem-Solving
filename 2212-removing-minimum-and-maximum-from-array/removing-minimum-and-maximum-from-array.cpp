class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int idx1 = 0,
            idx2 = 0;

        for(int i=0; i<n; i++) {

            if(nums[i] > maxi) {
                maxi = nums[i];
                idx1 = i;
            }

            if(nums[i] < mini) {
                mini = nums[i];
                idx2 = i;
            }

        }

       if(idx1 > idx2) {
           int j = idx2;
           idx2 = idx1;
           idx1 = j;

       }
           
        int left = idx1 + 1;
        int right = n - idx2;

        int ans = INT_MAX;
        ans = min(ans, left+right);

        right = idx2 - idx1;

        ans = min(ans, left+right);

        left = n - idx2;
        right = idx2 - idx1;

        ans = min(ans, left+right);

        return ans;



    }
};