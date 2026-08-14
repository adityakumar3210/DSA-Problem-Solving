class Solution {
public:
    int lastRemaining(int n) {
        
        int head = 1;
        int remaing = n;
        bool left = true;
        int step = 1;

        while(remaing > 1) {

            if(left == true || remaing % 2 == 1) {
                head += step;
            }

            left = !left;
            remaing /= 2;
            step *= 2;
        }
        return head;

    }
};