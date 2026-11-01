class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxi = nums[n-1];
        int dist = maxi - nums[0];
        int count = dist;

        for(int i=0; i<n-1; i++) {
            
            int step = nums[i] + dist;
            count += step - maxi;
        }

        return count;
    }
};