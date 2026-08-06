class Solution {
public:
    int smallestNumber(int n, int t) {
        
        int ans = 100;

        for(int x=n; x<=100; x++) {

            int product = 1;
            int num     = x;

            while (num > 0) {
                product *= (num % 10);
                num /= 10;
            }
            
            if(product % t == 0) 
                return x;

        }

        return ans;
    }
};