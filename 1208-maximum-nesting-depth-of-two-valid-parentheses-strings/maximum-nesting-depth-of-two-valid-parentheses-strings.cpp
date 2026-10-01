class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int n = seq.size();

        vector<int> ans;
        int ao = 0, bo = 0;

        for(int i=0; i<n; i++) {


            if(seq[i] == '(') {

                if(ao <= bo) {
                    ao += 1;
                    ans.push_back(0);
                }
                else{
                    bo += 1;
                    ans.push_back(1);
                }
            }
            else{
                
                if(ao >= bo) {
                    ao -= 1;
                    ans.push_back(0);
                }
                else{
                    bo -= 1;
                    ans.push_back(1);
                }

              

            }
        }

        return ans;
    }
};