class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n; i++) {

            if(nums[i] < 0) 
                nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;

        int i = 0, j = n-1;

        while(i <= j) {

            if(i == j) {

                sum += nums[i] * nums[i];
            }
            else{
                long long nums1 = nums[j] * nums[j];
                long long nums2 = nums[i] * nums[i];

                sum += (nums1 - nums2);
            }
            i++, j--;
        }

        return sum;
    }
};