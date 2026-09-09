class Solution {
public:
    long long countCommas(long long n) {
        
        long long result = 0;
        
        if(n >= 1000000000000000) {
            long long count = (n - 1000000000000000) + 1;
            count = count * 5;
            count += ((999999999999999 - 1000000000000)+1) * 4;
            count += ((999999999999 - 1000000000) + 1) * 3;
            count += ((999999999 - 1000000) + 1) * 2;
            count += (999999 - 1000) + 1;
            result = count;
        }
       
        else if(n >= 1000000000000) {
            long long count = (n - 1000000000000) + 1;
            count = count * 4; 
            count += ((999999999999 - 1000000000) + 1) * 3;
            count += ((999999999 - 1000000) + 1) * 2;
            count += (999999 - 1000) + 1;
            result = count;

        }
        
        else if(n >= 1000000000) {
            long long count = (n - 1000000000) + 1;
            count = count * 3;
            count += ((999999999 - 1000000) + 1) * 2;
            count += (999999 - 1000) + 1;
            result = count;
        }
        
        else if(n >= 1000000) {
            long long count = (n - 1000000) + 1;
            count = count * 2;
            count += (999999 - 1000) + 1;
            result = count;
        }
        
        else if(n >= 1000) {
            long long count = (n - 1000) + 1;
            result = count;
        }
        else{
            return 0;
        }

        return result;
        
          
    }
};