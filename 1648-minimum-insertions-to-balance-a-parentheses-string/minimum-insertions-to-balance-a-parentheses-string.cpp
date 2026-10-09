class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.length();

        int open = 0, count = 0;

        for(int i=0; i<n; i++) {

            if(s[i] == '(') {
                open++;
            }
            else{

                if(i+1 < n) {

                    if(s[i+1] == ')') {

                        if(open > 0) {
                            open--;
                        }
                        else{
                            count++;
                        }
                        i += 1;
                    }
                    else{
                        if(open > 0) {
                            open--;
                            count++;
                        }
                        else{
                            count += 2;
                        }
                    }
                }
                else{
                    if(open > 0) {
                        open--;
                        count++;
                    }
                    else{
                        count += 2;
                    }
                }
            }
        }

        count += open*2;

        return count;
    }
};