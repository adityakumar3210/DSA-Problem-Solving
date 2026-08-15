class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        int xor_ans = 0;
        bool flag = true;

        for(int i=0; i<n; i++) {

            xor_ans ^= nums[i];

            if(nums[i] != 0) 
                flag = false;

        }

        if(flag) return 0;

        return (xor_ans == 0) ? n-1 : n;
    }
};