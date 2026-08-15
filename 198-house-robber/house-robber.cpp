class Solution {
public:
    int t[101];
    int solve(int n, vector<int>& nums) {

        if(n <= 0) 
            return 0;

        if(t[n] != -1) 
            return t[n];

        int take = nums[n-1] + solve(n-2, nums);

        int not_take = solve(n-1, nums);

        return t[n] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        memset(t, -1, sizeof(t));

        return solve(n, nums);
    }
};