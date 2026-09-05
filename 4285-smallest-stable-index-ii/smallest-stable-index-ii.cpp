class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> minArray(n);
        int minVal = INT_MAX;

        for(int i=n-1; i>=0; i--) {
             
            minVal = min(minVal, nums[i]);
            minArray[i] = minVal;

        }

        int maxVal = INT_MIN;

        for(int i=0; i<n; i++) {

            maxVal = max(maxVal, nums[i]);

            if(maxVal - minArray[i] <= k) 
                return i;

        }

        return -1;
    }
};