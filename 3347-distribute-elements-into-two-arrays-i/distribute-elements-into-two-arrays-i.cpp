class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> array1, array2;
        array1.push_back(nums[0]);
        array2.push_back(nums[1]);

        for(int i=2; i<n; i++) {

            int s1 = array1.size();
            int s2 = array2.size();

            if(array1[s1-1] > array2[s2-1]) {
                array1.push_back(nums[i]);
            }
            else{
                array2.push_back(nums[i]);
            }
        }

        

        for(int i=0; i<n; i++) {
            
            int s1 = array1.size();

            if(i < s1) 
               nums[i] = array1[i];
            else
               nums[i] = array2[i-s1];

        }
        return nums;
    }
};