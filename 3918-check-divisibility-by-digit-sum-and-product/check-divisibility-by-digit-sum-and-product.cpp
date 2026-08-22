class Solution {
public:
    bool checkDivisibility(int n) {
        
        int num = n;
        int sum = 0;
        int pro = 1;

        while(num > 0) {

            int digit = num % 10;
            sum += digit;
            pro *= digit;

            num /= 10;
        }

        int total = sum + pro;

        return n % total == 0;
    }
};