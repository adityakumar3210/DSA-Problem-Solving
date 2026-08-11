class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        int sum   = nums[0];
       

        unordered_set<int> mp;

        for(int i=1; i<n; i++) {

            if(nums[i-1]+1 != nums[i]) {
                break;   
            }
            
            sum += nums[i];
                
        }

        for(int i=0; i<n; i++) 
           mp.insert(nums[i]);

       

        for(int i=sum; i<=2501; i++) {

            if(!mp.count(i)) 
                return i;
        }

        return -1;
    }
};