class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        
        int n = nums.size();

        int i   = 0,
            j   = 0,
            idx = 0;

        while(j < n) {

            if(nums[i] == nums[j])  {

                int count = j-i+1;
                if(count <= k) {
                    nums[idx] = nums[j];
                    j++;
                    idx++;
                }
                else{
                    j++;
                }
            }
            else{
                i = j;
                nums[idx] = nums[j];
                j++;
                idx++;
            }
        }

        return vector<int>(nums.begin(), nums.begin() + idx);
    }
};