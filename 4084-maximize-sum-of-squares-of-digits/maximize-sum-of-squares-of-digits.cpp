class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string result = "";

        if(num < sum / 9) 
            return result;

        while(sum / 9) {

            result += '9';
            sum -= 9;
        }

        if(sum > 0) 
            result += to_string(sum);

        
        int reamingLen = num - result.length();

        for(int i=0; i<reamingLen; i++) {

            result += '0';
        }

        return result.length() > num ? "" : result;
    }
};