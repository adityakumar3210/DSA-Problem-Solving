class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        vector<int> ans;

        int small = 0, equal = 0;

        for(int num : nums) {

            if(num < target)
                small++;
                
            else if(num == target)
                equal++;

        }

        for(int index=small; index < small + equal; index++) 
            ans.push_back(index);


        return ans;
    }
};