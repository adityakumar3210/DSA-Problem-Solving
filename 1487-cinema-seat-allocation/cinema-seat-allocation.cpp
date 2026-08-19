class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int size = reservedSeats.size();
        int result =   0,
            rowCount = 0,
            i        = 0;
            
        sort(reservedSeats.begin(), reservedSeats.end());

        while(i < size) {

            int j = i;
            vector<int> nums(11, 0);
            int row = reservedSeats[i][0];

            while(j < size && row == reservedSeats[j][0]) {

                int seat = reservedSeats[j][1];
                nums[seat] = seat;
                j++;
            }

            if(nums[2] == 0 && nums[3] == 0 && nums[4] == 0 && nums[5] == 0) {
                result++;
                
                if(nums[6] == 0 && nums[7] == 0 && nums[8] == 0 && nums[9] == 0)
                    result++;
            }
            else if(nums[4] == 0 && nums[5] == 0 && nums[6] == 0 && nums[7] == 0) {
                result++;
            }
            else if(nums[6] == 0 && nums[7] == 0 && nums[8] == 0 && nums[9] == 0) {
                result++;
            }

            rowCount++;

            i=j;
        
        }

        if(n > rowCount)
            result += 2 * (n - rowCount);

        return result;



    }
};