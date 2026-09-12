class Solution {
public:
    int n;
    int dp[2501][2501];

    int solve(int prev, int i, vector<int>& nums) {

        if(i == n) 
           return 0;
        
        if(dp[i][prev+1] != -1) 
           return dp[i][prev+1];
        
        if(prev == -1 || nums[prev] < nums[i]) { 

            return dp[i][prev+1] = max(1 + solve(i, i+1, nums), solve(prev, i+1, nums));
        }
        else{
            return dp[i][prev+1] = solve(prev, i+1, nums);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(-1, 0, nums);
    }
};