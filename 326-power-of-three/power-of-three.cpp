class Solution {
public:
    bool solve(double n) {

        if(n <= 0) 
            return false;

        if(n == 1.0) 
            return true;

        return solve(n/3.0);
    }
    bool isPowerOfThree(int n) {
        
        return solve(n);
    }
};