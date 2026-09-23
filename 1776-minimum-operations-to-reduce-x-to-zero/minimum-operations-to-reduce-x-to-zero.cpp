class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total < x) return -1;
        if(total == x) return n;

        int  i = 0, sum = 0;
        int  maxi = INT_MIN;

        for(int j=0; j<n; j++) {

            sum += nums[j];

            while(sum > total - x) {
                sum -= nums[i++];

            }

            if(sum == total - x) {
                int size = j - i + 1;
                maxi = max(size, maxi);
                
            }

        }  

        return maxi == INT_MIN ? -1 : n - maxi;

    }
};