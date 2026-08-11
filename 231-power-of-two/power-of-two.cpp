class Solution {
public:
    bool solve(double n) {

        if(n <= 0) 
            return false;

        if(n == 1.0) 
           return true;

        return solve(n/2.0);

    }
    bool isPowerOfTwo(int n) {
        
        return solve(n);
    }
};