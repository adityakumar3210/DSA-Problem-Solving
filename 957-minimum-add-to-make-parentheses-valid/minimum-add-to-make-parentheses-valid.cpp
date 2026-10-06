class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.length();

        int Count = 0, openCount = 0;


        for(char ch : s) {

            if(ch == '(') {

                openCount++;
            }
            else{
                if(openCount == 0)
                   Count++;
                else{
                    openCount--;
                }
            }
        }


        return openCount + Count;


    }
};