class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int i, int prev, vector<int>& nums) {

        if(i == n) 
           return 0;

        if(dp[i][prev+1] != -1) 
           return dp[i][prev+1];

        if(prev == -1 || nums[prev] < nums[i]) {

            return dp[i][prev+1] = max(1 + solve(i+1, i, nums), solve(i+1, prev, nums));
        }
        else{
            return dp[i][prev+1] = solve(i+1, prev, nums);
        }

    }
    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, nums);
    }
};