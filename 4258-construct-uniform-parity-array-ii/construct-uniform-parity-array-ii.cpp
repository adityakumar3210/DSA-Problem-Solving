class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();

        int smallestEven = INT_MAX;
        int smallestOdd  = INT_MAX;

        for(int num : nums1) {

            if(num % 2 == 0) {
                smallestEven = min(num, smallestEven);
            }
            else{
                smallestOdd = min(num, smallestOdd);
            }
        }

        if(smallestEven == INT_MAX || smallestOdd == INT_MAX) 
            return true;

        return smallestEven - smallestOdd >= 1;

    }
};