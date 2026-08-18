class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = -1,
            maxVal = -1,
            count = 0;
            

        vector<int> array(51, 0);

        for(int num : nums) 
            array[num]++;

        if(k == 1 || k == n) {

            for(int i=0; i<n; i++) {

                if(array[nums[i]] == 1) 
                   maxi = max(maxi, nums[i]);
                
                if(array[nums[i]] > 0)
                    maxVal = max(maxVal, nums[i]);
            }
  
        }
        else{

            if(array[nums[0]] == 1) 
               maxi = max(maxi, nums[0]);

            if(array[nums[n-1]] == 1) 
               maxi = max(maxi, nums[n-1]);

           
        }

        if(k == n) return maxVal;

        return maxi;
    }
};