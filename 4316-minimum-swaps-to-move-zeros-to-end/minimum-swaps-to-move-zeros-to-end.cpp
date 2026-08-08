class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        
        int n = nums.size();
        int j = n-1;
        int step = 0;

        for(int i=0; i<n; i++) {

            while(j >= 0 && nums[j] == 0)
                j--;
            
            if(i > j) 
               break;

            if(nums[i] == 0) {

                swap(nums[i], nums[j]);
                step++;
            }
               
        }

        return step;
    }
};